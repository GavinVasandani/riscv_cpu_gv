.text
.globl main
main:
    addi a5, a5, 0xA 
    addi t5, t5, 0x1 
lightloop:
    addi a0, zero, 0x1 
    addi a0, zero, 0x3 
    addi a0, zero, 0x7 
    addi a0, zero, 0xF 
    addi a0, zero, 0x1F
    addi a0, zero, 0x3F 
    addi a0, zero, 0x7F 
    addi a0, zero, 0xFF 
checkdelay:
    beq a5, zero, done 
    sub a5, a5, t5 
    bne a5, zero, checkdelay
done:
    addi a5, a5, 0x1 
    addi a0, zero, 0x0 
