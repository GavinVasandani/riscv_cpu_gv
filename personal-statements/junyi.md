# Contribution

## **Single cycle CPU**

In this part of the project, I was responsible for write test bench, creating top module to connect all the components, and do debugging.

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
- #### PC

PC contains a PC register and a ROM called Instruction Memory. PC register control current address, and Instruction Memory contains all 32-bit Instructions.


Normally, next PC = PC + 4, but when JUMP or Branch type instuction is implemented, PC is assigned with a certain value, depends on the type of instruction and it's parameter.

- #### Control Unit

Control Unit takes Instruction as input, and analyse the instruction in order to give control other components(PC, ALU, Sign_extension). 

Control Unit can be divided into two parts, **Main Decoder** and **ALUDecoder**. **Main Decoder** use Opcode to determine the type of the instruction. This will give most of the information. It also give an 2-bit ALUOp to **ALUDecoder**, which use ALUOp and the rest of the instuction (*funct3 and funct7*) to calculate ALUcontrol output.

- #### ALU



## **Pipeline**
In this part of the project, me (Junyi WU) and Harry each create two register, and I assemble the top module, and fix syntex errors and connection errors.

---
Four registers are added into the design, reg1 - 4. register1 is rather simple, it's connected right after the Instruction Memory. register 2,3 and 4, however, needs to be connected inside the ALU. So ALU block is divided into three parts, **Registerfile**, **alu_e.sv**, **alu