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

In order to implement Instructions, a few changes has been made.

1. For `JALR` and `JAL` operation, two bit control signal jump `J` is added. 
   |Operation   | J     |
   |:--------:  |:-:    |
   |JAL         | 01    |
   |JALR        | 10    |
   |other       | 00    |
2. `Datatype`, which is used to decide word operation, byte operation or half-word operation.
   |Operation   | Datatype|
   |:--------:  |:-:    |
   |lw          | 00    |
   |lbu         | 01    |
   |lhu         | 10    |
   |sw          | 00    |
   |sb          | 01    |
   |sh          | 10    |
3. `pc_reg` now have to choose between three values, `jalr_PC`, `inc_PC` (PC + ImmOp) and `alt_PC` (PC + 4).

4. `jalr_PC` is created as output from component `ALU`. It's the PC value for `JALR` instruction. `JALR` use the same `ALU_ctrl` value as `add` (0000), and has value as `ALU_out`. In any other cases, it has value of 0.

![a](../images-logbook/SingleCycle.jpeg)


- ### Debug
Most of the errors are syntex errors, and i didn't keep track of them. I documented some common errors, so others can prevent them.

---

# **Pipeline**

## Contribution

In this part of the project, me (Junyi WU) and Harry each create two registers, and I assemble the top module, fixed syntex errors and connection errors.

pipeline Registers also delay Output from control unit. This can make sure right control signal is delivered to the right component at the right moment.

---
## Pipeline assemble

**To make the code easier to read,  and make debugging easier, CPU is divided into 5 parts, F, D, E, M, and W from left to right.**


Four registers are added into the design, `reg1 - 4`. `register1` is rather simple, it's connected right after the Instruction Memory. `register 2,3 and 4`, however, needs to be connected inside the ALU. So ALU block is divided into four parts, `regfile.sv` (Register File), `alu_e.sv`, `ram.sv` (Data Memory), and `alu_w.sv`. These parts are connected by three registers. 

Apart from signal given in the slides, we added some more signals and made some changes.

1. `Jump` signal was extended to block `W`, because in our design, `Jump` signal is requires in `alu_e`.

2. In order to generate the signal `PCSrcE`, control unit gives a new output `Zero_select`. It pass through register2, and stop at block `E`. Below is the code for `PCSrcE`.
   
```systemverilog
logic PCsrcE_inter;

assign PCsrcE_inter = (Zero_selectE ? !ZeroE : ZeroE) & BranchE;

assign PCsrcE = PCsrcE_inter | JumpE[0];
```
----
# Mistakes and Experience

1. Many components have different names for the same signal. This caused many mistakes when assembling the CPU, especially when assembling the Pipeline version.
   
- discuss with the team in advance, decide all the names or the rule of naming.

2. `Data-Width` and `Address-Width` are two parameters used in almost every components, but that value is different in different components. So when other people use the components (add parameters), operation like shown in the example will cause number of bits doesn't match.
    
```systemverilog
input logic [ADDRESS_WIDTH-1:0] a0
```

- In components like `ram.sv` or `top_pc.sv`, parameters can make it easier for changing the Address-width and Data_width, but it's not necessary for every components to have them. Removing redundant parameter can make the code more efficient.

3. Control signals and corresponding instructions can be confussing for those who don't understand instruction set well.

- These important informations should be documented in the `readme.md` file. 

---
---

## Evidence
Commits corresponding to my contribution can be found here. 

**Note:** Many of the commits are in the old git project, and may not be found in the final assignment. Those will be shown seperately.

---
### Old project

#### write `ext.sv`
- [sign extension](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/acd427de9226d47c882ad4a16817afc41bf132b6)

#### initial `riscv_tb.cpp` and `top.sv` added
- [initial testbench and top module](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/0dc84ec7b69aa3cb8f17030e464595edfb6ce237)

#### Debug
- [fix some error, add common bugs in readme.md](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/b7afb35451e3b623daa2d2cffdd5e137b168cdfc)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/592600061d23f121ad5caa4b713a121c18e0cc41)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/cdbafc98e91de73d1278ebd823cc1c311d8055a7)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/ac0ef45fdb23184b45b077a06b05e491326a8bc8)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/d367ec775618bf284ff1498812756ca89f08cb41)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/9aafa02b5876adf8c3b3664717a230274e307fe7)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/a7ad1a239cfcbce72de4290a826bc6b302c568b3)
- [Debug](https://github.com/GavinVasandani/Lab4-Reduced-RISC-V-Architecture/commit/f5f7ff4857715090c66299c93caee184f0726b12)
  

### New project
Components were moved from old project to this new project

#### Debug
- [Debug](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/260e64ef3a2d798e87c55a24cb2d867fca9f2da8)

---

### **Pipeline**

### Register & test bench
#### `reg1.sv`
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/2479c9006b288790084596ab357be28d93f1569e
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/620a4a6fc8508cd4a691759a912684b8d1120991

#### `reg2.sv`

- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/1d3cbfd43e8abe4a1d4bdc7391e9dc4b7b1ed37e


#### `reg3.sv`
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/75a8a6b3506245404f4c17646f33054df105c2bd

#### `top.sv`
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/fe63d2979b14a3e3f12f9e7a91388530f2dec3fc

#### Debug
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/1ec9bbbf0e954719e5cc4dafd784f8dbf4035182
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/20a3207d203c8d64bde2f92d4d3a7b4bd2d45f54
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/06bafeb91fd2eb0b3697459bda0c6a7239c0f455
- https://github.com/EIE2-IAC-Labs/iac-riscv-cw-18/commit/be76e9ba2ea7758fe1eb38365455f6bee2fd5bc6
---

<!-- - #### PC

PC contains a PC register and a ROM called Instruction Memory. PC register control current address, and Instruction Memory contains all 32-bit Instructions.


Normally, next PC = PC + 4, but when JUMP or Branch type instuction is implemented, PC is assigned with a certain value, depends on the type of instruction and it's parameter.

- #### Control Unit

Control Unit takes Instruction as input, and analyse the instruction in order to give control other components(PC, ALU, Sign_extension). 

Control Unit can be divided into two parts, **Main Decoder** and **ALUDecoder**. **Main Decoder** use Opcode to determine the type of the instruction. This will give most of the information. It also give an 2-bit ALUOp to **ALUDecoder**, which use ALUOp and the rest of the instuction (*funct3 and funct7*) to calculate ALUcontrol output.

- #### ALU -->
