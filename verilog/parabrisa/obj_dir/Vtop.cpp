// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__clk_3,0,0);
    // Body
    __Vdly__top__DOT__clk_3 = vlTOPp->top__DOT__clk_3;
    // ALWAYS at top.sv:38
    __Vdly__top__DOT__clk_3 = (1U & (~ (IData)(vlTOPp->top__DOT__clk_3)));
    vlTOPp->top__DOT__clk_3 = __Vdly__top__DOT__clk_3;
}

VL_INLINE_OPT void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.sv:30
    vlTOPp->top__DOT__reset = (1U & ((IData)(vlTOPp->SWI) 
				     >> 7U));
    // ALWAYS at top.sv:125
    vlTOPp->LED = ((0x7fU & (IData)(vlTOPp->LED)) | 
		   ((IData)(vlTOPp->top__DOT__clk_3) 
		    << 7U));
    vlTOPp->LED = ((0xfcU & (IData)(vlTOPp->LED)) | (IData)(vlTOPp->top__DOT__state));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__state,1,0);
    VL_SIG8(__Vdly__top__DOT__contadorGotas,7,0);
    VL_SIG16(__Vdly__top__DOT__contador3,15,0);
    VL_SIG16(__Vdly__top__DOT__contador5,15,0);
    // Body
    __Vdly__top__DOT__contador3 = vlTOPp->top__DOT__contador3;
    __Vdly__top__DOT__contador5 = vlTOPp->top__DOT__contador5;
    __Vdly__top__DOT__contadorGotas = vlTOPp->top__DOT__contadorGotas;
    __Vdly__top__DOT__state = vlTOPp->top__DOT__state;
    // ALWAYS at top.sv:44
    if (vlTOPp->top__DOT__reset) {
	__Vdly__top__DOT__state = 0U;
	__Vdly__top__DOT__contador3 = 0U;
	__Vdly__top__DOT__contador5 = 0U;
    } else {
	if (((3U <= (IData)(vlTOPp->top__DOT__contadorGotas)) 
	     & (6U > (IData)(vlTOPp->top__DOT__contadorGotas)))) {
	    __Vdly__top__DOT__contador3 = (0xffffU 
					   & ((IData)(1U) 
					      + (IData)(vlTOPp->top__DOT__contador3)));
	    __Vdly__top__DOT__contador5 = 0U;
	} else {
	    if ((5U <= (IData)(vlTOPp->top__DOT__contadorGotas))) {
		__Vdly__top__DOT__contador5 = (0xffffU 
					       & ((IData)(1U) 
						  + (IData)(vlTOPp->top__DOT__contador5)));
		__Vdly__top__DOT__contador3 = (0xffffU 
					       & ((IData)(1U) 
						  + (IData)(vlTOPp->top__DOT__contador3)));
	    } else {
		__Vdly__top__DOT__contador3 = 0U;
		__Vdly__top__DOT__contador5 = 0U;
	    }
	}
	if ((0U == (IData)(vlTOPp->top__DOT__state))) {
	    __Vdly__top__DOT__state = (((3U <= (IData)(vlTOPp->top__DOT__contador3)) 
					& (2U > (IData)(vlTOPp->top__DOT__contador5)))
				        ? 1U : ((2U 
						 <= (IData)(vlTOPp->top__DOT__contador5))
						 ? 2U
						 : 0U));
	} else {
	    if ((1U == (IData)(vlTOPp->top__DOT__state))) {
		if ((3U > (IData)(vlTOPp->top__DOT__contadorGotas))) {
		    __Vdly__top__DOT__state = 0U;
		    __Vdly__top__DOT__contador3 = 0U;
		    __Vdly__top__DOT__contador5 = 0U;
		} else {
		    if ((2U <= (IData)(vlTOPp->top__DOT__contador5))) {
			__Vdly__top__DOT__state = 2U;
		    } else {
			if (((6U > (IData)(vlTOPp->top__DOT__contadorGotas)) 
			     & (3U <= (IData)(vlTOPp->top__DOT__contadorGotas)))) {
			    __Vdly__top__DOT__contador5 = 0U;
			    __Vdly__top__DOT__state = 1U;
			} else {
			    if ((4U > (IData)(vlTOPp->top__DOT__contadorGotas))) {
				__Vdly__top__DOT__state = 0U;
				__Vdly__top__DOT__contador3 = 0U;
			    }
			}
		    }
		}
	    } else {
		if ((2U == (IData)(vlTOPp->top__DOT__state))) {
		    if ((4U > (IData)(vlTOPp->top__DOT__contadorGotas))) {
			__Vdly__top__DOT__state = 0U;
			__Vdly__top__DOT__contador3 = 0U;
			__Vdly__top__DOT__contador5 = 0U;
		    } else {
			if (((3U <= (IData)(vlTOPp->top__DOT__contadorGotas)) 
			     & (6U > (IData)(vlTOPp->top__DOT__contadorGotas)))) {
			    __Vdly__top__DOT__state = 1U;
			    __Vdly__top__DOT__contador5 = 0U;
			} else {
			    if ((5U < (IData)(vlTOPp->top__DOT__contadorGotas))) {
				__Vdly__top__DOT__state = 2U;
			    }
			}
		    }
		}
	    }
	}
	__Vdly__top__DOT__contadorGotas = (0xffU & 
					   (((((((1U 
						  & (IData)(vlTOPp->SWI)) 
						 + 
						 (1U 
						  & ((IData)(vlTOPp->SWI) 
						     >> 1U))) 
						+ (1U 
						   & ((IData)(vlTOPp->SWI) 
						      >> 2U))) 
					       + (1U 
						  & ((IData)(vlTOPp->SWI) 
						     >> 3U))) 
					      + (1U 
						 & ((IData)(vlTOPp->SWI) 
						    >> 4U))) 
					     + (1U 
						& ((IData)(vlTOPp->SWI) 
						   >> 5U))) 
					    + (1U & 
					       ((IData)(vlTOPp->SWI) 
						>> 6U))));
    }
    vlTOPp->top__DOT__contadorGotas = __Vdly__top__DOT__contadorGotas;
    vlTOPp->top__DOT__contador3 = __Vdly__top__DOT__contador3;
    vlTOPp->top__DOT__contador5 = __Vdly__top__DOT__contador5;
    vlTOPp->top__DOT__state = __Vdly__top__DOT__state;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_2) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_2)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__clk_3) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk_2 = vlTOPp->clk_2;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3 
	= vlTOPp->__VinpClk__TOP__top__DOT__clk_3;
    vlTOPp->__VinpClk__TOP__top__DOT__clk_3 = vlTOPp->top__DOT__clk_3;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__clk_3 ^ vlTOPp->__Vchglast__TOP__top__DOT__clk_3));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__clk_3 ^ vlTOPp->__Vchglast__TOP__top__DOT__clk_3))) VL_DBG_MSGF("        CHANGE: top.sv:21: top.clk_3\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__clk_3 = vlTOPp->top__DOT__clk_3;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_2 & 0xfeU))) {
	Verilated::overWidthError("clk_2");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk_2 = VL_RAND_RESET_I(1);
    SWI = VL_RAND_RESET_I(8);
    LED = VL_RAND_RESET_I(8);
    SEG = VL_RAND_RESET_I(8);
    lcd_a = VL_RAND_RESET_Q(64);
    lcd_b = VL_RAND_RESET_Q(64);
    lcd_instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    lcd_registrador[__Vi0] = VL_RAND_RESET_I(8);
    }}
    lcd_pc = VL_RAND_RESET_I(8);
    lcd_SrcA = VL_RAND_RESET_I(8);
    lcd_SrcB = VL_RAND_RESET_I(8);
    lcd_ALUResult = VL_RAND_RESET_I(8);
    lcd_Result = VL_RAND_RESET_I(8);
    lcd_WriteData = VL_RAND_RESET_I(8);
    lcd_ReadData = VL_RAND_RESET_I(8);
    lcd_MemWrite = VL_RAND_RESET_I(1);
    lcd_Branch = VL_RAND_RESET_I(1);
    lcd_MemtoReg = VL_RAND_RESET_I(1);
    lcd_RegWrite = VL_RAND_RESET_I(1);
    top__DOT__state = VL_RAND_RESET_I(2);
    top__DOT__reset = VL_RAND_RESET_I(1);
    top__DOT__clk_3 = VL_RAND_RESET_I(1);
    top__DOT__contadorGotas = VL_RAND_RESET_I(8);
    top__DOT__contador3 = VL_RAND_RESET_I(16);
    top__DOT__contador5 = VL_RAND_RESET_I(16);
    __VinpClk__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk_2 = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
}
