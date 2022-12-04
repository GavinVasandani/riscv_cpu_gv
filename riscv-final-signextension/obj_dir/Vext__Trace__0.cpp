// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vext__Syms.h"


void Vext___024root__trace_chg_sub_0(Vext___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vext___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root__trace_chg_top_0\n"); );
    // Init
    Vext___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vext___024root*>(voidSelf);
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vext___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vext___024root__trace_chg_sub_0(Vext___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgSData(oldp+0,(vlSelf->sign_ext__DOT__imm_branch),13);
    }
    bufp->chgBit(oldp+1,(vlSelf->clk));
    bufp->chgIData(oldp+2,(vlSelf->inst),32);
    bufp->chgBit(oldp+3,(vlSelf->ImmSrc));
    bufp->chgIData(oldp+4,(vlSelf->ImmOp),32);
    bufp->chgIData(oldp+5,(vlSelf->rem),32);
    bufp->chgSData(oldp+6,((vlSelf->inst >> 0x14U)),12);
}

void Vext___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root__trace_cleanup\n"); );
    // Init
    Vext___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vext___024root*>(voidSelf);
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
}
