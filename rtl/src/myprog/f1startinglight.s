.text
.globl main
main:
    addi a5, zero, 0x0 # a5 is used by delay in subsequent modules
    addi a1, zero, 0x1 # a1 is the lfsr, we start with 1
    addi t5, zero, 0x1 # for subtraction (sub reg -1 operation)
lfsrloop:
    addi a5, a1, 0x0
    addi t1, a5, 0x0
    andi a1, t1, 0x7
    slli a1, a1, 0x1
    andi a2, t1, 0x4
    srli a2, a2, 0x2
    andi a3, t1, 0x8
    srli a3, a3, 0x3
    xor t2, a2, a3
    add a1, a1, t2
    beq a7, zero, lfsrloop # loop till trigger is asserted - trigger is stored in a7
lightloop:
    addi a0, zero, 0x1 # first light
    jal ra, mainclkdiv
    addi a0, zero, 0x3 # second light
    jal ra, mainclkdiv
    addi a0, zero, 0x7 # third light
    jal ra, mainclkdiv
    addi a0, zero, 0xF # fourth light
    jal ra, mainclkdiv
    addi a0, zero, 0x1F # fifth light
    jal ra, mainclkdiv
    addi a0, zero, 0x3F # sixth light
    jal ra, mainclkdiv
    addi a0, zero, 0x7F # seventh light
    jal ra, mainclkdiv
    addi a0, zero, 0xFF # eighth light
checkdelay:
    beq a5, zero, done # if no delay then jump to termination immediately or you have reached the end of the program
    jal ra, maindelay
    sub a5, a5, t5 # subtract 1 from delay
    bne a5, zero, checkdelay # loop till delay hits 0
    jal ra, done # to escape mainclkdiv loop below and finish execution unconditionally - can also use J operation
maindelay:
    addi a6, zero, 0x3 # set clkdiv to roughly 3 cycles - for FF lights state
    jal zero, hold # unconditional jump to count which creates about a 0.5 second delay for each value in a6 register
mainclkdiv:
    addi a6, zero, 0x20 # set clkdiv to roughly 14 cycles - for state in between each light
hold:
    sub a6, a6, t5 # decrement by one
    bne a6, zero, hold # loop till you hit zero
    jalr zero, ra, 0x0 # ret instruction, return to either check delay or lightloop after creating one second delay
done:
    addi a7, zero, 0x0 # reset trigger at the start of the program
    addi a0, zero, 0x0 # end program by turning all the lights off
    beq zero, zero, main # reset program by going back to main

