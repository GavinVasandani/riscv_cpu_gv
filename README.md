# Group 18's RISC - V CPU
##### *By: Arnav Kohli (sk1421), Gavin Vasandani (gv220), Junyi Wu, Xuhan Pan*

---
- ## Breakdown of tasks:
    - PC block, Instruction memory, Pipelining, Code for F1 light, Debuggging, Testing and Verification, Documentation : **Arnav Kohli**
    - ALU Block, Register Files, Data memory (including unit testing suites) : **Gavin Vasandani**
    - Control Block, Sign extension block, Pipelining: **Xuhan Pan**
    - Final CPU Assembly, Pipelining: **Junyi Wu**

---

|Module                              |Arnav Kohli    |Gavin Vasandani    |Junyi Wu   |Xuhan Pan  |
|:-----------------------------------|:-------------:|:-----------------:|:---------:|:---------:|
|riscv-alu/regfile.sv                |               |      :star:       |           |           |
|riscv-alu/regfileALU.sv             |               |      :star:       |           |           |
|riscv-alu/regfile_ALU_tb.cpp        |               |      :star:       |           |           |
|riscv-alu/ram.sv                    |      :o:      |      :star:       |           |           |
|riscv-alu/ram_cache.sv              |               |      :star:       |           |           |
|riscv-controlunit/control.sv        |      :o:      |                   |           |           |
|riscv-controlunit/ext.sv            |      :o:      |                   |   :o:     |           |
|riscv-controlunit/control_tb.cpp    |               |                   |           |           |
|riscv-final-pc/rom.sv               |     :star:    |                   |           |           |
|riscv-final-pc/pc_reg.sv            |     :star:    |                   |           |           |
|riscv-final-pc/pc_tb.cpp            |     :star:    |                   |           |           |
|top.sv                              |     :o:       |                   |   :star:  |           |
|riscv_tb.cpp                        |     :star:    |                   |           |           |
|pipeline register folder            |               |                   |   :star:  |           |
|pipeline stages                     |     :o:       |        :o:        |   :star:  |           |
|pipeline assembly & debugging       |     :o:       |                   |   :star:  |           |
|F1.s                                |     :star:    |                   |           |           |

:star: Principal Author

:o: Contributed

---

## Personal Statement - Gavin

1. My contributions.
2. Explanation of each component I contributed too, mention mistakes made, and what I learned (include code examples).
3. Obstacles faced in certain components (ram-cache) and how that led to special design decisions (include code examples).
4. Improvements for next time. 

I served as the principal author for the arithmetic logic unit (ALU), register file, ram or data memory and the combined ram-cache memory unit. I also built test benches for each of these components to validate that they work as expected before they’re implemented in the complete CPU. 

When creating the ALU I, first, identified all the instructions that are required to implement the Lab 4 binary counter task. These initial instructions were: bne and addi, therefore only a 1 bit ALU_ctrl signal was needed to differentiate between the 2 instructions and they were both implemented using in-built operations. The ALU had 2 output signals, ALUout which was the result of the 2 inputs after applying a certain arithmetic and eq which was assigned HIGH if the 2 ALU inputs were equal, regardless of the instruction being bne or beq. The control unit applied a signal to invert eq depending on if the instruction was bne. This ensured the same logic could be used for both bne and beq instructions, which simplifies the ALU.

This ALU served as the foundation for the ALU used in the complete RISC-V processor. I expanded upon it by using a 4-bit ALU_ctrl signal so it could differentiate between 16 instructions. As I introduced new logic to the ALU, I emphasized the design decision of reusing existing ALU logic for new instructions. For instance, the SUB, BNE and BEQ instructions all use the same ALU logic as shown below: (add code snippet)

However, a mistake I made was trying to overuse existing ALU logic instead of using a SystemVerilog operator. For instance, in the shift left logical (SLL) instruction where SLL rd, rs1, rs2 which means rd <- rs1 << rs2, I considered using the add logic to add rs1 with itself rs2 times. This has the same effect as shifting rs1 left by rs2 bits, and reuses an existing ALU logic. However, this requires overhead such as introducing registers to store the ALU output and then feed it as an ALU input to prevent a combinational loop. This operation would take multiple clock cycles to get the desired output, therefore, it was more suitable to create a new ALU logic which uses the shift operator, an inbuilt operator which performs the shift operation immediately.

---



