# Contribution:

- ## Introduction:
    - This lab report will provide an overview of the control unit implemented in a RISC-V processor written in SystemVerilog. This report will discuss the design and implementation of the control unit, as well as any challenges encountered during the development process.

- ## Control Unit & Sign Extension:
    - **Main Decoder:** The mainDecoder takes the input of last 7 digit from the instruction. This is known as opcode(**op**), which specify different type of instruction. There are mainly 6 types of instruction -- Load, Store, I-type, R-type, B-type and Jump type. Each of these type sends same control signals like **regWrite** and **ImmSrc**. One thing to note here is that JAL and JALR instruction are different in terms of the opcode and function. So it is good to write them seperately.


    - **ALU Decoder:** The mainDecoder provides the information of the instruction type (**ALUOp**).  Each individual instruction is determined by function 3(**funct3**) and the 5th digit of function7(**funct75**). ALUDecoder takes in ALUOp as well as **funct3** and **funct75**. This gives the **ALUControl**, which tells what ALU needs to do. I discussed with Gavin who is doing ALU, and we decided to add a new variable **dataType** that specify whether to load word/half word/byte.


    - **Sign Extension:** To extend a 2's complement number, we made copies of the sign bit the add to the front. In order to use the 32-bit instruction space efficiently, immediate signal may have appear everywhere exept for the opcode. These information could be find from the look up table in risc-v spec.

    - ![Alt text](images-logbook/IMG_6F290C27BD9D-1.jpeg?raw=true "Title")

- ## Pipelining
    - 4 registers is added to the top level. The main challenge in this part was the designing process. We have introduced new signal which is not mentioned in lecture. I also need to communicate with Gavin about splitting ALU into 3 parts. This is because parts of ALU was for **Decode**, **Execute** and **Memory Read/Write** stages. There should be 1 register between each stage.

- ## Challenges
    - The main challenge encountered during the development of the control unit was the complexity of the decoding logic. The lookup table had to be found in the risc-v spec, which was a time-consuming process. Additionally, I need to understand how the whole CPU work in order to think about what control signal to output. 

