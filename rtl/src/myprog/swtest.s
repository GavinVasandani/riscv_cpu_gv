.text
.globl main
main:
    li a0, 0x69069069
    sw a0, 0x0(a1)
    lbu a2, 0x0(a1)
    lbu a3, 0x1(a1)
    lbu a4, 0x2(a1)
    lbu a5, 0x3(a1)
    sb a2, 0x0(a1)
    sb a3, 0x1(a1)
    sb a4, 0x2(a1)
    sb a5, 0x3(a1)
    lw s2, 0x0(a1)



    