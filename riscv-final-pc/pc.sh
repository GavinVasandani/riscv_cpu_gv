rm -rf obj_dir
rm -f top_pc.vcd
verilator -Wall --cc --trace top_pc.sv --exe pc_tb.cpp
make -j -C obj_dir/ -f Vtop_pc.mk Vtop_pc
obj_dir/Vtop_pc