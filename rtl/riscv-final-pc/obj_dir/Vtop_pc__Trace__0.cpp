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
    bufp->chgIData(oldp+1,(vlSelf->jalr_PC),32);
    bufp->chgBit(oldp+2,(vlSelf->PCsrc));
    bufp->chgCData(oldp+3,(vlSelf->J),2);
    bufp->chgBit(oldp+4,(vlSelf->clk));
    bufp->chgBit(oldp+5,(vlSelf->rst));
    bufp->chgIData(oldp+6,(vlSelf->instr),32);
    bufp->chgIData(oldp+7,(vlSelf->next_PC),32);
    bufp->chgIData(oldp+8,(vlSelf->top_pc__DOT__PC),32);
    bufp->chgIData(oldp+9,((vlSelf->ImmOp + vlSelf->top_pc__DOT__PC)),32);
    bufp->chgBit(oldp+10,((1U & ((IData)(vlSelf->J) 
                                 | (IData)(vlSelf->PCsrc)))));
    bufp->chgIData(oldp+11,(((2U & (IData)(vlSelf->J))
                              ? vlSelf->jalr_PC : (
                                                   (1U 
                                                    & ((IData)(vlSelf->J) 
                                                       | (IData)(vlSelf->PCsrc)))
                                                    ? 
                                                   (vlSelf->ImmOp 
                                                    + vlSelf->top_pc__DOT__PC)
                                                    : vlSelf->next_PC))),32);
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
