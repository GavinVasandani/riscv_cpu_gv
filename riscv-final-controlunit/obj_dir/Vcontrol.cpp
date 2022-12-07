// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontrol.h"
#include "Vcontrol__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcontrol::Vcontrol(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontrol__Syms(contextp(), _vcname__, this)}
    , op{vlSymsp->TOP.op}
    , funct3{vlSymsp->TOP.funct3}
    , funct75{vlSymsp->TOP.funct75}
    , Zero{vlSymsp->TOP.Zero}
    , PCSrc{vlSymsp->TOP.PCSrc}
    , ResultSrc{vlSymsp->TOP.ResultSrc}
    , MemWrite{vlSymsp->TOP.MemWrite}
    , ALUControl{vlSymsp->TOP.ALUControl}
    , ALUSrc{vlSymsp->TOP.ALUSrc}
    , ImmSrc{vlSymsp->TOP.ImmSrc}
    , RegWrite{vlSymsp->TOP.RegWrite}
    , DataType{vlSymsp->TOP.DataType}
    , J{vlSymsp->TOP.J}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontrol::Vcontrol(const char* _vcname__)
    : Vcontrol(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontrol::~Vcontrol() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcontrol___024root___eval_debug_assertions(Vcontrol___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol___024root___eval_static(Vcontrol___024root* vlSelf);
void Vcontrol___024root___eval_initial(Vcontrol___024root* vlSelf);
void Vcontrol___024root___eval_settle(Vcontrol___024root* vlSelf);
void Vcontrol___024root___eval(Vcontrol___024root* vlSelf);

void Vcontrol::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontrol___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcontrol___024root___eval_static(&(vlSymsp->TOP));
        Vcontrol___024root___eval_initial(&(vlSymsp->TOP));
        Vcontrol___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcontrol___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
}

//============================================================
// Events and timing
bool Vcontrol::eventsPending() { return false; }

uint64_t Vcontrol::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcontrol::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcontrol___024root___eval_final(Vcontrol___024root* vlSelf);

VL_ATTR_COLD void Vcontrol::final() {
    Vcontrol___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontrol::hierName() const { return vlSymsp->name(); }
const char* Vcontrol::modelName() const { return "Vcontrol"; }
unsigned Vcontrol::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcontrol::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcontrol___024root__trace_init_top(Vcontrol___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcontrol___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol___024root*>(voidSelf);
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcontrol___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcontrol___024root__trace_register(Vcontrol___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcontrol::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcontrol::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcontrol___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
