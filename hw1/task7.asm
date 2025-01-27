li a7, 5
ecall
mv t0, a0  #x


li a7, 5
ecall
mv t1, a0  #y


li a0, '\n'
li a7, 11
ecall

#Task 7

li t2, 2
mul t2, t2, t0
mul t2, t2, t0  #2*x*x

li t3, 3
mul t3, t3, t1

sub t5, t2, t3 #2 * x * x - 3 * y + 4
ecall

li t6, 4
add t6, t5, t6

mv a0, t6
li a7, 1 
ecall
