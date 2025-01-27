li a7, 5
mv t0, a0  #x
ecall

li a7, 5
mv t1, a0  #y
ecall

li a0, '\n'
li a7, 11
ecall

#task 4

sll t2, t0, t1
li t4, 10
addi t3, t2, t4
ecall

mv a0, t3
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall