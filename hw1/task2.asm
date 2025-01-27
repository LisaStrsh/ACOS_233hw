li a7, 5
mv t0, a0  #x
ecall

li a7, 5
mv t1, a0  #y
ecall

li a0, '\n'
li a7, 11
ecall

#task
srli t2, t0, 2

li t5, 1
sub t3, t1, t5

slli t4, t3, 3
ecall

mv a0, t4
li a7, 1 
ecall

