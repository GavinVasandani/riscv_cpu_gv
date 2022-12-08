.text
.globl main
main:
    addi a6, zero, 0x0E # set clkdiv to roughly 14 cycles - should be initialized at the start of main program
mloop:
    addi a6, a6, -1 # decrement by one
    bne a6, zero, mloop # loop till you hit zero
    