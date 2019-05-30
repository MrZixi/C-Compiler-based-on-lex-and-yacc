# -*- coding=utf-8 -*-
import pygraphviz

class Mynode:
    def __init__(self,_depth,_id,_label,_flag):
        self.depth = _depth
        self.id = _id
        self.label = _label
        self.flag = _flag


def main():
    node_list = []
    node_num = 0
    deep = 0

    g=pygraphviz.AGraph(
        encoding='UTF-8',   # 为了可以显示中文
        rankdir='UD',       # 从上到下
        directed=True       # 有向图
    )

    f = open('./PT.txt','r')
    while 1:
        line = f.readline()
        flag = False
        depth = 0
        for c in line:
            if c == '+':
                depth += 1
	    elif c == ' ':
		continue
            else:
                break
        if depth >= 2 * len(line):
            break
        for word in line[depth * 2:].strip().split():
            node_list.append(Mynode(depth,node_num,word,flag))
            node_num += 1
            flag = True
            depth += 1

        deep = max(deep,depth-1)

        if not line:
            break

    parent = [0] * (deep + 1)

    g.add_node(str(node_list[0].id),label = node_list[0].label)
    parent[0] = 0

    node_current = 1
    while node_current<len(node_list):
        parent[node_list[node_current].depth] = node_list[node_current].id
        if(node_list[node_current].flag):
            shape_tmp = 'box'
        else:
            shape_tmp = 'ellipse'
        
        if node_current+1 == len(node_list) or (node_current+1 < len(node_list) and node_list[node_current+1].depth <= node_list[node_current].depth):
            color_tmp = 'red'
        else:
            color_tmp = 'black'

        g.add_node(str(node_list[node_current].id),label = node_list[node_current].label,shape = shape_tmp,color = color_tmp)
        g.add_edge(str(parent[node_list[node_current].depth-1]), str(node_list[node_current].id))
        node_current += 1

    g.layout('dot')
    g.draw('PT.jpg', format='jpg')

if __name__ == '__main__':
    main()
