// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol__Syms.h"


VL_ATTR_COLD void Vcontrol___024root__trace_init_sub__TOP__0(Vcontrol___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"op", false,-1, 6,0);
    tracep->declBus(c+2,"funct3", false,-1, 2,0);
    tracep->declBit(c+3,"funct75", false,-1);
    tracep->declBit(c+4,"Zero", false,-1);
    tracep->declBit(c+5,"PCSrc", false,-1);
    tracep->declBit(c+6,"ResultSrc", false,-1);
    tracep->declBit(c+7,"MemWrite", false,-1);
    tracep->declBus(c+8,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBus(c+10,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+11,"RegWrite", false,-1);
    tracep->declBus(c+12,"DataType", false,-1, 1,0);
    tracep->declBit(c+13,"J", false,-1);
    tracep->pushNamePrefix("control ");
    tracep->declBus(c+1,"op", false,-1, 6,0);
    tracep->declBus(c+2,"funct3", false,-1, 2,0);
    tracep->declBit(c+3,"funct75", false,-1);
    tracep->declBit(c+4,"Zero", false,-1);
    tracep->declBit(c+5,"PCSrc", false,-1);
    tracep->declBit(c+6,"ResultSrc", false,-1);
    tracep->declBit(c+7,"MemWrite", false,-1);
    tracep->declBus(c+8,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBus(c+10,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+11,"RegWrite", false,-1);
    tracep->declBus(c+12,"DataType", false,-1, 1,0);
    tracep->declBit(c+13,"J", false,-1);
    tracep->declBit(c+14,"Branch", false,-1);
    tracep->declBus(c+15,"ALUOp", false,-1, 1,0);
    tracep->pushNamePrefix("a ");
    tracep->declBus(c+2,"funct3", false,-1, 2,0);
    tracep->declBit(c+3,"funct75", false,-1);
    tracep->declBus(c+15,"ALUOp", false,-1, 1,0);
    tracep->declBus(c+8,"ALUControl", false,-1, 3,0);
    tracep->declBus(c+12,"DataType", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("m ");
    tracep->declBus(c+1,"op", false,-1, 6,0);
    tracep->declBus(c+10,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+14,"Branch", false,-1);
    tracep->declBit(c+6,"ResultSrc", false,-1);
    tracep->declBit(c+7,"MemWrite", false,-1);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBit(c+11,"RegWrite", false,-1);
    tracep->declBus(c+15,"ALUOp", false,-1, 1,0);
    tracep->declBit(c+13,"J", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vcontrol___024root__trace_init_top(Vcontrol___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_init_top\n"); );
    // Body
    Vcontrol___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcontrol___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcontrol___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcontrol___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcontrol___024root__trace_register(Vcontrol___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcontrol___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcontrol___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcontrol___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcontrol___024root__trace_full_sub_0(Vcontrol___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcontrol___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_full_top_0\n"); );
    // Init
    Vcontrol___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol___024root*>(voidSelf);
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcontrol___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcontrol___024root__trace_full_sub_0(Vcontrol___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->op),7);
    bufp->fullCData(oldp+2,(vlSelf->funct3),3);
    bufp->fullBit(oldp+3,(vlSelf->funct75));
    bufp->fullBit(oldp+4,(vlSelf->Zero));
    bufp->fullBit(oldp+5,(vlSelf->PCSrc));
    bufp->fullBit(oldp+6,(vlSelf->ResultSrc));
    bufp->fullBit(oldp+7,(vlSelf->MemWrite));
    bufp->fullCData(oldp+8,(vlSelf->ALUControl),4);
    bufp->fullBit(oldp+9,(vlSelf->ALUSrc));
    bufp->fullCData(oldp+10,(vlSelf->ImmSrc),2);
    bufp->fullBit(oldp+11,(vlSelf->RegWrite));
    bufp->fullCData(oldp+12,(vlSelf->DataType),2);
    bufp->fullBit(oldp+13,(vlSelf->J));
    bufp->fullBit(oldp+14,(vlSelf->control__DOT__Branch));
    bufp->fullCData(oldp+15,(vlSelf->control__DOT__ALUOp),2);
}
