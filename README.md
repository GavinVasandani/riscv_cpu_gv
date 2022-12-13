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
|riscv-alu/ram.sv                    |               |      :star:       |           |           |
|riscv-alu/ram_cache.sv              |               |      :star:       |           |           |
|riscv-controlunit/control.sv        |               |                   |           |           |
|riscv-controlunit/ext.sv            |               |                   |   :o:     |           |
|riscv-controlunit/control_tb.cpp    |               |                   |           |           |
|riscv-final-pc/rom.sv               |               |                   |           |           |
|riscv-final-pc/pc_reg.sv            |               |                   |           |           |
|riscv-final-pc/pc_tb.cpp            |               |                   |           |           |
|top.sv                              |               |                   |   :star:  |           |
|riscv_tb.cpp                        |               |                   |   :star:  |           |
|pipeline register                   |               |                   |   :star:  |           |
|pipeline stages                     |               |        :o:        |   :star:  |           |
|pipeline assembly & debugging       |               |                   |   :star:  |           |
|F1.s                                |               |                   |           |           |

:star: Principal Author

:o: Contributed

---

## Personal Statement - Gavin

1. My contributions.
2. Explanation of each component I contributed too, mention mistakes made, and what I learned (include code examples).
3. Obstacles faced in certain components (ram-cache) and how that led to special design decisions (include code examples).
4. Improvements for next time. 

---



