


li a7, 5
mv t0, a0  #x
ecall

li a7, 5
mv t1, a0  #y
ecall

li a0, '\n'
li a7, 11
ecall

#task1

addi t2, t0, 5
addi t3, t1, -7
sub t4, t2, t3
ecall

mv a0, t4
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall

#task2

srli t2, t0, 2
addi t3, t1, -1
slli t4, t3, 3
ecall

mv a0, t4
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall


#task3

srl t2, t0, t1
addi t3, t2, -10
ecall

mv a0, t3
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall

#task 4

sll t2, t0, t1
addi t3, t2, 10
ecall

mv a0, t3
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall

#task 5
slli t2, t0, 2
sub t3, t2, t1
addi t4, t3, 5
srli t5, t4, 1
ecall

mv a0, t5
li a7, 1 
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

#Task 7

slli t2, t0, 2
sll t2, t2, t0  #2*x*x

slli t3, t1, 1
add t3, t3, t1 #3*y
addi t4, t3, 4 #3*y+4

sub t5, t2, t3 #2 * x * x - 3 * y + 4
ecall

mv a0, t5
li a7, 1 
ecall

li a0, '\n'
li a7, 11
ecall


#TASK 8

addi t2, t0, 5
srl t3, t2, t1

addi t4, t1, -1
s














