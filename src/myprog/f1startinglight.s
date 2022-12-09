# the idea is to have the lfsr loop the moment the program starts.
# when trigger is asserted, the loop is terminated (check that trigger is zero at the start of this loop for this functionality).
# if trigger is asserted, store the output from the last iteration of the lfsr loop into a register.
# calculate the delay from the lfsr register and store it in a register
# feed 24 into a free register for the clktick module
# now the program starts, check that a0 (the output to the light) is not 0xFF
# if it is 0xFF, reed the delay from the delay register and wait the correct amount of clock cycles before going back to 0xFF
# now wait 24 cycles for the clktick register to become 0
# if it does become 0, initiate a subroutine that sets it beack to 24 and increments a0 accordingly
# a7 contains trigger
# a5 contains delay
# a6 contains N for clkdiv
# s2, a1, a2, a3, a5 - by lfsr
# a0, ra, a5 - by state machine
# a6 - by clkdiv
# use a subroutine in between each light to create a delay, this subroutine should be the clkdiv module
# TODO: more efficient way to implement lfsr loop and light loop
.text
.globl main
main:
    addi a5, zero, 0x0 # a5 is used by delay in subsequent modules
    addi a1, zero, 0x1 # a1 is the lfsr, we start with 1
    addi t5, t5, 0x1 # for subtraction (sub reg -1 operation)
lfsrloop:
    addi a5, a1, 0x0 # load output with answer
    addi t1, a5, 0x0 # initialize dummy register for operation
    slli a1, t1, 0x1A # shift left 26 times to get rid of the 7th bit
    srli a1, a1, 0x19 # a1 contains the first six bits of the number (shift right 25 times) as bits 1, 2 3, 4, 5, 6 instead of 0, 1, 2, 3, 4, 5 (x6x5x4x3x2x10)
    slli a2, t1, 0x1c # shift left 28 times to get rid of the 4th bit
    srli a2, a2, 0x1f # a2 contains the 4th bit of the number (shift right 31 times)
    srli a3, t1, 0x6 # a3 contains the 7th bit of the number
    xor t2, a3, a2 # randomization step (n)
    add a1, a1, t2 # reconstruct the number : x6x5x4x3x2x1n where n is the new bit from the randomization
    beq a7, zero, lfsrloop # loop till trigger is asserted - trigger is stored in a7
# mainfsm:
    # addi a5, a5, 0xA # lowest possible delay is supposed to be 11, so that the light doesn't turn off too fast in the worst case
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
    jal ra, mainclkdiv
    sub a5, a5, t5 # subtract 1 from delay
    bne a5, zero, checkdelay # loop till delay hits 0
mainclkdiv:
    addi a6, zero, 0x0E # set clkdiv to roughly 14 cycles
clkdiv:
    sub a6, a6, t5 # decrement by one
    bne a6, zero, clkdiv # loop till you hit zero
    jalr zero, ra, 0 # ret instruction, return to either check delay or lightloop after creating one second delay
done:
    addi a7, a7, 0x0  # to make sure that trigger is reset and there are no bugs.
    addi a0, zero, 0x0 # end program by turning all the lights off
    beq a0, zero, main # reset program by going back to main

