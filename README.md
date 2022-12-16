# Group 18's RISC - V CPU
##### *By: Arnav Kohli (sk1421), Gavin Vasandani (gv220), Junyi Wu, Xuhan Pan*

---
## Cache (in Single-Cycle Design)

This branch consists of the single cycle CPU design with a RAM-Cache component instead of a normal RAM. The RAM-Cache component can be viewed in the file 
[ram_cache_spatial.sv](rtl/riscv-alu/ram_cache_spatial.sv). 

We've chosen to build a direct mapped cache with 4 words per cache set. This cache organisation implements both spatial and temporal locality. 

As our reference programs often fetch data from neighbouring or successive memory addresses, this cache design is optimal and in a more complex CPU architecture it would drastically reduce time taken for the reference program to run. In a more complex CPU architecture, this cache organization would drastically reduce time taken for the reference program to run.

## Test

A [video](tests/cache-sc.mp4) of the cache with single cycle working is included in the [tests](tests/) directory.
 
Navigate to the rtl directory using the first command below and then execute the shell file using the second one:
 ```shell
 cd rtl

 source ./doit.sh
 ```
 
 To navigate back to the main branch type:
 ```shell
git checkout main
 ```
 
 ###### Authored by: Arnav Kohli
 ###### Videos by: Arnav Kohli
