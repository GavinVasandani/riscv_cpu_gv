// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_pc__Syms.h"


VL_ATTR_COLD void Vtop_pc___024root__trace_init_sub__TOP__0(Vtop_pc___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBit(c+3,"clk", false,-1);
    tracep->declBit(c+4,"rst", false,-1);
    tracep->declBus(c+5,"instr", false,-1, 31,0);
    tracep->pushNamePrefix("top_pc ");
    tracep->declBus(c+11,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+12,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBit(c+3,"clk", false,-1);
    tracep->declBit(c+4,"rst", false,-1);
    tracep->declBus(c+5,"instr", false,-1, 31,0);
    tracep->declBus(c+6,"internalImmOp", false,-1, 11,0);
    tracep->declBus(c+7,"PC", false,-1, 11,0);
    tracep->pushNamePrefix("pcReg ");
    tracep->declBus(c+11,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+6,"ImmOp", false,-1, 11,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBit(c+3,"clk", false,-1);
    tracep->declBit(c+4,"rst", false,-1);
    tracep->declBus(c+7,"PC", false,-1, 11,0);
    tracep->declBus(c+8,"branch_PC", false,-1, 11,0);
    tracep->declBus(c+9,"inc_PC", false,-1, 11,0);
    tracep->declBus(c+10,"next_PC", false,-1, 11,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcRom ");
    tracep->declBus(c+11,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+12,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+7,"PC", false,-1, 11,0);
    tracep->declBus(c+5,"instr", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop_pc___024root__trace_init_top(Vtop_pc___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_init_top\n"); );
    // Body
    Vtop_pc___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop_pc___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_pc___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_pc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop_pc___024root__trace_register(Vtop_pc___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop_pc___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop_pc___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop_pc___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop_pc___024root__trace_full_sub_0(Vtop_pc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_pc___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_full_top_0\n"); );
    // Init
    Vtop_pc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_pc___024root*>(voidSelf);
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop_pc___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_pc___024root__trace_full_sub_0(Vtop_pc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ImmOp),32);
    bufp->fullBit(oldp+2,(vlSelf->PCsrc));
    bufp->fullBit(oldp+3,(vlSelf->clk));
    bufp->fullBit(oldp+4,(vlSelf->rst));
    bufp->fullIData(oldp+5,(vlSelf->instr),32);
    bufp->fullSData(oldp+6,((0xfffU & vlSelf->ImmOp)),12);
    bufp->fullSData(oldp+7,(vlSelf->top_pc__DOT__PC),12);
    bufp->fullSData(oldp+8,((0xfffU & ((IData)(vlSelf->top_pc__DOT__PC) 
                                       + vlSelf->ImmOp))),12);
    bufp->fullSData(oldp+9,((0xfffU & ((IData)(4U) 
                                       + (IData)(vlSelf->top_pc__DOT__PC)))),12);
    bufp->fullSData(oldp+10,((0xfffU & ((IData)(vlSelf->PCsrc)
                                         ? ((IData)(vlSelf->top_pc__DOT__PC) 
                                            + vlSelf->ImmOp)
                                         : ((IData)(4U) 
                                            + (IData)(vlSelf->top_pc__DOT__PC))))),12);
    bufp->fullIData(oldp+11,(0xcU),32);
    bufp->fullIData(oldp+12,(8U),32);
    bufp->fullIData(oldp+13,(0x20U),32);
}
