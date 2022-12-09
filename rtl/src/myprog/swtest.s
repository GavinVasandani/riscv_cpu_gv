.text
.globl main
main:
    addi a1, a1, 0x4
    addi a0, a0, 0x69
    sw a0, 0x0(a1)
    lw a2, 0x0(a1)
    