.text
.globl main
# registers in use: s2, a1, a2, a3
# a5 will be used to store the trigger value, a6 can be used for program termination - increments when returning to zero and a6 is checked at the start of zero loop
main:
    addi a0, zero, 0x0 # initialization step
lightloop:
    addi a0, zero, 0x1 # first light
    addi a0, zero, 0x3 # second light
    addi a0, zero, 0x7 # third light
    addi a0, zero, 0xF # fourth light
    addi a0, zero, 0x1F # fifth light
    addi a0, zero, 0x3F # sixth light
    addi a0, zero, 0x7F # seventh light
    addi a0, zero, 0xFF # eighth light
    beq a5, zero, main

# you need to use branch operations to make the light check trigger at the end of the loop. Trigger can be asserted mid cycle, the program should loop to the check repeatedly till it detects a trigger. This can be done by jumping to itself.
