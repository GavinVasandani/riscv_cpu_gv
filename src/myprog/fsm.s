.text
.globl main
# registers in use: a1, a2, a3 - by lfsr, a0, ra, a5 - by this program
# a5 will be used to store the delay value
# ra is used to store the value of PC that holds the return from subroutine value
main:
    addi a5, a5, 0xA # lowest possible delay is supposed to be 11, so that the light doesn't turn off too fast in the worst case
    addi t5, t5, 0x1 # for subtraction
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
    beq a5, zero, done # if no delay then jump to termination immediately or you have reached the end of the program
    sub a5, a5, t5 # subtract 1 from delay
    bne a5, zero, checkdelay # loop till delay hits 0
done:
    addi a5, a5, 0x1 # to make sure no errors in the lfsr loop
    addi a0, zero, 0x0 # end program by turning all the lights off
