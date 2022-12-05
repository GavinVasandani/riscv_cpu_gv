.text
.globl main
main:
    addi a0, zero, 0x0 # a0 is used for output
    addi a1, zero, 0x7 # a1 is the lfsr, we start with 1
mloop:
    addi a0, a1, 0x0 # load output with answer
    addi t1, a0, 0x0 # initialize dummy register for operation
    slli a1, t1, 0x1d # shift left 29 times to get rid of the 4th bit
    srli a1, a1, 0x1c # a1 contains the first three bits of the number (shift right 28 times) as bits 1, 2 and 3 instead of 0, 1, 2 (x3x2x10)
    slli a2, t1, 0x1d # shift left 29 times to get rid of the 4th bit
    srli a2, a2, 0x1f # a2 contains the 3rd bit of the number (shift right 32 times)
    srli a3, t1, 0x3 # a3 contains the 4th bit of the number
    xor t2, a3, a2 # randomization step (n)
    add a1, a1, t2 # reconstruct the number : x3x2x1n where n is the new bit from the randomization
    jal zero, mloop # continue forever - this is temporary

