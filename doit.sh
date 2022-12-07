# rm -rf obj_dir
rm -f top.vcd

verilator -Wall --cc --trace  top.sv -I../riscv-final-pc -I../riscv-final-controlunit -I../riscv-alu  --exe riscv_tb.cpp
# verilator -Wall --cc --trace  control.sv PC.sv pcreg.sv rom.sv regFile.sv regFileALU.sv regFileMux.sv topLevelALU.sv ext.sv top.sv    --exe lab4_tb.cpp

make -j -C obj_dir/ -f Vtop.mk Vtop

obj_dir/Vtop