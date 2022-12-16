# Group 18's RISC - V CPU
##### *By: Arnav Kohli (sk1421), Gavin Vasandani (gv220), Junyi Wu, Xuhan Pan (hp921)*

---
- ## Breakdown of tasks:
    - PC block, Instruction memory, Pipelining, Code for F1 light, Debugging, Testing and Verification, Documentation : **Arnav Kohli**
    - ALU Block, Register Files, Data memory and cache (including unit testing suites) : **Gavin Vasandani**
    - Control Block, Sign extension block, Pipelining: **Xuhan Pan**
    - Final CPU Assembly, Pipelining: **Junyi Wu**

---

|Module                              |Arnav Kohli    |Gavin Vasandani    |Junyi Wu   |Xuhan Pan  |
|:-----------------------------------|:-------------:|:-----------------:|:---------:|:---------:|
|[regfile.sv](rtl/riscv-alu/regfile.sv)                |               |      :star:       |           |           |
|[regfileALU.sv](rtl/riscv-alu/regfileALU.sv)             |               |      :star:       |           |           |
|[regfile_ALU_tb.cpp](rtl/riscv-alu/regFile_ALU_tb.cpp)        |               |      :star:       |           |           |
|[ram.sv](rtl/riscv-alu/ram.sv)                    |      :o:      |      :star:       |           |           |
|ram_cache_spatial.sv (in the cache branch)              |               |      :star:       |           |           |
|[control.sv](rtl/riscv-final-controlunit/control.sv)        |      :o:      |                   |           |   :star:  |
|[ext.sv](rtl/riscv-final-controlunit/ext.sv)           |      :o:      |                   |   :o:     |   :star:  |
|[control_tb.cpp](rtl/riscv-final-controlunit/control_tb.cpp)    |               |                   |           |   :star:  |
|[rom.sv](rtl/riscv-final-pc/rom.sv)               |     :star:    |                   |           |           |
|[pc_reg.sv](rtl/riscv-final-pc/pc_reg.sv)            |     :star:    |                   |           |           |
|[pc_tb.cpp](rtl/riscv-final-pc/pc_tb.cpp)            |     :star:    |                   |           |           |
|[top_pc](rtl/riscv-final-pc/top_pc.sv)           |     :star:    |                   |           |           |
|[top.sv](rtl/top.sv)                              |     :o:       |                   |   :star:  |    :o:    |
|[riscv_tb.cpp](rtl/riscv_tb.cpp)                        |     :star:    |                   |   :o:     |           |
|pipeline register folder (in the pipeline branch)            |               |        :o:        |   :star:  |   :star:  |
|pipeline stages (in the pipeline branch)                    |     :o:       |        :o:        |   :star:  |   :star:  |
|pipeline assembly & debugging (in the pipeline branch)       |     :o:       |                   |   :star:  |   :o:     |
|[F1.s](tests/f1.s)                                |     :star:    |                   |           |           |

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
    
    To test the f1 code, navigate to the rtl directory using the first command below and then execute the shell file using the second one:
     ```shell
     cd rtl

     source ./doit.sh
     ```
     The [testbench](rtl/riscv_tb.cpp) has been set up in order to allow for execution of the light sequence to start **once the rotary encoder has been pressed**. For more details on how the code works, look at [Arnav's personal statement](personal-statements/arnav.md)

    The remaining personal statements can be found below:
    1. [Gavin's personal statement](personal-statements/gavin.md)
    2. [Harry's personal statement](personal-statements/xuhan.md)
    3. [Junyi's personal statement](personal-statements/junyi.md)

  To navigate to the pipeline branch type:
  ```bash
  git checkout pipeline
  ```

  To test the reference program on single cycle type:
  ```bash
  git checkout sc-reference
  ```

  To test the reference program on pipeline type:
  ```bash
  git checkout pp-reference
  ```

  To navigate to the cache branch:
  ```bash
  git checkout cache
  ```
  Follow test instructions to test reference program on single cycle design with cache.
  
  To test reference program in pipelined processor with cache (reference program test, since only the ram is changing) type:
  ```bash
  git checkout pipeline_with_cache
  ```

In any of the branches that test reference programs, the data in the ram can be changed from

```systemverilog
  $readmemh("reference/gaussian.mem", ram_array, 17'h10000);
```

to whatever distribution the assessor wants to check. For simplicity, the default distribution on running each branch is the Gaussian distribution

###### Videos by : Arnav Kohli
###### Authored by : Arnav Kohli

---


