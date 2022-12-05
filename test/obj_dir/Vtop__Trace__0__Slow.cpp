// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBit(c+94,"rst", false,-1);
    tracep->declBus(c+95,"a0", false,-1, 31,0);
    tracep->declBit(c+96,"wr_en", false,-1);
    tracep->declBit(c+97,"Eq", false,-1);
    tracep->declBit(c+98,"alusrc", false,-1);
    tracep->declBus(c+99,"aluCtrl", false,-1, 2,0);
    tracep->declBus(c+100,"extout", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+101,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+101,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBit(c+94,"rst", false,-1);
    tracep->declBus(c+95,"a0", false,-1, 31,0);
    tracep->declBit(c+96,"wr_en", false,-1);
    tracep->declBit(c+97,"Eq", false,-1);
    tracep->declBit(c+98,"alusrc", false,-1);
    tracep->declBus(c+99,"aluCtrl", false,-1, 2,0);
    tracep->declBus(c+100,"extout", false,-1, 31,0);
    tracep->declBit(c+29,"write_en", false,-1);
    tracep->declBus(c+30,"PC_instr", false,-1, 31,0);
    tracep->declBit(c+31,"PCsrc", false,-1);
    tracep->declBus(c+32,"rs1", false,-1, 4,0);
    tracep->declBus(c+33,"rs2", false,-1, 4,0);
    tracep->declBus(c+34,"rd", false,-1, 4,0);
    tracep->declBus(c+102,"write_data", false,-1, 31,0);
    tracep->declBit(c+35,"ALUSrc", false,-1);
    tracep->declBus(c+36,"ALU_ctrl", false,-1, 2,0);
    tracep->declBit(c+37,"EQ", false,-1);
    tracep->declBus(c+38,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+39,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+103,"imm_imm", false,-1, 11,0);
    tracep->declBus(c+104,"imm_branch", false,-1, 12,0);
    tracep->declBit(c+40,"MemWrite", false,-1);
    tracep->declBit(c+41,"ResultSrc", false,-1);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+101,"NumberOfReg", false,-1, 31,0);
    tracep->declBus(c+105,"Address_Width_RegFile", false,-1, 31,0);
    tracep->declBus(c+106,"Address_Width_RAM", false,-1, 31,0);
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBus(c+32,"rs1", false,-1, 4,0);
    tracep->declBus(c+33,"rs2", false,-1, 4,0);
    tracep->declBus(c+34,"rd", false,-1, 4,0);
    tracep->declBit(c+29,"regFileWen", false,-1);
    tracep->declBit(c+35,"ALUSrc", false,-1);
    tracep->declBus(c+38,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+42,"ALU_ctrl", false,-1);
    tracep->declBit(c+40,"MemWrite", false,-1);
    tracep->declBit(c+41,"ResultSrc", false,-1);
    tracep->declBit(c+37,"eq", false,-1);
    tracep->declBus(c+43,"rd1", false,-1, 31,0);
    tracep->declBus(c+44,"rd2", false,-1, 31,0);
    tracep->declBus(c+45,"ALUOp2", false,-1, 31,0);
    tracep->declBus(c+46,"ALUout", false,-1, 31,0);
    tracep->declBus(c+47,"dinTest", false,-1, 31,0);
    tracep->declBus(c+48,"ReadData", false,-1, 31,0);
    tracep->pushNamePrefix("alu1 ");
    tracep->declBus(c+105,"Address_Width", false,-1, 31,0);
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+43,"op1", false,-1, 31,0);
    tracep->declBus(c+45,"op2", false,-1, 31,0);
    tracep->declBit(c+42,"ALU_ctrl", false,-1);
    tracep->declBus(c+46,"ALUout", false,-1, 31,0);
    tracep->declBit(c+37,"eq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+44,"regOp2", false,-1, 31,0);
    tracep->declBus(c+38,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+35,"ALUSrc", false,-1);
    tracep->declBus(c+45,"ALUOp2", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram1 ");
    tracep->declBus(c+106,"Address_Width", false,-1, 31,0);
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBit(c+40,"WE", false,-1);
    tracep->declBus(c+49,"A", false,-1, 7,0);
    tracep->declBus(c+44,"WD", false,-1, 31,0);
    tracep->declBus(c+48,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regFile1 ");
    tracep->declBus(c+101,"NumberOfReg", false,-1, 31,0);
    tracep->declBus(c+105,"Address_Width", false,-1, 31,0);
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBus(c+32,"rs1", false,-1, 4,0);
    tracep->declBus(c+33,"rs2", false,-1, 4,0);
    tracep->declBus(c+34,"rd", false,-1, 4,0);
    tracep->declBit(c+29,"en", false,-1);
    tracep->declBus(c+47,"din", false,-1, 31,0);
    tracep->declBus(c+43,"rd1", false,-1, 31,0);
    tracep->declBus(c+44,"rd2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+50+i*1,"regFile_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("resultMux1 ");
    tracep->declBus(c+101,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+46,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+48,"ReadData", false,-1, 31,0);
    tracep->declBit(c+41,"ResultSrc", false,-1);
    tracep->declBus(c+47,"Result", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("control_unit ");
    tracep->declBus(c+82,"op", false,-1, 6,0);
    tracep->declBus(c+83,"funct3", false,-1, 2,0);
    tracep->declBit(c+84,"funct75", false,-1);
    tracep->declBit(c+37,"Zero", false,-1);
    tracep->declBit(c+31,"PCSrc", false,-1);
    tracep->declBit(c+41,"ResultSrc", false,-1);
    tracep->declBit(c+40,"MemWrite", false,-1);
    tracep->declBus(c+36,"ALUControl", false,-1, 2,0);
    tracep->declBit(c+35,"ALUSrc", false,-1);
    tracep->declBus(c+39,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+29,"RegWrite", false,-1);
    tracep->declBit(c+85,"Branch", false,-1);
    tracep->declBus(c+86,"ALUOp", false,-1, 1,0);
    tracep->pushNamePrefix("a ");
    tracep->declBit(c+87,"op5", false,-1);
    tracep->declBus(c+83,"funct3", false,-1, 2,0);
    tracep->declBit(c+84,"funct75", false,-1);
    tracep->declBus(c+86,"ALUOp", false,-1, 1,0);
    tracep->declBus(c+36,"ALUControl", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("m ");
    tracep->declBus(c+82,"op", false,-1, 6,0);
    tracep->declBus(c+39,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+85,"Branch", false,-1);
    tracep->declBit(c+41,"ResultSrc", false,-1);
    tracep->declBit(c+40,"MemWrite", false,-1);
    tracep->declBit(c+35,"ALUSrc", false,-1);
    tracep->declBit(c+29,"RegWrite", false,-1);
    tracep->declBus(c+86,"ALUOp", false,-1, 1,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("myPC ");
    tracep->declBus(c+101,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+101,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+38,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+31,"PCsrc", false,-1);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBit(c+94,"rst", false,-1);
    tracep->declBus(c+30,"instr", false,-1, 31,0);
    tracep->declBus(c+88,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("myPCreg ");
    tracep->declBus(c+101,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+38,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+31,"PCsrc", false,-1);
    tracep->declBit(c+93,"clk", false,-1);
    tracep->declBit(c+94,"rst", false,-1);
    tracep->declBus(c+88,"PC", false,-1, 31,0);
    tracep->declBus(c+89,"branch_PC", false,-1, 31,0);
    tracep->declBus(c+90,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+91,"next_PC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myRom ");
    tracep->declBus(c+101,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+106,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+88,"PC", false,-1, 31,0);
    tracep->declBus(c+30,"instr", false,-1, 31,0);
    for (int i = 0; i < 28; ++i) {
        tracep->declBus(c+1+i*1,"rom_array", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sign_extend ");
    tracep->declBus(c+92,"imm", false,-1, 31,7);
    tracep->declBus(c+39,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+38,"ImmExt", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[0]),8);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[1]),8);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[2]),8);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[3]),8);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[4]),8);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[5]),8);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[6]),8);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[7]),8);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[8]),8);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[9]),8);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[10]),8);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[11]),8);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[12]),8);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[13]),8);
    bufp->fullCData(oldp+15,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[14]),8);
    bufp->fullCData(oldp+16,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[15]),8);
    bufp->fullCData(oldp+17,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[16]),8);
    bufp->fullCData(oldp+18,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[17]),8);
    bufp->fullCData(oldp+19,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[18]),8);
    bufp->fullCData(oldp+20,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[19]),8);
    bufp->fullCData(oldp+21,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[20]),8);
    bufp->fullCData(oldp+22,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[21]),8);
    bufp->fullCData(oldp+23,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[22]),8);
    bufp->fullCData(oldp+24,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[23]),8);
    bufp->fullCData(oldp+25,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[24]),8);
    bufp->fullCData(oldp+26,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[25]),8);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[26]),8);
    bufp->fullCData(oldp+28,(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[27]),8);
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__write_en));
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__PC_instr),32);
    bufp->fullBit(oldp+31,(((IData)(vlSelf->top__DOT__EQ) 
                            & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))));
    bufp->fullCData(oldp+32,((0x1fU & (vlSelf->top__DOT__PC_instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+33,((0x1fU & (vlSelf->top__DOT__PC_instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+34,((0x1fU & (vlSelf->top__DOT__PC_instr 
                                       >> 7U))),5);
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__ALUSrc));
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__ALU_ctrl),3);
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__EQ));
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__ImmSrc),2);
    bufp->fullBit(oldp+40,(vlSelf->top__DOT__MemWrite));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__ResultSrc));
    bufp->fullBit(oldp+42,((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))));
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__ALU__DOT__rd1),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__ALU__DOT__rd2),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__ALU__DOT__ALUOp2),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__ALU__DOT__ALUout),32);
    bufp->fullIData(oldp+47,(((IData)(vlSelf->top__DOT__ResultSrc)
                               ? vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                              [(0xffU & vlSelf->top__DOT__ALU__DOT__ALUout)]
                               : vlSelf->top__DOT__ALU__DOT__ALUout)),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                             [(0xffU & vlSelf->top__DOT__ALU__DOT__ALUout)]),32);
    bufp->fullCData(oldp+49,((0xffU & vlSelf->top__DOT__ALU__DOT__ALUout)),8);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[0]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[1]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[2]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[3]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[4]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[5]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[6]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[7]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[8]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[9]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[10]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[11]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[12]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[13]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[14]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[15]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[16]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[17]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[18]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[19]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[20]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[21]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[22]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[23]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[24]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[25]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[26]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[27]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[28]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[29]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[30]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[31]),32);
    bufp->fullCData(oldp+82,((0x7fU & vlSelf->top__DOT__PC_instr)),7);
    bufp->fullCData(oldp+83,((7U & (vlSelf->top__DOT__PC_instr 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+84,((1U & (vlSelf->top__DOT__PC_instr 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+85,(vlSelf->top__DOT__control_unit__DOT__Branch));
    bufp->fullCData(oldp+86,(vlSelf->top__DOT__control_unit__DOT__ALUOp),2);
    bufp->fullBit(oldp+87,((1U & (vlSelf->top__DOT__PC_instr 
                                  >> 5U))));
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__myPC__DOT__PC),32);
    bufp->fullIData(oldp+89,((vlSelf->top__DOT__myPC__DOT__PC 
                              + vlSelf->top__DOT__ImmOp)),32);
    bufp->fullIData(oldp+90,(((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC)),32);
    bufp->fullIData(oldp+91,((((IData)(vlSelf->top__DOT__EQ) 
                               & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))
                               ? (vlSelf->top__DOT__myPC__DOT__PC 
                                  + vlSelf->top__DOT__ImmOp)
                               : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC))),32);
    bufp->fullIData(oldp+92,((vlSelf->top__DOT__PC_instr 
                              >> 7U)),25);
    bufp->fullBit(oldp+93,(vlSelf->clk));
    bufp->fullBit(oldp+94,(vlSelf->rst));
    bufp->fullIData(oldp+95,(vlSelf->a0),32);
    bufp->fullBit(oldp+96,(vlSelf->wr_en));
    bufp->fullBit(oldp+97,(vlSelf->Eq));
    bufp->fullBit(oldp+98,(vlSelf->alusrc));
    bufp->fullCData(oldp+99,(vlSelf->aluCtrl),3);
    bufp->fullIData(oldp+100,(vlSelf->extout),32);
    bufp->fullIData(oldp+101,(0x20U),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__write_data),32);
    bufp->fullSData(oldp+103,(vlSelf->top__DOT__imm_imm),12);
    bufp->fullSData(oldp+104,(vlSelf->top__DOT__imm_branch),13);
    bufp->fullIData(oldp+105,(5U),32);
    bufp->fullIData(oldp+106,(8U),32);
}
