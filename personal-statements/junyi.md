# **Single cycle CPU** &nbsp; Junyi Wu

## Contribution

In this part of the project, I was responsible of creating top module to connect all the components, and fix syntex errors in `top.sv` and individual components. I also wrote the initial version of `test bench`.

- ### Test Bench

Test bench is a cpp file that execute the whole CPU design. It's not complicated, what it needs to do is initialise three parameter, and interact with Vbuddy to display sertain output.

**initialisation part:**
```
top->trigger = 0;
top->rst = 1;
top->clk = 1;
```
**Vbuddy display part:**
```
vbdHex(2, (int(top->a0) >> 4) & 0XF);
vbdHex(1, int(top->a0) & 0XF);
vbdBar(top->a0 & 0xFF);
vbdCycle(i+1);
top->trigger = vbdFlag();
```

- ### **Top Module**
Top Module is an important part, It connect all components.

![a](../images-logbook/SingleCycle.jpeg)


- ### Debug

---

# **Pipeline**

## Contribution

In this part of the project, me (Junyi WU) and Harry each create two register, and I assemble the top module, and fix syntex errors and connection errors.

pipeline Registers also delay Output from control unit. This can make sure right control signal is delivered to the right component at the right moment.

---
## Pipeline assemble

**To make the code easier to read,  and make debugging easier, CPU is divided into 5 parts, F, D, E, M, and W from left to right.**


Four registers are added into the design, `reg1 - 4`. `register1` is rather simple, it's connected right after the Instruction Memory. `register 2,3 and 4`, however, needs to be connected inside the ALU. So ALU block is divided into four parts, `regfile.sv` (Register File), `alu_e.sv`, `ram.sv` (Data Memory), and `alu_w.sv`. These parts are connected by three registers. 

Apart from signal given in the slides, we added one more signals.

1. `Datatype`, which is used to decide word operation, byte operation or half-word operation.
2. `Jump` signal has also been extended to block `W`, in out design, `Jump` signal is requires in `alu_e`.
3. `Jump` Signal has been extended from 1 bit to 2 bits. This is because we need **JAL, JALR** instructions.
4. In order to generate the signal `PCSrcE`, control unit gives a new output `Zero_select`. It pass through register2, and stop at block `E`. Below is the code for `PCSrcE`.
   
```systemverilog
logic PCsrcE_inter;

assign PCsrcE_inter = (Zero_selectE ? !ZeroE : ZeroE) & BranchE;

assign PCsrcE = PCsrcE_inter | JumpE[0];
```








## Mistakes and Experience

1. Many components have different names for the same signal. This caused many mistakes when assembling the CPU.
   
- discuss with the team in advance, decide all the names or the rule of naming.

2. `Data-Width` and `Address-Width` are two parameters used in almost every components, but that value is different in different components. So when other people use the components (add parameters), operation like shown in the example will cause number of bits doesn't match.
    
```systemverilog
input logic [ADDRESS_WIDTH-1:0] a0
```

- In components like `ram.sv` or `top_pc.sv`, parameters can make it easier for changing the Address-width and Data_width, but it's not necessary for every components to have them. Removing redundant parameter can make the code more efficient.


---
---

## Evidence
Commits corresponding to my contribution can be found here. 

**Note:** Many of the commits are in the old git project, and may not be found in the final assignment. Those will be shown seperately.

---
### Old project

#### write `ext.sv`
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/acd427de9226d47c882ad4a16817afc41bf132b6

#### initial `riscv_tb.cpp` and `top.sv` added
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/0dc84ec7b69aa3cb8f17030e464595edfb6ce237

#### Debug
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/b7afb35451e3b623daa2d2cffdd5e137b168cdfc
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/592600061d23f121ad5caa4b713a121c18e0cc41
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/cdbafc98e91de73d1278ebd823cc1c311d8055a7
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/ac0ef45fdb23184b45b077a06b05e491326a8bc8
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/d367ec775618bf284ff1498812756ca89f08cb41
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/9aafa02b5876adf8c3b3664717a230274e307fe7
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/a7ad1a239cfcbce72de4290a826bc6b302c568b3
- https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/f5f7ff4857715090c66299c93caee184f0726b12
  
---
### New project
Components were moved from old project to this new project

#### Debug
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/260e64ef3a2d798e87c55a24cb2d867fca9f2da8


---

<!-- - #### PC

PC contains a PC register and a ROM called Instruction Memory. PC register control current address, and Instruction Memory contains all 32-bit Instructions.


Normally, next PC = PC + 4, but when JUMP or Branch type instuction is implemented, PC is assigned with a certain value, depends on the type of instruction and it's parameter.

- #### Control Unit

Control Unit takes Instruction as input, and analyse the instruction in order to give control other components(PC, ALU, Sign_extension). 

Control Unit can be divided into two parts, **Main Decoder** and **ALUDecoder**. **Main Decoder** use Opcode to determine the type of the instruction. This will give most of the information. It also give an 2-bit ALUOp to **ALUDecoder**, which use ALUOp and the rest of the instuction (*funct3 and funct7*) to calculate ALUcontrol output.

- #### ALU -->
