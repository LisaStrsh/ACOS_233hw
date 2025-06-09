.section .text
.globl _start
_start:
    call mess 

    li a7, 10 
    ecall
