# Contribution:

All of the proof for contribution can be seen in commits and the respective folders on this branch. They are further documented with explanations below:

## Single Cycle CPU:

- ### PC Block & Instruction Memory:
  The relevant files for this part of the module can be found in the main branch, in the directory rtl/riscv-final-pc. This directory contains a test bench for the entire block, the program counter files and the rom file. The top level module is called  ***top_pc.sv***
  - #### **Functioning** :

    - **Counter & Mux:** The PC block is responsible for smooth progressing of the program. It consists of a counter (called a program counter) which moves up in increments depending upon outputs from a mux block. The mux block in question takes inputs depending on if the operation requires a branch/jump (where the address to jump to is specified in the instruction) or a regular operation. These two functions are handled by **alt_PC** and **inc_PC** as shown below.

      **insert image of mux block here.**

      Apart from these two functions, jumps were handled by an input from the control block called "**J**". When J was 0, there would be no jumps. With J = 1 there would be a **jal** operation, but this was easily handled by **alt_PC**. Finally if J = 2, a **jalr** operation would be executed. This is explained in further detail below.

    - **Instruction Memory:** Apart from the counter and mux block, there is also a memory block(in this particular use case we have used a ROM, but a RAM would work perfectly fine as well). Typically a RAM would be implemented in case of a Von Neumann architecture where we require dynamic access to the memory location in case it needs to be changed mid-program). The memory block currently contains 65536 (hex FFF as per the memory map) addresses, with 32 bit instruction words stored in each of these addresses. The reasoning for this decision was due to optimization of the memory to fit the memory map provided in the project speicifcation. It was decided that only 0xFFF locations would be allocated because allocating all $2^{32}$ memory address would require 4 Gigs of system memory which verilator would not be able to handle.

      **insert picture of memory block here.**

    - **PC Register:** To avoid a combinational loop, a register is added between the mux and the memory block. This is because at cycle 0, PC is required to determine PC. In case there was no PC register in between, this would latch and cause a combinational loop. The register initially contains 0, so this will not hamper the functioning of the program.

      **insert picture of PC reg here**

  - #### [**PC Register & Counter & Mux**:](../rtl/riscv-final-pc/pc_reg.sv)
    The **pcreg** module handled the creation of a register and the mux based on the picture above, it handled the mux block, as well as the pc register. The mux block depends on **PCsrc**, a control input. When **PCsrc** is high, the program counter accepts input from the branch component. The Jump instruction would also require PC to be dynamically changed according to the previous PC and the offset which is stored as an immediate as part of the instruction. This functionality is common for both the branch operation and the jump operation. The only difference being the jalr operation, which allocates PC according to a value stored in a register. JALR works like a return operation when the register to which the JAL operation was stored is accessed. It allows PC to increment after returning from a subroutine. For jalr specifically, the input to the rom should come from the alu block since the operation to be performed is  **PCsrc_inter** is responsible for checking if the instruction is a jump or not. Since J is a 2 bit input which is **2'b10** when a jalr operation is requested, the most significant bit is used to allocate the PC value which also comes as an input from the ALU. When **PCsrc_inter** is low, the program counter increments by 4 (due to byte addressing). This can be seen in the code snippet below:
    ```systemverilog
    assign PCsrc_inter = J[0] | PCsrc;

    assign alt_PC = PC + ImmOp;
    assign inc_PC = PC + 32'h4;

    always_comb begin
      if (J[1]) next_PC = jalr_PC; // //specifially for the jalr instruction
      else begin
        next_PC = PCsrc_inter ? alt_PC : inc_PC; // PCsrc is 1 during regular jump or branch operation
      end 
    end 
    ```
    The program counter ensures a one cycle delay between input PC (to calculate the increment and subsequent PC) and the output PC (which is pushed forward to the instruction memory as well as used as input PC for the next cycle). This is implemented with the code below (synchronously):
    ```systemverilog
    always_ff @(posedge clk)
    if(rst) PC <= {ADDRESS_WIDTH{1'b0}};
    else    PC <= next_PC;  
    ```
    It also contained a reset in order to allow for mid cycle resetting capabilities.

  - #### [**Instruction Memory**](../rtl/riscv-final-pc/rom.sv):
    The instruction memory module consists of a rom (rom.sv)which is loaded with instructions compiled from assembly language using the riscv assembler. The rom used for this CPU has a data width of 8 bits (since each address stores one byte - byte addressing) and an instruction width of 12 bits. This is because the memory map in the project specification demands we use at least 0xFFF or 12 bit-wide instruction addresses. Since the RISC-V ISA uses 32 bit wide instructions, 4 addresses would have to be concatenated to form one instruction.  Apart from this, the memory is allocated using a little endian representation (least significant byte is stored in the lowest of the 4 allocated addresses). This is implemented using the code below:
    ```systemverilog
    assign instr = {rom_array[PC+3], rom_array[PC+2], rom_array[PC+1], rom_array[PC]};
    ```
    Note that the assignment is asynchronous as per the specification.
    
