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
|riscv-controlunit/control.sv        |      :o:      |                   |           |   :star:  |
|riscv-controlunit/ext.sv            |      :o:      |                   |   :o:     |   :star:  |
|riscv-controlunit/control_tb.cpp    |               |                   |           |   :star:  |
|riscv-final-pc/rom.sv               |     :star:    |                   |           |           |
|riscv-final-pc/pc_reg.sv            |     :star:    |                   |           |           |
|riscv-final-pc/pc_tb.cpp            |     :star:    |                   |           |           |
|top.sv                              |     :o:       |                   |   :star:  |    :o:    |
|riscv_tb.cpp                        |     :star:    |                   |           |           |
|pipeline register folder            |               |                   |   :star:  |    :o:    |
|pipeline stages                     |     :o:       |        :o:        |   :star:  |   :star:  |
|pipeline assembly & debugging       |     :o:       |                   |   :star:  |   :star:  |
|F1.s                                |     :star:    |                   |           |           |

:star: Principal Author

:o: Contributed


---



