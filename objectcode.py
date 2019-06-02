import os
import re

t_regs = ['t4', 't5', 't6', 't7', 't8', 't9']
s_regs = ['s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 's8']
a_regs = ['a0', 'a1', 'a2', 'a3']

table = {}
reg_ok = {}

temps = []
vars = []

paravars = dict()

functions = dict()
function = dict()

cur_t_reg = 0
cur_s_reg = 0
cur_a_reg = 0
cur_func = ''


def Load_Temp(Inter):
    global temps
    _temps = []
    temp_re = '(temp\d+)'
    for line in Inter:
        temp = re.findall(temp_re, ''.join(line))
        # print(temp)
        _temps += temp
    temps = list(set(_temps))
    temps.sort(key=_temps.index)


def Load_Var(Inter):
    global vars
    _temps = []
    temp_re = '(var\d+)'
    for line in Inter:
        temp = re.findall(temp_re, ''.join(line))
        # print(temp)
        _temps += temp
    # print(_temps)
    vars = list(set(_temps))
    vars.sort(key=_temps.index)
    # vars = _temps


def Load_Func(Inter):
    global functions
    for line in Inter:
        if(line[0] == 'define'):
            functions[line[2]] = dict()


def Func_Var(Inter):
    global functions
    global function
    global paravars
    cur_reg = 'a0'
    offset = 0
    cur_func = ''
    local_vars = []
    for value in vars:
        local_vars.append(value)
    for line in Inter:
        if(line[0] == 'define'):
            cur_func = line[2]
            offset = 0
            cur_reg = 'a0'
        if(line[0] in local_vars):
            local_vars.remove(line[0])
            functions[cur_func][line[0]] = offset
            function[cur_func] = offset + 4
            offset += 4
        if(line[0] == 'LOAD_PARAM'):
            if(cur_reg != 'error'):
                paravars[line[1]] = cur_reg
            if(cur_reg == 'a0'):
                cur_reg = 'a1'
            elif(cur_reg == 'a1'):
                cur_reg = 'a2'
            elif(cur_reg == 'a2'):
                cur_reg = 'a3'
            elif(cur_reg == 'a4'):
                cur_reg = 'error'


def Load_Inter(filename):
    lines = []
    for line in open(filename, 'r', encoding='utf-8'):
        line = line.replace('\r', '').replace('\n', '').replace(
            '%', '').replace('@', '').replace(':=', '=')
        line = re.sub('\\(.*\\)', '', line)
        if line == '':
            continue
        lines.append(line.split(' '))
    return lines


def get_r_t(string):
    global cur_t_reg
    try:
        temps.remove(string)
    except:
        pass
    if string in table:
        return '$' + table[string]
    else:
        if cur_t_reg >= 6:
            delitem(t_regs[cur_t_reg % 6])
        table[string] = t_regs[cur_t_reg % 6]
        cur_t_reg = cur_t_reg + 1
        return '$' + table[string]


def delitem(_value):
    global table
    _table = dict()
    for key, value in table.items():
        _table[key] = value

    for key, value in _table.items():
        if value == _value:
            del table[key]


def get_r_s(string):
    global cur_s_reg
    if string in table:
        return '$' + table[string]
    else:
        if cur_s_reg >= 9:
            #cur_s_reg = 0
            delitem(s_regs[cur_s_reg % 9])
        table[string] = s_regs[cur_s_reg % 9]
        cur_s_reg = cur_s_reg + 1
        return '\tlw %s,%d($sp)\n' % (table[string], functions[cur_func][string])


def translate(line):
    global cur_func
    global cur_a_reg
    pre_load = ''
    para1 = ''
    para2 = ''
    para3 = ''

    # pre-lw all var which is dirty
    for item in line:
        if item in vars and item not in table and item not in paravars:
            pre_load += get_r_s(item)

    if line[0] == 'LABEL':
        return line[1] + ':'
    if line[1] == '=':
        if len(line) == 3:
            if line[0] in vars:
                if line[2][0] == '#':
                    return pre_load + '\tli %s,%s' % (get_r_s(line[0]), line[2].replace('#', ''))
                else:
                    return pre_load + '\tmove %s,%s' % (get_r_s(line[0]), get_r_t(line[2]))
            else:
                if(line[2][0] == '#'):
                    return pre_load + '\tli %s,%s' % (get_r_t(line[0]), line[2].replace('#', ''))
                else:
                    return pre_load + '\tmove %s,%s' % (get_r_t(line[0]), get_r_t(line[2]))
        if len(line) == 5:
            if line[0] in paravars:
                para1 = paravars[line[0]]
            elif line[0] in vars:
                para1 = get_r_s(line[0])
            else:
                para1 = get_r_t(line[0])
            if line[2] in paravars:
                para2 = paravars[line[2]]
            elif line[2] in vars:
                para2 = get_r_s(line[2])
            else:
                para2 = get_r_t(line[2])
            if line[-1] in paravars:
                para3 = paravars[line[-1]]
            elif line[-1] in vars:
                para3 = get_r_s(line[-1])
            else:
                para3 = get_r_t(line[-1])

            if line[3] == '+':
                return pre_load + '\tadd %s,%s,%s' % (para1, para2, para3)
            elif line[3] == '-':
                return pre_load + '\tsub %s,%s,%s' % (para1, para2, para3)
            elif line[3] == '*':
                return pre_load + '\tmul %s,%s,%s' % (para1, para2, para3)
            elif line[3] == '/':
                return pre_load + '\tdiv %s,%s\n\tmfhi %s' % (para2, para3, para1)
            elif line[3] == '<':
                return pre_load + '\tslt %s,%s,%s' % (para1, para2, para3)
            elif line[3] == '>':
                return pre_load + '\tslt %s,%s,%s' % (para1, para3, para2)
        if line[2] == 'CALL':
            # clear $s&$t
            table.clear()
            cur_a_reg = 0
            return pre_load + '\taddi $sp,$sp,-20\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $t2,8($sp)\n\tsw $t3,12($sp)\n\tsw $ra,16($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $a2,8($sp)\n\tlw $a3,12($sp)\n\tlw $ra,16($sp)\n\taddi $sp,$sp,20\n\tmove %s $v0' % (line[-1], get_r_t(line[0]))
    if line[0] == 'GOTO':
        return '\tj %s' % line[1]
    if line[0] == 'ret':
        if cur_func in function:
            pre_load += '\taddi $sp,$sp,%d\n' % function[cur_func]
        if line[2] in paravars:
            return pre_load + '\tmove $v0,%s\n\tjr $ra' % paravars[line[2]]
        elif line[2] in vars:
            return pre_load + '\tmove $v0,%s\n\tjr $ra' % get_r_s(line[2])
        else:
            return pre_load + '\tmove $v0,%s\n\tjr $ra' % get_r_t(line[2])
    if line[0] == 'IF':
        if line[1] in paravars:
            para1 = paravars[line[1]]
        elif line[1] in vars:
            para1 = get_r_s(line[1])
        else:
            para1 = get_r_t(line[1])
        if line[3] in paravars:
            para2 = paravars[line[3]]
        elif line[3] in vars:
            para2 = get_r_s(line[3])
        else:
            para2 = get_r_t(line[3])
        if line[2] == 'EQ_OP':
            return pre_load + '\tbeq %s,%s,%s' % (para1, para2, line[-1])
        elif line[2] == 'NE_OP':
            return pre_load + '\tbne %s,%s,%s' % (para1, para2, line[-1])
        elif line[2] == '>':
            return pre_load + '\tbgt %s,%s,%s' % (para1, para2, line[-1])
        elif line[2] == '<':
            return pre_load + '\tblt %s,%s,%s' % (para1, para2, line[-1])
        elif line[2] == 'GE_OP':
            return pre_load + '\tbge %s,%s,%s' % (para1, para2, line[-1])
        elif line[2] == 'LE_OP':
            return pre_load + '\tble %s,%s,%s' % (para1, para2, line[-1])
    if line[0] == 'define':
        cur_func = line[2]
        return line[2] + ':\n\taddi $sp,$sp,-%d' % function[cur_func]
    if line[0] == 'LOAD_PARAM':
        pass
    if line[0] == 'PASS':
        cur_a_reg += 1
        pass_var = ''
        if line[1] in paravars:
            pass_var = paravars[line[1]]
        elif line[1] in vars:
            pass_var = get_r_s(line[1])
        else:
            pass_var = get_r_t(line[1])
        return '\tmove $t%d,%s\n\tmove $%s,%s' % (cur_a_reg-1, a_regs[cur_a_reg-1], a_regs[cur_a_reg-1],pass_var)
    return ''


def parser():
    for reg in t_regs:
        reg_ok[reg] = 1  # 初始化，所有寄存器都可用
    Inter = Load_Inter('IR.txt')  # 读取中间代码
    Load_Temp(Inter)
    Load_Var(Inter)
    Load_Func(Inter)
    Func_Var(Inter)

    print(Inter)
    print(temps)
    print(vars)
    print(functions)
    print(function)
    print(paravars)
    print(type(functions['main']['var6']))
    print(cur_func)

    Obj = []

    for line in Inter:
        obj_line = translate(line)
        if obj_line == '':
            continue
        Obj.append(obj_line)
    
    f = open('mips.asm','w')
    template = '''.data
_prompt: .asciiz "Hello"
_ret: .asciiz "\\n"
.globl main
.text
'''
    f.write(template)
    for line in Obj:
        f.write(line+'\n')
    f.close()


parser()
