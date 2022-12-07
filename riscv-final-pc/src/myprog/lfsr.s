main:
    addi a5, zero, 0x0 # s2 is used by delay in subsequent modules
    addi a1, zero, 0x1 # a1 is the lfsr, we start with 1
mloop:
    addi a5, a1, 0x0 # load output with answer
    addi t1, a5, 0x0 # initialize dummy register for operation
    slli a1, t1, 0x1A # shift left 26 times to get rid of the 7th bit
    srli a1, a1, 0x19 # a1 contains the first six bits of the number (shift right 25 times) as bits 1, 2 and 3 instead of 0, 1, 2 (x3x2x10)
    slli a2, t1, 0x1c # shift left 28 times to get rid of the 4th bit
    srli a2, a2, 0x1f # a2 contains the 4th bit of the number (shift right 31 times)
    srli a3, t1, 0x6 # a3 contains the 7th bit of the number
    xor t2, a3, a2 # randomization step (n)
    add a1, a1, t2 # reconstruct the number : x3x2x1n where n is the new bit from the randomization
    beq a7, zero, mloop # loop till trigger is asserted - trigger is stored in a7 or x17
    