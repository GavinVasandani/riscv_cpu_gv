// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h83cfa321__0;
    VlWide<6>/*191:0*/ __Vtemp_hfbf7ff78__0;
    // Body
    VL_WRITEF("Initializing regFile with null values (0).\n");
    __Vtemp_h83cfa321__0[0U] = 0x2e6d656dU;
    __Vtemp_h83cfa321__0[1U] = 0x70757473U;
    __Vtemp_h83cfa321__0[2U] = 0x6c65496eU;
    __Vtemp_h83cfa321__0[3U] = 0x65676669U;
    __Vtemp_h83cfa321__0[4U] = 0x72U;
    VL_READMEM_N(true, 32, 32, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_h83cfa321__0)
                 ,  &(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array)
                 , 0, ~0ULL);
    VL_WRITEF("Register successfully initialized\nLoading rom.\n");
    __Vtemp_hfbf7ff78__0[0U] = 0x2e686578U;
    __Vtemp_hfbf7ff78__0[1U] = 0x65722e73U;
    __Vtemp_hfbf7ff78__0[2U] = 0x6f756e74U;
    __Vtemp_hfbf7ff78__0[3U] = 0x6f672f63U;
    __Vtemp_hfbf7ff78__0[4U] = 0x6d797072U;
    __Vtemp_hfbf7ff78__0[5U] = 0x7372632fU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_hfbf7ff78__0)
                 ,  &(vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array)
                 , 0, ~0ULL);
    VL_WRITEF("Rom successfully loaded.\n");
}

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [0xaU];
    vlSelf->top__DOT__PC_instr = ((vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
                                   [(0xfffU & ((IData)(3U) 
                                               + vlSelf->top__DOT__myPC__DOT__PC))] 
                                   << 0x18U) | ((vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->top__DOT__myPC__DOT__PC))] 
                                                 << 0x10U) 
                                                | ((vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
                                                    [
                                                    (0xfffU 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__myPC__DOT__PC))] 
                                                    << 8U) 
                                                   | vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
                                                   [
                                                   (0xfffU 
                                                    & vlSelf->top__DOT__myPC__DOT__PC)])));
    vlSelf->top__DOT__ALU__DOT__rd1 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [(0x1fU & (vlSelf->top__DOT__PC_instr >> 0xfU))];
    vlSelf->top__DOT__ALU__DOT__rd2 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [(0x1fU & (vlSelf->top__DOT__PC_instr >> 0x14U))];
    if ((0x40U & vlSelf->top__DOT__PC_instr)) {
        if (VL_LIKELY((0x20U & vlSelf->top__DOT__PC_instr))) {
            if (VL_UNLIKELY((0x10U & vlSelf->top__DOT__PC_instr))) {
                VL_WRITEF("MainDecoder error\n");
            } else if ((8U & vlSelf->top__DOT__PC_instr)) {
                if (VL_LIKELY((4U & vlSelf->top__DOT__PC_instr))) {
                    if (VL_LIKELY((2U & vlSelf->top__DOT__PC_instr))) {
                        if (VL_LIKELY((1U & vlSelf->top__DOT__PC_instr))) {
                            vlSelf->top__DOT__RegWrite = 1U;
                            vlSelf->top__DOT__ImmSrc = 3U;
                            vlSelf->top__DOT__MemWrite = 0U;
                            vlSelf->top__DOT__control_unit__DOT__Branch = 0U;
                            vlSelf->top__DOT__J = 1U;
                        } else {
                            VL_WRITEF("MainDecoder error\n");
                        }
                    } else {
                        VL_WRITEF("MainDecoder error\n");
                    }
                } else {
                    VL_WRITEF("MainDecoder error\n");
                }
            } else if (VL_UNLIKELY((4U & vlSelf->top__DOT__PC_instr))) {
                VL_WRITEF("MainDecoder error\n");
            } else if (VL_LIKELY((2U & vlSelf->top__DOT__PC_instr))) {
                if (VL_LIKELY((1U & vlSelf->top__DOT__PC_instr))) {
                    vlSelf->top__DOT__RegWrite = 0U;
                    vlSelf->top__DOT__ImmSrc = 2U;
                    vlSelf->top__DOT__ALUSrc = 0U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT__control_unit__DOT__Branch = 1U;
                    vlSelf->top__DOT__control_unit__DOT__ALUOp = 1U;
                    vlSelf->top__DOT__J = 0U;
                } else {
                    VL_WRITEF("MainDecoder error\n");
                }
            } else {
                VL_WRITEF("MainDecoder error\n");
            }
        } else {
            VL_WRITEF("MainDecoder error\n");
        }
    } else if ((0x20U & vlSelf->top__DOT__PC_instr)) {
        if ((0x10U & vlSelf->top__DOT__PC_instr)) {
            if (VL_UNLIKELY((8U & vlSelf->top__DOT__PC_instr))) {
                VL_WRITEF("MainDecoder error\n");
            } else if (VL_UNLIKELY((4U & vlSelf->top__DOT__PC_instr))) {
                VL_WRITEF("MainDecoder error\n");
            } else if (VL_LIKELY((2U & vlSelf->top__DOT__PC_instr))) {
                if (VL_LIKELY((1U & vlSelf->top__DOT__PC_instr))) {
                    vlSelf->top__DOT__RegWrite = 1U;
                    vlSelf->top__DOT__ALUSrc = 0U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__control_unit__DOT__Branch = 0U;
                    vlSelf->top__DOT__control_unit__DOT__ALUOp = 2U;
                    vlSelf->top__DOT__J = 0U;
                } else {
                    VL_WRITEF("MainDecoder error\n");
                }
            } else {
                VL_WRITEF("MainDecoder error\n");
            }
        } else if (VL_UNLIKELY((8U & vlSelf->top__DOT__PC_instr))) {
            VL_WRITEF("MainDecoder error\n");
        } else if (VL_UNLIKELY((4U & vlSelf->top__DOT__PC_instr))) {
            VL_WRITEF("MainDecoder error\n");
        } else if (VL_LIKELY((2U & vlSelf->top__DOT__PC_instr))) {
            if (VL_LIKELY((1U & vlSelf->top__DOT__PC_instr))) {
                vlSelf->top__DOT__RegWrite = 0U;
                vlSelf->top__DOT__ImmSrc = 1U;
                vlSelf->top__DOT__ALUSrc = 1U;
                vlSelf->top__DOT__MemWrite = 1U;
                vlSelf->top__DOT__control_unit__DOT__Branch = 0U;
                vlSelf->top__DOT__control_unit__DOT__ALUOp = 0U;
                vlSelf->top__DOT__J = 0U;
            } else {
                VL_WRITEF("MainDecoder error\n");
            }
        } else {
            VL_WRITEF("MainDecoder error\n");
        }
    } else if (VL_UNLIKELY((0x10U & vlSelf->top__DOT__PC_instr))) {
        VL_WRITEF("MainDecoder error\n");
    } else if (VL_UNLIKELY((8U & vlSelf->top__DOT__PC_instr))) {
        VL_WRITEF("MainDecoder error\n");
    } else if (VL_UNLIKELY((4U & vlSelf->top__DOT__PC_instr))) {
        VL_WRITEF("MainDecoder error\n");
    } else if (VL_LIKELY((2U & vlSelf->top__DOT__PC_instr))) {
        if (VL_LIKELY((1U & vlSelf->top__DOT__PC_instr))) {
            vlSelf->top__DOT__RegWrite = 1U;
            vlSelf->top__DOT__ImmSrc = 0U;
            vlSelf->top__DOT__ALUSrc = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT__ResultSrc = 1U;
            vlSelf->top__DOT__control_unit__DOT__Branch = 0U;
            vlSelf->top__DOT__control_unit__DOT__ALUOp = 0U;
            vlSelf->top__DOT__J = 0U;
        } else {
            VL_WRITEF("MainDecoder error\n");
        }
    } else {
        VL_WRITEF("MainDecoder error\n");
    }
    if ((0U == (IData)(vlSelf->top__DOT__control_unit__DOT__ALUOp))) {
        vlSelf->top__DOT__ALU_ctrl = 0U;
        if ((2U == (7U & (vlSelf->top__DOT__PC_instr 
                          >> 0xcU)))) {
            vlSelf->top__DOT__DataType = 0U;
        } else if ((0U == (7U & (vlSelf->top__DOT__PC_instr 
                                 >> 0xcU)))) {
            vlSelf->top__DOT__DataType = 1U;
        } else if (VL_LIKELY((1U == (7U & (vlSelf->top__DOT__PC_instr 
                                           >> 0xcU))))) {
            vlSelf->top__DOT__DataType = 1U;
        } else {
            VL_WRITEF("ALUDecoder error\n");
        }
    } else if ((1U == (IData)(vlSelf->top__DOT__control_unit__DOT__ALUOp))) {
        if ((0U == (7U & (vlSelf->top__DOT__PC_instr 
                          >> 0xcU)))) {
            vlSelf->top__DOT__ALU_ctrl = 1U;
        } else if (VL_LIKELY((5U == (7U & (vlSelf->top__DOT__PC_instr 
                                           >> 0xcU))))) {
            vlSelf->top__DOT__ALU_ctrl = 8U;
        } else {
            VL_WRITEF("ALUDecoder error\n");
        }
    } else if ((2U == (IData)(vlSelf->top__DOT__control_unit__DOT__ALUOp))) {
        if ((0x4000U & vlSelf->top__DOT__PC_instr)) {
            vlSelf->top__DOT__ALU_ctrl = ((0x2000U 
                                           & vlSelf->top__DOT__PC_instr)
                                           ? ((0x1000U 
                                               & vlSelf->top__DOT__PC_instr)
                                               ? 2U
                                               : 3U)
                                           : ((0x1000U 
                                               & vlSelf->top__DOT__PC_instr)
                                               ? 6U
                                               : 9U));
        } else if ((0x2000U & vlSelf->top__DOT__PC_instr)) {
            if (VL_UNLIKELY((0x1000U & vlSelf->top__DOT__PC_instr))) {
                VL_WRITEF("ALUDecoder error\n");
            } else {
                vlSelf->top__DOT__ALU_ctrl = 5U;
            }
        } else {
            vlSelf->top__DOT__ALU_ctrl = ((0x1000U 
                                           & vlSelf->top__DOT__PC_instr)
                                           ? 4U : (
                                                   (0x40000000U 
                                                    & vlSelf->top__DOT__PC_instr)
                                                    ? 1U
                                                    : 0U));
        }
    }
    vlSelf->top__DOT__ImmOp = ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                ? ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0x13U) | 
                                       ((0x7f800U & 
                                         (vlSelf->top__DOT__PC_instr 
                                          >> 1U)) | 
                                        ((0x400U & 
                                          (vlSelf->top__DOT__PC_instr 
                                           >> 0xaU)) 
                                         | (0x3ffU 
                                            & (vlSelf->top__DOT__PC_instr 
                                               >> 0x15U)))))
                                    : (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xdU) | 
                                       ((0x1000U & 
                                         (vlSelf->top__DOT__PC_instr 
                                          >> 0x13U)) 
                                        | ((0x800U 
                                            & (vlSelf->top__DOT__PC_instr 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelf->top__DOT__PC_instr 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->top__DOT__PC_instr 
                                                    >> 7U)))))))
                                : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0xfe0U & (vlSelf->top__DOT__PC_instr 
                                                   >> 0x14U)) 
                                        | (0x1fU & 
                                           (vlSelf->top__DOT__PC_instr 
                                            >> 7U))))
                                    : (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->top__DOT__PC_instr 
                                        >> 0x14U))));
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = ((IData)(vlSelf->top__DOT__ALUSrc)
                                           ? vlSelf->top__DOT__ImmOp
                                           : vlSelf->top__DOT__ALU__DOT__rd2);
    if ((8U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if (VL_UNLIKELY((4U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = 0U;
            VL_WRITEF("Instruction not detected.\n");
        } else if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            VL_WRITEF("Instruction not detected.\n");
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = 0U;
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  ^ vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        } else {
            vlSelf->top__DOT__EQ = (vlSelf->top__DOT__ALU__DOT__rd1 
                                    >= vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if ((2U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
                vlSelf->top__DOT__ALU__DOT__ALUout 
                    = ((0x1fU >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        ? (vlSelf->top__DOT__ALU__DOT__rd1 
                           >> vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        : 0U);
                vlSelf->top__DOT__EQ = 0U;
            } else {
                vlSelf->top__DOT__ALU__DOT__ALUout 
                    = ((0x1fU >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        ? (vlSelf->top__DOT__ALU__DOT__rd1 
                           >> vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        : 0U);
                vlSelf->top__DOT__EQ = 0U;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            if ((vlSelf->top__DOT__ALU__DOT__rd1 < vlSelf->top__DOT__ALU__DOT__ALUOp2)) {
                vlSelf->top__DOT__ALU__DOT__ALUout = 1U;
                vlSelf->top__DOT__EQ = 1U;
            } else {
                vlSelf->top__DOT__ALU__DOT__ALUout = 1U;
                vlSelf->top__DOT__EQ = 0U;
            }
        } else {
            vlSelf->top__DOT__ALU__DOT__ALUout = ((0x1fU 
                                                   >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                                                   ? 
                                                  (vlSelf->top__DOT__ALU__DOT__rd1 
                                                   << vlSelf->top__DOT__ALU__DOT__ALUOp2)
                                                   : 0U);
            vlSelf->top__DOT__EQ = 0U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  | vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        } else {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  & vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              - vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = (0U == (vlSelf->top__DOT__ALU__DOT__rd1 
                                       - vlSelf->top__DOT__ALU__DOT__ALUOp2));
    } else {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              + vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = 0U;
    }
    vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC 
        = (((IData)(vlSelf->top__DOT__EQ) & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))
            ? (vlSelf->top__DOT__myPC__DOT__PC + vlSelf->top__DOT__ImmOp)
            : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC));
    if ((0U == (IData)(vlSelf->top__DOT__DataType))) {
        vlSelf->top__DOT__ALU__DOT__ReadData = ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                 [(1U 
                                                   & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                                                 << 0x18U) 
                                                | ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                    [
                                                    (1U 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__ALU__DOT__ALUout))] 
                                                    << 0x10U) 
                                                   | ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                       [
                                                       (1U 
                                                        & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                                                       << 8U) 
                                                      | vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                      [
                                                      (1U 
                                                       & ((IData)(1U) 
                                                          + vlSelf->top__DOT__ALU__DOT__ALUout))])));
    } else if ((1U == (IData)(vlSelf->top__DOT__DataType))) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign 
            = vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
            [(1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout))];
        vlSelf->top__DOT__ALU__DOT__ReadData = (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign) 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign));
    } else if (VL_LIKELY((2U == (IData)(vlSelf->top__DOT__DataType)))) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign 
            = ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                [(1U & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                << 8U) | vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
               [(1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout))]);
        vlSelf->top__DOT__ALU__DOT__ReadData = (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign) 
                                                                >> 0xfU)))) 
                                                 << 0x10U) 
                                                | (IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign));
    } else {
        VL_WRITEF("No dataType selected. Please choose word, byte or halfword.\n");
    }
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PC_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALU_ctrl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__DataType = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__J = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__myPC__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__control_unit__DOT__Branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__control_unit__DOT__ALUOp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALU__DOT__rd1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__rd2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ReadData = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
