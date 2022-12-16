# Contribution:

The commit evidence could also be found in https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture
This was our old repo, one person transferred my work to this repo.
- ## Introduction:
    - This report will provide an overview of the control unit implemented in a RISC-V processor written in SystemVerilog, and discuss the design and implementation of the control unit, as well as any challenges encountered during the development process.

- ## Control Unit & Sign Extension:
    - **Main Decoder:** The mainDecoder takes the input of last 7 digit from the instruction. This is known as opcode(**op**), which specify different type of instruction. There are mainly 6 types of instruction, Load, Store, I-type, R-type, B-type and Jump type. Each of these type sends same control signals - 
    
        - **regWrite** - If activated, store current result to the register file to given location.
        -  **ImmSrc** - Specify different type of instruction where they have different immediate location.
        - **ALUSrc** - Determine whether the value feeds to ALU is from immediate or regfile.
        - **MemWrite** - If activated, write the current WriteData to Data Memory.
        - **ResultSrc** - Determine the current result is from ALU or Data Memory.
        - **Branch** - Temperary variable - is 1 if the instruction is B-type.
        - **ALUOp** - Specify types of instruction which have the same ALU feature.
        - **J** - J stands for Jump, is 01 for JAL and 10 for JALR.

        This block is in combinational logic, and each instruction was differentiated from **op** using case statement.
        ```systemverilog
        case(op)
            7'b0000011: begin           // Load
                RegWrite = 1;
                ImmSrc = 3'b000;
                ALUSrc = 1;
                MemWrite = 0;
                ResultSrc = 1;
                Branch = 0;
                ALUOp = 2'b00;
                J = 2'b00;
            end
            7'b0100011:                 //Store
                //set all signals
            7'b0110011:
                //.....

        ```

    - **ALU Decoder:** The mainDecoder provides the information of the instruction type via **ALUOp**. As shown in the diagram below, each individual instruction is determined by function 3(**funct3**) and the 5th digit of function7(**funct75**). If funct7 is not needed, it will become part of immediate - in order to use the space efficiently. There are 2 outputs from this block - 
        - **ALUControl** - 4-bits signal specifying induvidual ALU instruction.
        - **Datatype** - For Load/Store, this variable diffenciate between word/half word/byte read from/store to the memory. This is a new variable not mentioned in lecture.

    Diagram below shows the low-level overview of control unit and the relationship between mainDecoder and ALUDecoder.
    ![Control Block](../images-logbook/ControlBlock.png)

    - **Sign Extension:** To extend a 2's complement number, we made copies of the most significant bit(sign bit) the add to the front. In order to use the 32-bit instruction space efficiently, immediate signal may have positioned everywhere exept for the opcode. These information could be find from the look up table in risc-v spec. Code below shows 2 examples of extending Imm from different location.
        ```systemverilog
        always_comb 
            case(ImmSrc)
                3'b000:             //Immediate and JALR
                    ImmExt = {{20{imm[31]}}, imm[31:20]};
                
                3'b001:             //Store
                    ImmExt = {{20{imm[31]}}, imm[31:25], imm[11:7]};

        ```


- ## Pipelining
    - 4 registers is added to the top level. I was responsible for the **fetch** and **Decode** stage. The main challenge in this part was the designing process. We have introduced new signal which is not mentioned in lecture. I also need to communicate with Gavin about splitting ALU into 3 parts. This is because parts of ALU was for **Decode**, **Execute** and **Memory Read/Write** stages. There should be 1 register between each stage. My work also includes debugging after we connected all registers.

- ## Mistakes and Experience
    - **Challenges:** The main challenge encountered during the development of the control unit was the complexity of the decoding logic. The lookup table had to be found in the risc-v spec, which was a time-consuming process. Additionally, I need to understand how the whole CPU work to think about the value of control signal to output. 
    - **Mistakes:** 
        - When I was testing my top level control.sv, I realized it is combinational logic unlike other components. I must add a temporary clk signal for testing. 
        - Initially I included all instructions in one control.sv file. I found this so complicated when instructions gots more and more. So I split them to mainDecoder and ALUDecoder, as explained above.
        - In terms of logic, for subtract operation, the **funct7[5]** should be 1. However, **funct7[5]** could also be in immediate signal for add operation, which is considered as same set in ALUDecoder. This leads to error in special cases. This was solved by include **op[5]** in ALUDecoder. 
        

    










- ## Evidence 
    - control testbench - https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/70863a553780b7dad3675f2c69664da6497114f0#diff-96e7efdb42afd3960e4915a04763a9e436ab370698b0004699545a34b6d8a902
    - sign extention block - https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/500a30d53ff6527ed01c0873f0a3aa12f0674b7f
    - sign extension 2 - https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/500a30d53ff6527ed01c0873f0a3aa12f0674b7f
    - control.sv initial version - https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/b3f288b3fa7cb9ab015b3405170140dd930273e5
    - new control block - https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/2b9cae481cb5b3e2993073b5243c7051a697227e
    - pipeline registers 1 - https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/45e157ffa7bf6a00ea1d942231b296effaf3f3b0#diff-8287d3dda2092f633f3c3802f4b4bc91f80c073d77d68cfe48139f58d66a42e2
    - pipeline register 2 - https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/024b4ca999651b9f723474c070c306f8b8b3f47d
    