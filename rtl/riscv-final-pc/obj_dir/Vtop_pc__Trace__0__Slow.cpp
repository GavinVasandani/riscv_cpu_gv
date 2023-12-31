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
    tracep->declBus(c+2,"jalr_PC", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"J", false,-1, 1,0);
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBit(c+6,"rst", false,-1);
    tracep->declBus(c+7,"instr", false,-1, 31,0);
    tracep->declBus(c+8,"next_PC", false,-1, 31,0);
    tracep->pushNamePrefix("top_pc ");
    tracep->declBus(c+13,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+2,"jalr_PC", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"J", false,-1, 1,0);
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBit(c+6,"rst", false,-1);
    tracep->declBus(c+7,"instr", false,-1, 31,0);
    tracep->declBus(c+8,"next_PC", false,-1, 31,0);
    tracep->declBus(c+9,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("pcReg ");
    tracep->declBus(c+13,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+2,"jalr_PC", false,-1, 31,0);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"J", false,-1, 1,0);
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBit(c+6,"rst", false,-1);
    tracep->declBus(c+9,"PC", false,-1, 31,0);
    tracep->declBus(c+8,"pc_alu", false,-1, 31,0);
    tracep->declBus(c+8,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+10,"alt_PC", false,-1, 31,0);
    tracep->declBit(c+11,"PCsrc_inter", false,-1);
    tracep->declBus(c+12,"next_PC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcRom ");
    tracep->declBus(c+13,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+14,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"PC", false,-1, 31,0);
    tracep->declBus(c+7,"instr", false,-1, 31,0);
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
    bufp->fullIData(oldp+2,(vlSelf->jalr_PC),32);
    bufp->fullBit(oldp+3,(vlSelf->PCsrc));
    bufp->fullCData(oldp+4,(vlSelf->J),2);
    bufp->fullBit(oldp+5,(vlSelf->clk));
    bufp->fullBit(oldp+6,(vlSelf->rst));
    bufp->fullIData(oldp+7,(vlSelf->instr),32);
    bufp->fullIData(oldp+8,(vlSelf->next_PC),32);
    bufp->fullIData(oldp+9,(vlSelf->top_pc__DOT__PC),32);
    bufp->fullIData(oldp+10,((vlSelf->ImmOp + vlSelf->top_pc__DOT__PC)),32);
    bufp->fullBit(oldp+11,((1U & ((IData)(vlSelf->J) 
                                  | (IData)(vlSelf->PCsrc)))));
    bufp->fullIData(oldp+12,(((2U & (IData)(vlSelf->J))
                               ? vlSelf->jalr_PC : 
                              ((1U & ((IData)(vlSelf->J) 
                                      | (IData)(vlSelf->PCsrc)))
                                ? (vlSelf->ImmOp + vlSelf->top_pc__DOT__PC)
                                : vlSelf->next_PC))),32);
    bufp->fullIData(oldp+13,(0x20U),32);
    bufp->fullIData(oldp+14,(8U),32);
}
