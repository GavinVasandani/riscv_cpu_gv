.text
.globl main
# registers in use: s2, a1, a2, a3
# a5 will be used to store the delay value
# a6 will be used to check if the program has already run once. If so, it will stop running
# ra is used to store the value of PC that holds the return from subroutine value
main:
    addi a0, zero, 0x0 # initialization step
    addi ra, zero, 0x0 # reset subroutine register
    bne a6, zero, main
# setdelay:
#    addi a5, zero, 0x5 # set delay to 5 for testing purposes. REMOVE THIS FROM FINAL CODE. DELAY COMES FROM LFSR
lightloop:
    addi a0, zero, 0x1 # first light
    addi a0, zero, 0x3 # second light
    addi a0, zero, 0x7 # third light
    addi a0, zero, 0xF # fourth light
    addi a0, zero, 0x1F # fifth light
    addi a0, zero, 0x3F # sixth light
    addi a0, zero, 0x7F # seventh light
    addi a0, zero, 0xFF # eighth light
checkdelay:
    jal ra, delay # jump to the delay subroutine and store return value in ra
    addi a6, zero, 0x1 # terminate program - since you only reach here if the delay has reached 0
    beq a5, zero, main # this jumps to the beginning and ensures the program terminates after resetting the lights to 0.
delay:
    addi a5, a5, -1 # subtract 1 from delay
    bne a5, zero, delay # loop till delay hits 0
    jalr x0, x1, 0 # return from subroutine - equivalent to the ret instruction - initiates program termination

# look at f1 starting light code for reasoning behind design decisions
# suggested modifications/ questions to ask to the GTA:

