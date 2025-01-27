
li a7, 5
mv t0, a0  #x
ecall

li a7, 5
mv t1, a0  #y
ecall

li a0, '\n'
li a7, 11
ecall

#TASK6

#6 = 2^2 + 2^1

slli t2, t0, 2
slli t3, t0, 1
add t3, t2, t3

#3 = 2^1 + y

slli t4, t1, 1
add t5, t4, t1

#subs
sub t6, t3, t5
ecall

mv a0, t6
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall
