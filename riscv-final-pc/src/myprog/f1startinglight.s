# the idea is to have the lfsr loop the moment the program starts.
# when trigger is asserted, the loop is terminated (check that trigger is zero at the start of this loop for this functionality).
# if trigger is asserted, store the output from the last iteration of the lfsr loop into a register.
# calculate the delay from the lfsr register and store it in a register
# feed 24 into a free register for the clktick module
# now the program starts, check that a0 (the output to the light) is not 0xFF
# if it is 0xFF, reed the delay from the delay register and wait the correct amount of clock cycles before going back to 0xFF
# now wait 24 cycles for the clktick register to become 0
# if it does become 0, initiate a subroutine that sets it beack to 24 and increments a0 accordingly