- ### Testing and verification:
  Apart from the instruction memory block, I handled design verification and testing for the single cycle CPU. To test the CPU, I used the src folder under rtl to write code in assembly. The code was written to be a part of the F1 program but also simultaneously allow me to test the three basic instructions needed by the CPU in order to implement the F1 program. These were: XOR, Shifts, Add/Sub, Branch, JAL and JALR. A more detailed explanation as to why and where these were used in particular:


  - [**fsm.s :**](../rtl/src/myprog/fsm.s) This program would switch the lights on sequentially till all it would reach a state where all 8 light on the LED array were turned on, at which it would wait a fixed amount of time before turning all of them off.
    1. The main label would set up **a5** and **t5** with the initial values. **a5** holds the value of the delay after the final state, and **t5** holds the value 1 for subtraction during the delay loop. 
    2. **lightloop** initiated the switching on of the array of LED lights.
    3. **checkdelay** would hold the state when all the lights were on till the contents of register **a5** (the delay register) reached 0.
    The looping mechanism allowed me to check that bne was indeed working as expected. This code also proved that the add operations were working correctly.
  - [**clkdiv.s :**](../rtl/src/myprog/clkdiv.s) This program allowed me to check if the jal and the jalr function were working properly. It was useful in implementing a pause between each light sequence so that I could control how much time would pass in between each light turning on. 
    The test for this program was simple: If register a0 contained 1 at the end of execution, then both the jal and jalr operations were working fine. 
    1. In the initial loop, register **a6** is set up with the value to hold execution between each light progression. Once **a0** and **a6** are initialized, a jump is performed to the main loop.
    2. The main loop titled **mloop** would decrement the value of a6 till it reaches zero, at which point the branch check will fail. 
    3. The **jalr** operation just before the end label is equivalent to a **RET** and allows the program to return from the mloop subroutine once a6 has reached 0.


  - [**F1.s :**](../tests/f1.s) This program can be found in the "tests" folder. It is the code that executes the functionality of the F1 lights. A video is also shown in the folder, and steps to execute the code are explained in the Documentation. This program utilized the fsm and the clkdiv from the previous program in order to progress the state of the lights and allow for creation of a delay between each light respectively. The only new additions to the code were the randomizer, for which we used the lfsr explained in previous labs, a trigger register (**a7**) which would be used to determine when the light sequence is to be initiated.
    1. On start, the program would stay in the lfsr loop till a7 was fed with a value greater than zero (more details in the testbench for the code below).
    2. The lfsr loop used **&** functions in order to isolate the third bit, the fourth bit and the least significant least bits to perform the primitive polynomial function (note that the lfsr I used was 4 bit, since 7 bits would increase the delay time significantly)
   
    **insert picture of primitive polynomial here**


    3. The isolated bits would be added to register **a1** before the branch check. If the branch was successful, **a1** would be stored back in **a5** which is the delay register. Otherwise, the lfsr loop would be executed and the LED array would be turned on sequentially.
    4. **mainclkdiv** was the subroutine which would execute the clkdiv function along with the **hold** label.
    5. **checkdelay** was executed after all 8 lights were turned on. As the name suggests, it would check the value of register **a5** and decrement it till it reached 0. 
    6. **maindelay** was required so that in the worst case (if the delay was 1), the lights would not turn off immediately. **maindelay** performed the same function as mainclkdiv, except the delay between each loop in **checkdelay** would be about 0.5 seconds.
    7. When the delay counter hit 0, the program jumps to **done** which shuts off all the lights and resets the trigger manually so that the program can be executed again on asserting **vbdFlag()**.


   - [**Testbench :**](../rtl/riscv_tb.cpp)
      The testbench allows execution of the f1 program at the moment, but uncommenting the lines
    ```cpp
       if (i>400000){
          vbdPlot(int(top->a0), 0, 255);
       }
    ``` 
    and commenting out the vbdBar() function would allow for testing of the reference programs. The test for the reference programs will be mentioned in subsequent sections. 

    The testbench initializes by resetting the program count, and resetting trigger, which is an input into the register file in the ALU. Trigger always maps to register 7. 
    ```cpp
      top->trigger = vbdFlag();
      top->rst = false;
    ```
    The code above ensures that once vbdFlag() that is the rotary encoder is pressed, trigger goes high and 1 is stored in the register **a7**. From the [f1](../tests/f1.s) code above, this register breaks the lfsr loop and initiates the lights loop, which is implemented with the code below:
    ```cpp
      vbdBar(top->a0 & 0xFF);
    ```
    It is essential that the vbuddy is in one shot mode, because otherwise trigger would stay high till it is de-asserted. The code below ensures this:
    ```cpp
      vbdSetMode(1);
    ```

---
## Reflection and possible improvements:
- In the fsm program, it is possible to save register t5 from being used at all by instead replacing the decrement with: 
    ```asm
    addi a5, a5, -1
   ```
  This is a minor change, as it would not affect the functioning of the program except for a microscopic delay due to loading of the register file with 1. Where this could be problematic, was in case of a bigger program, if more registers were required in order to facilitate more variables, or if the given subroutine was run enough times to cause a substantial delay.
- Also in the fsm program, the effect of switching the lights on could be accomplished by using an lsl operation, along with an increment at each stage.

---
## Relevant commits not mentioned here:
