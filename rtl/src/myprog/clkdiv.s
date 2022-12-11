.text
.globl main
main:
    addi a0, zero, 0x0
    addi a6, zero, 0x0E # set clkdiv to roughly 14 cycles - should be initialized at the start of main program
    jal ra, mloop 
    addi a0, a0, 0x1 # if a0 contains 1 the tests have passed
    jal ra, end
mloop:
    addi a6, a6, -1 # decrement by one
    bne a6, zero, mloop # loop till you hit zero
    jalr x0, ra, 0 # ret instruction
end:


    