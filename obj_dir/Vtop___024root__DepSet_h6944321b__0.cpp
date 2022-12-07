// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    // Body
    __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelf->top__DOT__DataType))) {
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
                = (0xffU & vlSelf->top__DOT__ALU__DOT__rd2);
            __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1 
                = (0xffU & (vlSelf->top__DOT__ALU__DOT__rd2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1 
                = (1U & vlSelf->top__DOT__ALU__DOT__ALUout);
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2 
                = (0xffU & (vlSelf->top__DOT__ALU__DOT__rd2 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3 
                = (vlSelf->top__DOT__ALU__DOT__rd2 
                   >> 0x18U);
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3 
                = (1U & vlSelf->top__DOT__ALU__DOT__ALUout);
        } else {
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 
                = (0xffU & vlSelf->top__DOT__ALU__DOT__rd2);
            __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
        }
    }
    if (vlSelf->top__DOT__RegWrite) {
        if (VL_LIKELY((0U != (0x1fU & (vlSelf->top__DOT__PC_instr 
                                       >> 7U))))) {
            __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
                = ((IData)(vlSelf->top__DOT__J) ? ((IData)(4U) 
                                                   + vlSelf->top__DOT__myPC__DOT__PC)
                    : ((IData)(vlSelf->top__DOT__ResultSrc)
                        ? vlSelf->top__DOT__ALU__DOT__ReadData
                        : vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
                = (0x1fU & (vlSelf->top__DOT__PC_instr 
                            >> 7U));
        } else {
            VL_WRITEF("Cannot write to register 0.\n");
        }
    }
    if (vlSelf->trigger) {
        __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1 = 1U;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[0x11U] = 1U;
    }
    vlSelf->a0 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [0xaU];
    vlSelf->top__DOT__myPC__DOT__PC = ((IData)(vlSelf->rst)
                                        ? 0U : vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC);
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

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
