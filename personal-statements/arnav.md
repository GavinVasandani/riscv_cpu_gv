# Contribution:

All of the proof for contribution can be seen in commits and the respective folders on this branch. They are further documented with explanations below:

- ## PC Block & Instruction Memory:
  - ### Functioning:

    - **Counter & Mux:** The PC block is responsible for smooth progressing of the program. It consists of a counter (called a program counter) which moves up in increments depending upon outputs from a mux block. The mux block in question takes inputs depending on if the operation requires a branch/jump (where the address to jump to is specified in the instruction) or a regular operation. These two functions are handled by **branch_PC** and **inc_PC** as shown below.

      **insert image of mux block here.**

    - **Instruction Memory:** Apart from the counter and mux block, there is also a memory (in this particular use case we have used a ROM, but a RAM would work perfectly fine as well. Typically a RAM would be implemented in case of a Von Neumann architecture where we require dynamic access to the memory location in case it needs to be changed mid-program). The memory block currently contains 256 addresses, with 32 bit instruction words stored in each of these addresses. The reasoning for this decision will be made clear in subsequent sections.

      **insert picture of memory block here.**

    - **PC Register:** To avoid a combinational loop, a register is added between the mux and the memory block. This is because at cycle 0, PC is required to determine PC. In case there was no PC register in between, this would latch and cause a combinational loop. The register initially contains 0, so this will not hamper the functioning of the program.

      **insert picture of PC reg here**

  - ### PC Register & Counter & Mux:
    The **pcreg** module handled the creation of a register and the mux based on the picture above, it handled the mux block, as well as the pc register. The mux block depends on **PCsrc**, a control input. When **PCsrc** is high, the program counter accepts input from the branch component. The Jump instruction would also require PC to be dynamically changed according to the previous PC and the offset which is stored as an immediate as part of the instruction. This functionality is common for both the branch operation and the jump operation. The only difference being the jalr operation, which allocates PC according to a value stored in a register. JALR works like a return operation when the register to which the JAL operation was stored is accessed. It allows PC to increment after returning from a subroutine. **PCsrc_inter** is responsible for checking if the instruction is a jump or not. Since J is a 2 bit input which is **2'b10** when a jalr operation is requested, the most significant bit is used to allocate the PC value which also comes as an input from the ALU. When **PCsrc_inter** is low, the program counter increments by 4 (due to byte addressing). This can be seen in the code snippet below:
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

  - ### Instruction Memory:
    The instruction memory module consists of a rom which is loaded with instructions compiled from assembly language using the riscv assembler. The rom used for this CPU has a data width of 8 bits (since each address stores one byte - byte addressing) and an instruction width of 12 bits. This is because the memory map in the project specification demands we use at least 0xFFF or 12 bit-wide instruction addresses. Since the RISC-V ISA uses 32 bit wide instructions, 4 addresses would have to be concatenated to form one instruction.  Apart from this, the memory is allocated using a little endian representation (least significabt byte is stored in the lowest of the 4 allocated addresses). This is implemented using the code below:
    ```systemverilog
    assign instr = {rom_array[PC+3], rom_array[PC+2], rom_array[PC+1], rom_array[PC]};
    ```
    Note that the assignment is asynchronous as per the specification.

---