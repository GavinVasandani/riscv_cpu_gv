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
|riscv-alu/regfile.sv                |               |                   |           |           |
|riscv-alu/regfile_ALU_tb.cpp        |               |                   |           |           |
|riscv-alu/ram.sv                    |               |                   |           |           |
|riscv-alu/ram_cache.sv              |               |                   |           |           |
|riscv-controlunit/control.sv        |               |                   |           |     :star:     |
|riscv-controlunit/control_tb.cpp    |               |                   |           |           |
|riscv-final-pc/rom.sv               |               |                   |           |           |
|riscv-final-pc/pc_reg.sv            |               |                   |           |           |
|riscv-final-pc/pc_tb.cpp            |               |                   |           |           |
|top.sv                              |               |                   |     :star:     |           |
|riscv_tb.cpp                        |               |                   |     :star:     |           |
|pipeline register                   |               |                   |     :star:     |     :o:     |
|pipeline stages                     |               |                   |     :star:     |     :o:     |
|pipeline assembly & debugging       |               |                   |     :star:     |     :o:     |
|F1.s                                |               |                   |           |           |

:star: Principal Author

:o: Contributed

