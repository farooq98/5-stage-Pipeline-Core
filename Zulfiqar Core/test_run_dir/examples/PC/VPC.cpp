// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPC.h for the primary calling header

#include "VPC.h"               // For This
#include "VPC__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VPC) {
    VPC__Syms* __restrict vlSymsp = __VlSymsp = new VPC__Syms(this, name());
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VPC::__Vconfigure(VPC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VPC::~VPC() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VPC::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPC::eval\n"); );
    VPC__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VPC::_eval_initial_loop(VPC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VPC::_sequent__TOP__1(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_sequent__TOP__1\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at PC.v:44
    vlTOPp->PC__DOT__reg__024 = ((IData)(vlTOPp->reset)
				  ? 0U : vlTOPp->io_input);
    vlTOPp->io_pc4 = ((IData)(4U) + vlTOPp->PC__DOT__reg__024);
    vlTOPp->io_pc = vlTOPp->PC__DOT__reg__024;
}

void VPC::_settle__TOP__2(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_settle__TOP__2\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_pc4 = ((IData)(4U) + vlTOPp->PC__DOT__reg__024);
    vlTOPp->io_pc = vlTOPp->PC__DOT__reg__024;
}

void VPC::_eval(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_eval\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VPC::_eval_initial(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_eval_initial\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPC::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::final\n"); );
    // Variables
    VPC__Syms* __restrict vlSymsp = this->__VlSymsp;
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPC::_eval_settle(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_eval_settle\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VPC::_change_request(VPC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_change_request\n"); );
    VPC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VPC::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG

void VPC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input = VL_RAND_RESET_I(32);
    io_pc4 = VL_RAND_RESET_I(32);
    io_pc = VL_RAND_RESET_I(32);
    PC__DOT__reg__024 = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
