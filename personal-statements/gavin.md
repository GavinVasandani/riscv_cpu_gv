---

## Personal Statement - Gavin

1. My contributions.
2. Explanation of each component I contributed too, mention mistakes made, and what I learned (include code examples).
3. Obstacles faced in certain components (ram-cache) and how that led to special design decisions (include code examples).
4. Improvements for next time. 

## ALU


I served as the principal author for the arithmetic logic unit (ALU), register file, ram or data memory and the combined ram-cache memory unit. I also built test benches for each of these components to validate that they work as expected before they’re implemented in the complete CPU. 

When creating the ALU I, first, identified all the instructions that are required to implement the Lab 4 binary counter task. These initial instructions were: bne and addi, therefore only a 1 bit ALU_ctrl signal was needed to differentiate between the 2 instructions and they were both implemented using in-built operations. The ALU had 2 output signals, ALUout which was the result of the 2 inputs after applying a certain arithmetic and eq which was assigned HIGH if the 2 ALU inputs were equal, regardless of the instruction being bne or beq. The control unit applied a signal to invert eq depending on if the instruction was bne. This ensured the same logic could be used for both bne and beq instructions, which simplifies the ALU.

This ALU served as the foundation for the ALU used in the complete RISC-V processor. I expanded upon it by using a 4-bit ALU_ctrl signal so it could differentiate between 16 instructions. As I introduced new logic to the ALU, I emphasized the design decision of reusing existing ALU logic for new instructions. For instance, the SUB, BNE and BEQ instructions all use the same ALU logic as shown below: (add code snippet)

However, a mistake I made was trying to overuse existing ALU logic instead of using a SystemVerilog operator. For instance, in the shift left logical (SLL) instruction where SLL rd, rs1, rs2 which means rd <- rs1 << rs2, I considered using the add logic to add rs1 with itself rs2 times. This has the same effect as shifting rs1 left by rs2 bits, and reuses an existing ALU logic. However, this requires overhead such as introducing registers to store the ALU output and then feed it as an ALU input to prevent a combinational loop. This operation would take multiple clock cycles to get the desired output, therefore, it was more suitable to create a new ALU logic which uses the shift operator, an inbuilt operator which performs the shift operation immediately.

## Register File

To create the register file, I instantiated a set of 32 registers each storing a word of 32-bit size. Furthermore, registers are given specific uses as mentioned in Lecture 6 Slide 8. For instance, the register x0 only holds a constant value 0. This is useful for instructions like writing an immediate to a register, in this case register x0 can be used for rs1 as it has no effect on the immediate. 

(An example of this instruction is: addi x1, x0, 255.) - ADD as code snippet

Hence, before any register is written to, a conditional evaluates the destination register (rd) to ensure it isn’t register x0. Thus, after initialization, register x0 always holds constant value 0.

Finally, another design decision was to initialize each register in the register file with constant value 0 during start-up. After declaring the register file using a vector, the value held within each register is unknown and could effect the program result if a value is read and used from the register before an instruction writes to the register. Therefore, to have full knowledge of register values throughout the program execution, the design decision of initializing the register file with 0s was made.

## RAM-Cache

As an extension to the pipelined processor, I implemented a data cache to the main memory giving a new combined memory component called: RAM-cache. 

Initially, I planned on creating a separate cache component that would be wired to the existing RAM. This data cache would have an input DataIn that would be stored in the cache location if there was a cache miss. However, as DataIn is the data stored in main memory address A then the cache is unnecessary as regardless of a hit or miss, the data from main memory is fetched to be inputted into the cache component. Therefore, fetching data from the cache would take equal amount of cycles as fetching from main memory. 

As an alternative, I considered combining the RAM and data cache into one memory component called the RAM-Cache. This component has input address A where bits A[7:4], known as the set bits, are used to establish cache set location. As each set stores 4 32-bit data values, bits A[3:2] known as the block offset is used as the control signal for a multiplexer which outputs the data stored in the corresponding block. Finally, to check for a cache hit, the most significant bit of the data stored in the cache set, the valid bit is evaluated. Additionally, bits A[15:8] is compared with the cache’s tag to determine whether the cache contains the requested data.

A 4-way set associative cache was created as it considers both temporal and spatial locality. In the situation of a cache miss, the data is read from the main memory and flagMiss is HIGH. A conditional then evaluates flagMiss and writes the recently accessed data from the main memory into a specific block within the cache set. The neighboring memory locations for the given address are also simultaneously fetched from main memory and written to the same cache set in the remaining blocks. This allows data to be fetched from the cache set even if the address containing the data wasn’t previously queried. 

All write operations were executed in an always_ff block that executes at a positive edge, whereas all read operations were done in an always_comb block. This ensures that the clock cycles to read and write to the RAM-cache is identical to RAM which ensures that programs are still able to execute normally. In the case of a more complex CPU design, this implementation of the cache ensures that fetching from cache is far more quicker than reading from main memory. 

## RAM

Based on the RISC-V specifications, the RAM component uses byte addressing and the addresses are offset by 17’h1000 which allowed for easier debugging. This was implemented in the RAM declaration: 

(ADD CODE Snippet of RAM declaration)

In order to implement store byte, word and halfword instructions, a special design decision was to introduce a new control signal called DataType into the RAM. This is a 2-bit signal evaluated by a case statement that concatenates and outputs successive bytes depending on if dataType is 00 (word), 10 (halfword) or 01 (byte). The remainder of the bits, in the case of halfword or byte, are filled with 0s for unsigned extension to 32 bits. Similarly, the memory write operations evaluate dataType to determine whether to write only to address A, in the case of store byte instruction, or the next 3 successive addresses, if we have a store word instruction and therefore dataType is 00 (word).

## Reflection about what I have learned

Through this project, I have grown my understanding of the RISC-V architecture. Whilst I had a theoretical grasp of how an instruction is translated into an operation, by now creating the components that make up the RISC-V architecture on SystemVerilog, I was able to apply theory into practice which gave me insight into details that I previously overlooked. For instance, to implement load byte, halfword or word, I hadn’t considered how the RAM would differentiate between the data size requests as an input signal wasn’t mentioned in the provided diagrams. This led me to implement the dataType control signal. 

Our approach to building the complete CPU was constructing individual components, combining them in a top level module for ALU, control unit and PC and combining these components to form the complete system. This bottom-up and modular design approach was beneficial as I was able to repurpose components from the single-cycle CPU to build the different stages of the pipelined processor. So, from this project I have learned how to approach large programming tasks and I have improved my SystemVerilog proficiency.

## What I would have done differently

With more time available, I would change the cache organization to be 2-way associative cache with LRU replacement. Currently, I have implemented direct-mapped cache with 4 word blocks per set as it allows for spatial locality. This is optimal for the reference program as we’re reading and writing data in successive memory addresses. With spatial locality, these data values can now be easily fetched from the cache when its address is inputted. In a more complex CPU architecture, this cache organization would drastically reduce time taken for the reference program to run. However, for more general programs, a 2-way associative cache allows for less cache misses and maximizes temporal locality by only replacing the least recently used way in the cache line. 

