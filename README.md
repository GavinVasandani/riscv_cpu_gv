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
|riscv-controlunit/control.sv        |               |                   |           |   :star:  |
|riscv-controlunit/ext.sv            |               |                   |   :o:     |   :star:  |
|riscv-controlunit/control_tb.cpp    |               |                   |           |   :star:  |
|riscv-final-pc/rom.sv               |               |                   |           |           |
|riscv-final-pc/pc_reg.sv            |               |                   |           |           |
|riscv-final-pc/pc_tb.cpp            |               |                   |           |           |
|top.sv                              |               |                   |           |   :o:     |
|riscv_tb.cpp                        |               |                   |   :star:  |           |
|pipeline register                   |               |                   |   :star:  |   :star:  |
|pipeline stages                     |               |                   |   :star:  |   :star:  |
|pipeline assembly & debugging       |               |                   |   :star:  |   :o:     |
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



