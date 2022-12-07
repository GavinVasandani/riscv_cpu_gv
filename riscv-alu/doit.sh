rm -rf obj_dir
rm -f topLevelALU.vcd

verilator -Wall --cc --trace  topLevelALU.sv --exe regFile_ALU_tb.cpp

make -j -C obj_dir/ -f VtopLevelALU.mk VtopLevelALU

obj_dir/VtopLevelALU