// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol__Syms.h"


void Vcontrol___024root__trace_chg_sub_0(Vcontrol___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcontrol___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_chg_top_0\n"); );
    // Init
    Vcontrol___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol___024root*>(voidSelf);
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcontrol___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcontrol___024root__trace_chg_sub_0(Vcontrol___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->op),7);
    bufp->chgCData(oldp+1,(vlSelf->funct3),3);
    bufp->chgBit(oldp+2,(vlSelf->funct75));
    bufp->chgBit(oldp+3,(vlSelf->Zero));
    bufp->chgBit(oldp+4,(vlSelf->PCSrc));
    bufp->chgBit(oldp+5,(vlSelf->ResultSrc));
    bufp->chgBit(oldp+6,(vlSelf->MemWrite));
    bufp->chgCData(oldp+7,(vlSelf->ALUControl),4);
    bufp->chgBit(oldp+8,(vlSelf->ALUSrc));
    bufp->chgCData(oldp+9,(vlSelf->ImmSrc),2);
    bufp->chgBit(oldp+10,(vlSelf->RegWrite));
    bufp->chgCData(oldp+11,(vlSelf->DataType),2);
    bufp->chgBit(oldp+12,(vlSelf->J));
    bufp->chgBit(oldp+13,(vlSelf->control__DOT__Branch));
    bufp->chgCData(oldp+14,(vlSelf->control__DOT__ALUOp),2);
}

void Vcontrol___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_cleanup\n"); );
    // Init
    Vcontrol___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol___024root*>(voidSelf);
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
