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
    tracep->declBit(c+71,"trigger", false,-1);
    tracep->declBit(c+72,"top.clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"a0", false,-1, 31,0);
    tracep->declBit(c+75,"top_dataram.clk", false,-1);
    tracep->declBit(c+76,"WE", false,-1);
    tracep->declBus(c+77,"A", false,-1, 31,0);
    tracep->declBus(c+78,"WD", false,-1, 31,0);
    tracep->declBit(c+79,"ResultSrc", false,-1);
    tracep->declBus(c+80,"Result", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+87,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+71,"trigger", false,-1);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"a0", false,-1, 31,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+2,"PC_instr", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"rd", false,-1, 4,0);
    tracep->declBus(c+88,"write_data", false,-1, 31,0);
    tracep->declBit(c+7,"ALUSrc", false,-1);
    tracep->declBus(c+8,"ALU_ctrl", false,-1, 3,0);
    tracep->declBit(c+9,"EQ", false,-1);
    tracep->declBus(c+10,"DataType", false,-1, 1,0);
    tracep->declBit(c+11,"J", false,-1);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+13,"next_PC", false,-1, 31,0);
    tracep->declBus(c+14,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+89,"imm_imm", false,-1, 11,0);
    tracep->declBus(c+90,"imm_branch", false,-1, 12,0);
    tracep->declBit(c+15,"MemWrite", false,-1);
    tracep->declBit(c+16,"ResultSrc", false,-1);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+91,"Address_Width_RegFile", false,-1, 31,0);
    tracep->declBus(c+92,"Address_Width_RAM", false,-1, 31,0);
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"rd", false,-1, 4,0);
    tracep->declBit(c+1,"regFileWen", false,-1);
    tracep->declBit(c+71,"trigger", false,-1);
    tracep->declBit(c+7,"ALUSrc", false,-1);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+8,"ALU_ctrl", false,-1, 3,0);
    tracep->declBit(c+15,"MemWrite", false,-1);
    tracep->declBus(c+10,"dataType", false,-1, 1,0);
    tracep->declBit(c+16,"SrcSel", false,-1);
    tracep->declBus(c+13,"newPC", false,-1, 31,0);
    tracep->declBit(c+11,"JumpSel", false,-1);
    tracep->declBit(c+9,"eq", false,-1);
    tracep->declBus(c+74,"a0", false,-1, 31,0);
    tracep->declBus(c+17,"rd1", false,-1, 31,0);
    tracep->declBus(c+18,"rd2", false,-1, 31,0);
    tracep->declBus(c+19,"ALUOp2", false,-1, 31,0);
    tracep->declBus(c+20,"ALUout", false,-1, 31,0);
    tracep->declBus(c+21,"ReadData", false,-1, 31,0);
    tracep->declBus(c+22,"ResultSrcOutput", false,-1, 31,0);
    tracep->declBus(c+23,"regWrite", false,-1, 31,0);
    tracep->pushNamePrefix("alu1 ");
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+17,"op1", false,-1, 31,0);
    tracep->declBus(c+19,"op2", false,-1, 31,0);
    tracep->declBus(c+8,"ALU_ctrl", false,-1, 3,0);
    tracep->declBus(c+20,"ALUout", false,-1, 31,0);
    tracep->declBit(c+9,"eq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+18,"regOp2", false,-1, 31,0);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+7,"ALUSrc", false,-1);
    tracep->declBus(c+19,"ALUOp2", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram1 ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+87,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+93,"BYTE_WIDTH", false,-1, 31,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+15,"WE", false,-1);
    tracep->declBus(c+10,"dataType", false,-1, 1,0);
    tracep->declBus(c+24,"A", false,-1, 31,0);
    tracep->declBus(c+18,"WD", false,-1, 31,0);
    tracep->declBus(c+21,"RD", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+25+i*1,"ram_array", true,(i+-1), 7,0);
    }
    tracep->declBus(c+27,"byteAssign", false,-1, 7,0);
    tracep->declBus(c+28,"halfwordAssign", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regFile1 ");
    tracep->declBus(c+91,"Address_Width", false,-1, 31,0);
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"rd", false,-1, 4,0);
    tracep->declBit(c+1,"en", false,-1);
    tracep->declBit(c+71,"trigger", false,-1);
    tracep->declBus(c+23,"din", false,-1, 31,0);
    tracep->declBus(c+17,"rd1", false,-1, 31,0);
    tracep->declBus(c+18,"rd2", false,-1, 31,0);
    tracep->declBus(c+74,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+29+i*1,"regFile_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("resultPCMux1 ");
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+22,"ResultSrc", false,-1, 31,0);
    tracep->declBus(c+13,"newPC", false,-1, 31,0);
    tracep->declBit(c+11,"JumpSel", false,-1);
    tracep->declBus(c+23,"Result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("resultSrcMux1 ");
    tracep->declBus(c+87,"Data_Width", false,-1, 31,0);
    tracep->declBus(c+20,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+21,"ReadData", false,-1, 31,0);
    tracep->declBit(c+16,"SrcSel", false,-1);
    tracep->declBus(c+22,"OutputSrcMux", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("control_unit ");
    tracep->declBus(c+61,"op", false,-1, 6,0);
    tracep->declBus(c+62,"funct3", false,-1, 2,0);
    tracep->declBit(c+63,"funct75", false,-1);
    tracep->declBit(c+9,"Zero", false,-1);
    tracep->declBit(c+3,"PCSrc", false,-1);
    tracep->declBit(c+16,"ResultSrc", false,-1);
    tracep->declBit(c+15,"MemWrite", false,-1);
    tracep->declBus(c+8,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+7,"ALUSrc", false,-1);
    tracep->declBus(c+14,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+10,"DataType", false,-1, 1,0);
    tracep->declBit(c+11,"J", false,-1);
    tracep->declBit(c+64,"Branch", false,-1);
    tracep->declBus(c+65,"ALUOp", false,-1, 1,0);
    tracep->pushNamePrefix("a ");
    tracep->declBit(c+66,"op5", false,-1);
    tracep->declBus(c+62,"funct3", false,-1, 2,0);
    tracep->declBit(c+63,"funct75", false,-1);
    tracep->declBus(c+65,"ALUOp", false,-1, 1,0);
    tracep->declBus(c+8,"ALUControl", false,-1, 3,0);
    tracep->declBus(c+10,"DataType", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("m ");
    tracep->declBus(c+61,"op", false,-1, 6,0);
    tracep->declBus(c+14,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+64,"Branch", false,-1);
    tracep->declBit(c+16,"ResultSrc", false,-1);
    tracep->declBit(c+15,"MemWrite", false,-1);
    tracep->declBit(c+7,"ALUSrc", false,-1);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+65,"ALUOp", false,-1, 1,0);
    tracep->declBit(c+11,"J", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("myPC ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+87,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+2,"instr", false,-1, 31,0);
    tracep->declBus(c+13,"next_PC", false,-1, 31,0);
    tracep->declBus(c+67,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("pcReg ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+67,"PC", false,-1, 31,0);
    tracep->declBus(c+13,"pc_alu", false,-1, 31,0);
    tracep->declBus(c+13,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+68,"alt_PC", false,-1, 31,0);
    tracep->declBus(c+69,"next_PC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcRom ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+93,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"PC", false,-1, 31,0);
    tracep->declBus(c+2,"instr", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sign_extend ");
    tracep->declBus(c+70,"imm", false,-1, 31,7);
    tracep->declBus(c+14,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+12,"ImmExt", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("top_dataram ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+87,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+75,"clk", false,-1);
    tracep->declBit(c+76,"WE", false,-1);
    tracep->declBus(c+77,"A", false,-1, 31,0);
    tracep->declBus(c+78,"WD", false,-1, 31,0);
    tracep->declBit(c+79,"ResultSrc", false,-1);
    tracep->declBus(c+80,"Result", false,-1, 31,0);
    tracep->declBus(c+94,"RD", false,-1, 31,0);
    tracep->pushNamePrefix("dataram ");
    tracep->declBus(c+87,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+87,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+93,"BYTE_WIDTH", false,-1, 31,0);
    tracep->declBit(c+75,"clk", false,-1);
    tracep->declBit(c+76,"WE", false,-1);
    tracep->declBus(c+81,"dataType", false,-1, 1,0);
    tracep->declBus(c+78,"A", false,-1, 31,0);
    tracep->declBus(c+94,"WD", false,-1, 31,0);
    tracep->declBus(c+82,"RD", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+83+i*1,"ram_array", true,(i+-1), 7,0);
    }
    tracep->declBus(c+85,"byteAssign", false,-1, 7,0);
    tracep->declBus(c+86,"halfwordAssign", false,-1, 15,0);
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
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__RegWrite));
    bufp->fullIData(oldp+2,((((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
                              << 0x18U) | vlSelf->__VdfgTmp_h899fe6da__0)),32);
    bufp->fullBit(oldp+3,(((IData)(vlSelf->top__DOT__EQ) 
                           & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))));
    bufp->fullCData(oldp+4,((0x1fU & (vlSelf->__VdfgTmp_h899fe6da__0 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+5,(((0x10U & ((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
                                       << 4U)) | (0xfU 
                                                  & (vlSelf->__VdfgTmp_h899fe6da__0 
                                                     >> 0x14U)))),5);
    bufp->fullCData(oldp+6,((0x1fU & ((IData)(vlSelf->__VdfgTmp_h557ad426__0) 
                                      >> 7U))),5);
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__ALUSrc));
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__ALU_ctrl),4);
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__EQ));
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__DataType),2);
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__J));
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullIData(oldp+13,(((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC)),32);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__ImmSrc),2);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__MemWrite));
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__ResultSrc));
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__ALU__DOT__rd1),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__ALU__DOT__rd2),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__ALU__DOT__ALUOp2),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__ALU__DOT__ALUout),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__ALU__DOT__ReadData),32);
    bufp->fullIData(oldp+22,(((IData)(vlSelf->top__DOT__ResultSrc)
                               ? vlSelf->top__DOT__ALU__DOT__ReadData
                               : vlSelf->top__DOT__ALU__DOT__ALUout)),32);
    bufp->fullIData(oldp+23,(((IData)(vlSelf->top__DOT__J)
                               ? ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC)
                               : ((IData)(vlSelf->top__DOT__ResultSrc)
                                   ? vlSelf->top__DOT__ALU__DOT__ReadData
                                   : vlSelf->top__DOT__ALU__DOT__ALUout))),32);
    bufp->fullIData(oldp+24,((0x1ffffU & vlSelf->top__DOT__ALU__DOT__ALUout)),32);
    bufp->fullCData(oldp+25,(vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[0]),8);
    bufp->fullCData(oldp+26,(vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[1]),8);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign),8);
    bufp->fullSData(oldp+28,(vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign),16);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[0]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[1]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[2]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[3]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[4]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[5]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[6]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[7]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[8]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[9]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[10]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[11]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[12]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[13]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[14]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[15]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[16]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[17]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[18]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[19]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[20]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[21]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[22]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[23]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[24]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[25]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[26]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[27]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[28]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[29]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[30]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[31]),32);
    bufp->fullCData(oldp+61,((0x7fU & (IData)(vlSelf->__VdfgTmp_h9436ee9b__0))),7);
    bufp->fullCData(oldp+62,((7U & ((IData)(vlSelf->__VdfgTmp_h255a7f46__0) 
                                    >> 4U))),3);
    bufp->fullBit(oldp+63,((1U & ((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
                                  >> 6U))));
    bufp->fullBit(oldp+64,(vlSelf->top__DOT__control_unit__DOT__Branch));
    bufp->fullCData(oldp+65,(vlSelf->top__DOT__control_unit__DOT__ALUOp),2);
    bufp->fullBit(oldp+66,((1U & ((IData)(vlSelf->__VdfgTmp_h9436ee9b__0) 
                                  >> 5U))));
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__myPC__DOT__PC),32);
    bufp->fullIData(oldp+68,((vlSelf->top__DOT__ImmOp 
                              + vlSelf->top__DOT__myPC__DOT__PC)),32);
    bufp->fullIData(oldp+69,((((IData)(vlSelf->top__DOT__EQ) 
                               & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))
                               ? (vlSelf->top__DOT__ImmOp 
                                  + vlSelf->top__DOT__myPC__DOT__PC)
                               : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC))),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT____Vcellinp__sign_extend__imm),25);
    bufp->fullBit(oldp+71,(vlSelf->trigger));
    bufp->fullBit(oldp+72,(vlSelf->top__02Eclk));
    bufp->fullBit(oldp+73,(vlSelf->rst));
    bufp->fullIData(oldp+74,(vlSelf->a0),32);
    bufp->fullBit(oldp+75,(vlSelf->top_dataram__02Eclk));
    bufp->fullBit(oldp+76,(vlSelf->WE));
    bufp->fullIData(oldp+77,(vlSelf->A),32);
    bufp->fullIData(oldp+78,(vlSelf->WD),32);
    bufp->fullBit(oldp+79,(vlSelf->ResultSrc));
    bufp->fullIData(oldp+80,(vlSelf->Result),32);
    bufp->fullCData(oldp+81,((3U & vlSelf->A)),2);
    bufp->fullIData(oldp+82,(vlSelf->top_dataram__DOT__dataram__DOT__RD),32);
    bufp->fullCData(oldp+83,(vlSelf->top_dataram__DOT__dataram__DOT__ram_array[0]),8);
    bufp->fullCData(oldp+84,(vlSelf->top_dataram__DOT__dataram__DOT__ram_array[1]),8);
    bufp->fullCData(oldp+85,(vlSelf->top_dataram__DOT__dataram__DOT__byteAssign),8);
    bufp->fullSData(oldp+86,(vlSelf->top_dataram__DOT__dataram__DOT__halfwordAssign),16);
    bufp->fullIData(oldp+87,(0x20U),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__write_data),32);
    bufp->fullSData(oldp+89,(vlSelf->top__DOT__imm_imm),12);
    bufp->fullSData(oldp+90,(vlSelf->top__DOT__imm_branch),13);
    bufp->fullIData(oldp+91,(5U),32);
    bufp->fullIData(oldp+92,(0x11U),32);
    bufp->fullIData(oldp+93,(8U),32);
    bufp->fullIData(oldp+94,(vlSelf->top_dataram__DOT__RD),32);
}
