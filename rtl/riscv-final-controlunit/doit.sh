rm -rf obj_dir
rm -f control.vcd

verilator -Wall --cc --trace control.sv --exe control_tb.cpp
make -j -C obj_dir/ -f Vcontrol.mk Vcontrol

obj_dir/Vcontrol