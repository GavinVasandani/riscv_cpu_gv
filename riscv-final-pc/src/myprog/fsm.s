.text
.globl main
# registers in use: s2, a1, a2, a3
# a5 will be used to store the delay value
# a6 will be used to check if the program has already run once. If so, it will stop running
# s4 is used to store the value of PC that initiates the checkdelay loop
main:
    addi a0, zero, 0x0 # initialization step
    addi s4, zero, 0x0 
    bne a6, zero, main
; setdelay:
;     addi a5, zero, 0x5 # set delay to 5 for testing purposes. REMOVE THIS FROM FINAL CODE. DELAY COMES FROM LFSR
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
    bne a5, zero, delay # branch to delay if the delay register hasn't hit 0 yet.
    addi a6, zero, 0x1 # terminate program - since you only reach here if the delay has reached 0
    beq a5, zero, main # this jumps to the beginning and ensures the program terminates after resetting the lights to 0.
delay:
    addi a5, a5, -1 # subtract 1 from delay
    jal s4, checkdelay # call the subroutine that checks the delay register

# look at f1 starting light code for reasoning behind design decisions
# suggested modifications/ questions to ask to the GTA:

