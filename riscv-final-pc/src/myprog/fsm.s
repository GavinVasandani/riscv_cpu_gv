.text
.globl main
# registers in use: a1, a2, a3 - by lfsr, a0, ra, a5 - by this program
# a5 will be used to store the delay value
# ra is used to store the value of PC that holds the return from subroutine value
main:
    addi a5, a5, 0xA # lowest possible delay is supposed to be 11, so that the light doesn't turn off too fast in the worst case
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
    beq a5, zero, done # if no delay then jump to termination immediately
    jal ra, delay # jump to the delay subroutine and store return value in ra
delay:
    addi a5, a5, -1 # subtract 1 from delay
    bne a5, zero, delay # loop till delay hits 0
    jal ra, checkdelay # unconditional jump to termination step if you reach here
done:
    addi ra, zero, 0x0 # reset subroutine register
    addi a0, zero, 0x0 # end program by turning all the lights off
# look at f1 starting light code for reasoning behind design decisions
# suggested modifications/ questions to ask to the GTA:

