rm -rf obj_dir
rm -f ext.vcd

verilator -Wall --cc --trace  ext.sv --exe ext_tb.cpp

make -j -C obj_dir/ -f Vext.mk Vext

obj_dir/Vext