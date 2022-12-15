# Group 18's RISC - V CPU
##### *By: Arnav Kohli (sk1421), Gavin Vasandani (gv220), Junyi Wu, Xuhan Pan*

---
- ## Breakdown of tasks:
    - PC block, Instruction memory, Pipelining, Code for F1 light, Debugging, Testing and Verification, Documentation : **Arnav Kohli**
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
|riscv_tb.cpp                        |     :star:    |                   |   :o:     |           |
|pipeline register folder            |               |                   |   :star:  |   :star:  |
|pipeline stages                     |     :o:       |        :o:        |   :star:  |   :star:  |
|pipeline assembly & debugging       |     :o:       |                   |   :star:  |   :o:     |
|F1.s                                |     :star:    |                   |           |           |

:star: Principal Author

:o: Contributed

###### Authored by : Gavin Vasandani
---

- ## Branches:
  This repository has been split up into three branches. The current branch contains the code for the single cycle RISC-V CPU. The pipeline branch and the cache branch, as the names suggest are the stretched goals mentioned in the project brief.

- ## Single Cycle branch (main):
  The results for the reference program can be found in the [tests](tests/) directory:
  1. [F1 program code](tests/f1.s)
  2. [F1 test video](tests/sc-f1.mp4)
  3. [Gaussian distribution](tests/sc-gaussian.mp4)
  4. [Sine distribution](tests/sc-sine.mp4)
  5. [Triangle distribution](tests/sc-triangle.mp4)
    
    To test the f1 code, navigate to the rtl directory using the first command below and then execute the shell file using the commands one after the other:
     ```shell
     cd rtl

     source ./doit.sh
     ```
     The [testbench](rtl/riscv_tb.cpp) has been set up in order to allow for execution of the light sequence to start once the rotary encoder has been pressed. For more details on how the code works, look at [Arnav's personal statement](personal-statements/arnav.md)

    The remaining personal statements can be found below:
    1. [Gavin's personal statement](personal-statements/gavin.md)
    2. [Harry's personal statement](personal-statements/xuhan.md)
    3. [Junyi's personal statement](personal-statements/junyi.md)

  To navigate to the pipeline branch type:
  ```bash
  git checkout pipeline
  ```
  And for the cache branch type:
  ```bash
  git checkout cache
  ```


###### Videos by : Arnav Kohli
###### Authored by : Arnav Kohli


