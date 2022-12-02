rm -rf obj_dir
rm -f PC_top.vcd
verilator -Wall --cc --trace PC_top.sv pcreg.sv rom.sv --exe pc_tb.cpp
make -j -C obj_dir/ -f VPC_top.mk VPC_top
obj_dir/VPC_top