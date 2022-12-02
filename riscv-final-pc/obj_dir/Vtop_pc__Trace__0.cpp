// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_pc__Syms.h"


void Vtop_pc___024root__trace_chg_sub_0(Vtop_pc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_pc___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_chg_top_0\n"); );
    // Init
    Vtop_pc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_pc___024root*>(voidSelf);
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_pc___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_pc___024root__trace_chg_sub_0(Vtop_pc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->ImmOp),32);
    bufp->chgBit(oldp+1,(vlSelf->PCsrc));
    bufp->chgBit(oldp+2,(vlSelf->clk));
    bufp->chgBit(oldp+3,(vlSelf->rst));
    bufp->chgCData(oldp+4,(vlSelf->instr),8);
    bufp->chgSData(oldp+5,((0xfffU & vlSelf->ImmOp)),12);
    bufp->chgSData(oldp+6,(vlSelf->top_pc__DOT__PC),12);
    bufp->chgSData(oldp+7,((0xfffU & ((IData)(vlSelf->top_pc__DOT__PC) 
                                      + vlSelf->ImmOp))),12);
    bufp->chgSData(oldp+8,((0xfffU & ((IData)(4U) + (IData)(vlSelf->top_pc__DOT__PC)))),12);
    bufp->chgSData(oldp+9,((0xfffU & ((IData)(vlSelf->PCsrc)
                                       ? ((IData)(vlSelf->top_pc__DOT__PC) 
                                          + vlSelf->ImmOp)
                                       : ((IData)(4U) 
                                          + (IData)(vlSelf->top_pc__DOT__PC))))),12);
    bufp->chgIData(oldp+10,(((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                              [vlSelf->top_pc__DOT__PC] 
                              << 0x18U) | ((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->top_pc__DOT__PC)))] 
                                            << 0x10U) 
                                           | ((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + (IData)(vlSelf->top_pc__DOT__PC)))] 
                                               << 8U) 
                                              | (IData)(vlSelf->instr))))),32);
}

void Vtop_pc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root__trace_cleanup\n"); );
    // Init
    Vtop_pc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_pc___024root*>(voidSelf);
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
