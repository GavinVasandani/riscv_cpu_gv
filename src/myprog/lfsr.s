main:
    addi a5, zero, 0x0
    addi a1, zero, 0x1
mloop:
    addi a5, a1, 0x0
    addi a0, a5, 0x0
    addi t1, a5, 0x0
    andi a1, t1, 0x7
    slli a1, a1, 0x1
    andi a2, t1, 0x4
    srli a2, a2, 0x2
    andi a3, t1, 0x8
    srli a3, a3, 0x3
    xor t2, a2, a3
    add a1, a1, t2
    beq a7, zero, mloop
end:
    addi a0, zero, 0x69
    