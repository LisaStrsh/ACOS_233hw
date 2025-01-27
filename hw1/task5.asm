
li a7, 5
mv t0, a0  #x
ecall

li a7, 5
mv t1, a0  #y
ecall

li a0, '\n'
li a7, 11
ecall

#task 5

li t2, 2
sll t2, t0, t2
sub t3, t2, t1
addi t4, t3, 5
srai t5, t4, 1
ecall

mv a0, t5
li a7, 1 
ecall
