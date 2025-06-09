.section .data
msg:
    .asciz "Ku Ku Hello Hello!\n"

.section .text
.globl mess

mess:
    la a0, msg    
    li a7, 1        
    ecall
    ret
