.data
_prompt: .asciiz "Hello"
_ret: .asciiz "\n"
.globl main
.text
xx:
	addi $sp,$sp,-4
	add $t4,a0,a1
	lw s0,0($sp)
	move $s0,$t4
	li $t5,1
	addi $sp,$sp,4
	move $v0,$t5
	jr $ra
fact:
	addi $sp,$sp,-4
	li $t6,1
	bne a0,$t6,label0
	j label1
label0:
	addi $sp,$sp,4
	move $v0,a0
	jr $ra
	j label2
label1:
	li $t8,1
	sub $t9,a0,$t8
	move $t0,a0
	move $a0,$t9
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $ra,16($sp)
	jal fact
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $a2,8($sp)
	lw $a3,12($sp)
	lw $ra,16($sp)
	addi $sp,$sp,20
	move $t4 $v0
	mul $t5,a0,$t4
	lw s1,0($sp)
	move $s1,$t5
	addi $sp,$sp,4
	move $v0,$s1
	jr $ra
label2:
main:
	addi $sp,$sp,-16
	li $t6,10
	lw s2,0($sp)
	move $s2,$t6
	li $t7,1
	lw s3,4($sp)
	move $s3,$t7
label3:
	slt $t8,$s3,$s2
	blt $s3,$s2,label4
	j label5
label4:
	li $t9,3
	lw s4,8($sp)
	move $s4,$t9
	li $t4,1
	slt $t5,$t4,$s4
	bgt $s4,$t4,label6
	j label7
label6:
	move $t0,a0
	move $a0,$s4
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $ra,16($sp)
	jal fact
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $a2,8($sp)
	lw $a3,12($sp)
	lw $ra,16($sp)
	addi $sp,$sp,20
	move $t6 $v0
	lw s5,12($sp)
	move $s5,$t6
	j label8
label7:
	li $t7,1
	move $s5,$t7
label8:
	li $t8,1
	lw s6,4($sp)
	move $t9,$s6
	add $s6,$s6,$t8
	j label3
label5:
	li $t4,0
	addi $sp,$sp,16
	move $v0,$t4
	jr $ra
