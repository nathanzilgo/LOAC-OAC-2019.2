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
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.sv:19
    vlTOPp->SEG = vlTOPp->SWI;
    vlTOPp->lcd_WriteData = vlTOPp->SWI;
    vlTOPp->lcd_pc = 0x12U;
    vlTOPp->lcd_instruction = 0x34567890U;
    vlTOPp->lcd_SrcA = 0xabU;
    vlTOPp->lcd_SrcB = 0xcdU;
    vlTOPp->lcd_ALUResult = 0xefU;
    vlTOPp->lcd_Result = 0x11U;
    vlTOPp->lcd_ReadData = 0x33U;
    vlTOPp->lcd_MemWrite = (1U & (IData)(vlTOPp->SWI));
    vlTOPp->lcd_Branch = (1U & ((IData)(vlTOPp->SWI) 
				>> 1U));
    vlTOPp->lcd_MemtoReg = (1U & ((IData)(vlTOPp->SWI) 
				  >> 2U));
    vlTOPp->lcd_RegWrite = (1U & ((IData)(vlTOPp->SWI) 
				  >> 3U));
    vlTOPp->lcd_registrador[0U] = 0U;
    vlTOPp->lcd_registrador[1U] = 0x11U;
    vlTOPp->lcd_registrador[2U] = 0x22U;
    vlTOPp->lcd_registrador[3U] = 0x33U;
    vlTOPp->lcd_registrador[4U] = 0x44U;
    vlTOPp->lcd_registrador[5U] = 0x55U;
    vlTOPp->lcd_registrador[6U] = 0x66U;
    vlTOPp->lcd_registrador[7U] = 0x77U;
    vlTOPp->lcd_registrador[8U] = 0x88U;
    vlTOPp->lcd_registrador[9U] = 0x99U;
    vlTOPp->lcd_registrador[0xaU] = 0xaaU;
    vlTOPp->lcd_registrador[0xbU] = 0xbbU;
    vlTOPp->lcd_registrador[0xcU] = 0xccU;
    vlTOPp->lcd_registrador[0xdU] = 0xddU;
    vlTOPp->lcd_registrador[0xeU] = 0xeeU;
    vlTOPp->lcd_registrador[0xfU] = 0xffU;
    vlTOPp->lcd_registrador[0x10U] = 0x10U;
    vlTOPp->lcd_registrador[0x11U] = 0x21U;
    vlTOPp->lcd_registrador[0x12U] = 0x32U;
    vlTOPp->lcd_registrador[0x13U] = 0x43U;
    vlTOPp->lcd_registrador[0x14U] = 0x54U;
    vlTOPp->lcd_registrador[0x15U] = 0x65U;
    vlTOPp->lcd_registrador[0x16U] = 0x76U;
    vlTOPp->lcd_registrador[0x17U] = 0x87U;
    vlTOPp->lcd_registrador[0x18U] = 0x98U;
    vlTOPp->lcd_registrador[0x19U] = 0xa9U;
    vlTOPp->lcd_registrador[0x1aU] = 0xbaU;
    vlTOPp->lcd_registrador[0x1bU] = 0xcbU;
    vlTOPp->lcd_registrador[0x1cU] = 0xdcU;
    vlTOPp->lcd_registrador[0x1dU] = 0xedU;
    vlTOPp->lcd_registrador[0x1eU] = 0xfeU;
    vlTOPp->lcd_registrador[0x1fU] = 0xfU;
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.sv:19
    vlTOPp->SEG = vlTOPp->SWI;
    vlTOPp->lcd_WriteData = vlTOPp->SWI;
    vlTOPp->lcd_pc = 0x12U;
    vlTOPp->lcd_instruction = 0x34567890U;
    vlTOPp->lcd_SrcA = 0xabU;
    vlTOPp->lcd_SrcB = 0xcdU;
    vlTOPp->lcd_ALUResult = 0xefU;
    vlTOPp->lcd_Result = 0x11U;
    vlTOPp->lcd_ReadData = 0x33U;
    vlTOPp->lcd_MemWrite = (1U & (IData)(vlTOPp->SWI));
    vlTOPp->lcd_Branch = (1U & ((IData)(vlTOPp->SWI) 
				>> 1U));
    vlTOPp->lcd_MemtoReg = (1U & ((IData)(vlTOPp->SWI) 
				  >> 2U));
    vlTOPp->lcd_RegWrite = (1U & ((IData)(vlTOPp->SWI) 
				  >> 3U));
    vlTOPp->lcd_registrador[0U] = 0U;
    vlTOPp->lcd_registrador[1U] = 0x11U;
    vlTOPp->lcd_registrador[2U] = 0x22U;
    vlTOPp->lcd_registrador[3U] = 0x33U;
    vlTOPp->lcd_registrador[4U] = 0x44U;
    vlTOPp->lcd_registrador[5U] = 0x55U;
    vlTOPp->lcd_registrador[6U] = 0x66U;
    vlTOPp->lcd_registrador[7U] = 0x77U;
    vlTOPp->lcd_registrador[8U] = 0x88U;
    vlTOPp->lcd_registrador[9U] = 0x99U;
    vlTOPp->lcd_registrador[0xaU] = 0xaaU;
    vlTOPp->lcd_registrador[0xbU] = 0xbbU;
    vlTOPp->lcd_registrador[0xcU] = 0xccU;
    vlTOPp->lcd_registrador[0xdU] = 0xddU;
    vlTOPp->lcd_registrador[0xeU] = 0xeeU;
    vlTOPp->lcd_registrador[0xfU] = 0xffU;
    vlTOPp->lcd_registrador[0x10U] = 0x10U;
    vlTOPp->lcd_registrador[0x11U] = 0x21U;
    vlTOPp->lcd_registrador[0x12U] = 0x32U;
    vlTOPp->lcd_registrador[0x13U] = 0x43U;
    vlTOPp->lcd_registrador[0x14U] = 0x54U;
    vlTOPp->lcd_registrador[0x15U] = 0x65U;
    vlTOPp->lcd_registrador[0x16U] = 0x76U;
    vlTOPp->lcd_registrador[0x17U] = 0x87U;
    vlTOPp->lcd_registrador[0x18U] = 0x98U;
    vlTOPp->lcd_registrador[0x19U] = 0xa9U;
    vlTOPp->lcd_registrador[0x1aU] = 0xbaU;
    vlTOPp->lcd_registrador[0x1bU] = 0xcbU;
    vlTOPp->lcd_registrador[0x1cU] = 0xdcU;
    vlTOPp->lcd_registrador[0x1dU] = 0xedU;
    vlTOPp->lcd_registrador[0x1eU] = 0xfeU;
    vlTOPp->lcd_registrador[0x1fU] = 0xfU;
    // ALWAYS at top.sv:63
    vlTOPp->top__DOT__reset = (1U & ((IData)(vlTOPp->SWI) 
				     >> 7U));
    vlTOPp->top__DOT__car0 = (1U & (IData)(vlTOPp->SWI));
    vlTOPp->top__DOT__car1 = (1U & ((IData)(vlTOPp->SWI) 
				    >> 1U));
    // ALWAYS at top.sv:137
    vlTOPp->SEG = ((0x7fU & (IData)(vlTOPp->SEG)) | 
		   ((IData)(vlTOPp->top__DOT__clk_3) 
		    << 7U));
    vlTOPp->LED = ((0xfeU & (IData)(vlTOPp->LED)) | 
		   (1U != (IData)(vlTOPp->top__DOT__estado)));
    vlTOPp->LED = ((0xfdU & (IData)(vlTOPp->LED)) | 
		   ((2U != (IData)(vlTOPp->top__DOT__estado)) 
		    << 1U));
    vlTOPp->lcd_a = ((VL_ULL(0xfffffffffffffff0) & vlTOPp->lcd_a) 
		     | (IData)((IData)(vlTOPp->top__DOT__actual_count0)));
    vlTOPp->lcd_a = ((VL_ULL(0xffffffffffffff0f) & vlTOPp->lcd_a) 
		     | ((QData)((IData)(vlTOPp->top__DOT__actual_count1)) 
			<< 4U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__clk_3,0,0);
    // Body
    __Vdly__top__DOT__clk_3 = vlTOPp->top__DOT__clk_3;
    // ALWAYS at top.sv:59
    __Vdly__top__DOT__clk_3 = (1U & (~ (IData)(vlTOPp->top__DOT__clk_3)));
    vlTOPp->top__DOT__clk_3 = __Vdly__top__DOT__clk_3;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__estado,1,0);
    VL_SIG8(__Vdly__top__DOT__car_count0,3,0);
    VL_SIG8(__Vdly__top__DOT__car_count1,3,0);
    VL_SIG8(__Vdly__top__DOT__actual_count0,3,0);
    VL_SIG8(__Vdly__top__DOT__actual_count1,3,0);
    VL_SIG8(__Vdly__top__DOT__max_count0,3,0);
    VL_SIG8(__Vdly__top__DOT__max_count1,3,0);
    // Body
    __Vdly__top__DOT__car_count0 = vlTOPp->top__DOT__car_count0;
    __Vdly__top__DOT__car_count1 = vlTOPp->top__DOT__car_count1;
    __Vdly__top__DOT__max_count0 = vlTOPp->top__DOT__max_count0;
    __Vdly__top__DOT__max_count1 = vlTOPp->top__DOT__max_count1;
    __Vdly__top__DOT__estado = vlTOPp->top__DOT__estado;
    __Vdly__top__DOT__actual_count0 = vlTOPp->top__DOT__actual_count0;
    __Vdly__top__DOT__actual_count1 = vlTOPp->top__DOT__actual_count1;
    // ALWAYS at top.sv:69
    if (vlTOPp->top__DOT__reset) {
	__Vdly__top__DOT__estado = 0U;
	__Vdly__top__DOT__car_count0 = 0U;
	__Vdly__top__DOT__car_count1 = 0U;
	__Vdly__top__DOT__actual_count0 = 0U;
	__Vdly__top__DOT__actual_count1 = 0U;
	__Vdly__top__DOT__max_count0 = 2U;
	__Vdly__top__DOT__max_count1 = 2U;
    } else {
	if ((0U == (IData)(vlTOPp->top__DOT__estado))) {
	    if ((1U & ((~ (IData)(vlTOPp->top__DOT__car0)) 
		       & (~ (IData)(vlTOPp->top__DOT__car1))))) {
		__Vdly__top__DOT__estado = 0U;
	    } else {
		if (vlTOPp->top__DOT__car0) {
		    __Vdly__top__DOT__estado = 1U;
		} else {
		    if (vlTOPp->top__DOT__car1) {
			__Vdly__top__DOT__estado = 2U;
		    }
		}
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->top__DOT__estado))) {
		if (vlTOPp->top__DOT__car0) {
		    __Vdly__top__DOT__car_count0 = 
			(0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__car_count0)));
		}
		if (((IData)(vlTOPp->top__DOT__actual_count0) 
		     == (IData)(vlTOPp->top__DOT__max_count0))) {
		    __Vdly__top__DOT__max_count0 = 
			(((IData)(vlTOPp->top__DOT__car_count0) 
			  == (IData)(vlTOPp->top__DOT__max_count0))
			  ? 5U : 2U);
		    __Vdly__top__DOT__actual_count0 = 0U;
		    __Vdly__top__DOT__estado = ((IData)(vlTOPp->top__DOT__car1)
						 ? 2U
						 : 0U);
		    __Vdly__top__DOT__car_count0 = 0U;
		} else {
		    __Vdly__top__DOT__actual_count0 
			= (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__actual_count0)));
		}
	    } else {
		if ((2U == (IData)(vlTOPp->top__DOT__estado))) {
		    if (vlTOPp->top__DOT__car1) {
			__Vdly__top__DOT__car_count1 
			    = (0xfU & ((IData)(1U) 
				       + (IData)(vlTOPp->top__DOT__car_count1)));
		    }
		    if (((IData)(vlTOPp->top__DOT__actual_count1) 
			 == (IData)(vlTOPp->top__DOT__max_count1))) {
			__Vdly__top__DOT__max_count1 
			    = (((IData)(vlTOPp->top__DOT__car_count1) 
				== (IData)(vlTOPp->top__DOT__max_count1))
			        ? 5U : 2U);
			__Vdly__top__DOT__actual_count1 = 0U;
			__Vdly__top__DOT__estado = 
			    ((IData)(vlTOPp->top__DOT__car0)
			      ? 2U : 0U);
			__Vdly__top__DOT__car_count1 = 0U;
		    } else {
			__Vdly__top__DOT__actual_count1 
			    = (0xfU & ((IData)(1U) 
				       + (IData)(vlTOPp->top__DOT__actual_count1)));
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__car_count0 = __Vdly__top__DOT__car_count0;
    vlTOPp->top__DOT__max_count0 = __Vdly__top__DOT__max_count0;
    vlTOPp->top__DOT__car_count1 = __Vdly__top__DOT__car_count1;
    vlTOPp->top__DOT__max_count1 = __Vdly__top__DOT__max_count1;
    vlTOPp->top__DOT__estado = __Vdly__top__DOT__estado;
    vlTOPp->top__DOT__actual_count0 = __Vdly__top__DOT__actual_count0;
    vlTOPp->top__DOT__actual_count1 = __Vdly__top__DOT__actual_count1;
}

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.sv:63
    vlTOPp->top__DOT__reset = (1U & ((IData)(vlTOPp->SWI) 
				     >> 7U));
    vlTOPp->top__DOT__car0 = (1U & (IData)(vlTOPp->SWI));
    vlTOPp->top__DOT__car1 = (1U & ((IData)(vlTOPp->SWI) 
				    >> 1U));
    // ALWAYS at top.sv:137
    vlTOPp->SEG = ((0x7fU & (IData)(vlTOPp->SEG)) | 
		   ((IData)(vlTOPp->top__DOT__clk_3) 
		    << 7U));
    vlTOPp->LED = ((0xfeU & (IData)(vlTOPp->LED)) | 
		   (1U != (IData)(vlTOPp->top__DOT__estado)));
    vlTOPp->LED = ((0xfdU & (IData)(vlTOPp->LED)) | 
		   ((2U != (IData)(vlTOPp->top__DOT__estado)) 
		    << 1U));
    vlTOPp->lcd_a = ((VL_ULL(0xfffffffffffffff0) & vlTOPp->lcd_a) 
		     | (IData)((IData)(vlTOPp->top__DOT__actual_count0)));
    vlTOPp->lcd_a = ((VL_ULL(0xffffffffffffff0f) & vlTOPp->lcd_a) 
		     | ((QData)((IData)(vlTOPp->top__DOT__actual_count1)) 
			<< 4U));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->clk_2) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_2)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__clk_3) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
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
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__clk_3 ^ vlTOPp->__Vchglast__TOP__top__DOT__clk_3))) VL_DBG_MSGF("        CHANGE: top.sv:37: top.clk_3\n"); );
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
    top__DOT__clk_3 = VL_RAND_RESET_I(1);
    top__DOT__car0 = VL_RAND_RESET_I(1);
    top__DOT__car1 = VL_RAND_RESET_I(1);
    top__DOT__car_count0 = VL_RAND_RESET_I(4);
    top__DOT__car_count1 = VL_RAND_RESET_I(4);
    top__DOT__actual_count0 = VL_RAND_RESET_I(4);
    top__DOT__actual_count1 = VL_RAND_RESET_I(4);
    top__DOT__max_count0 = VL_RAND_RESET_I(4);
    top__DOT__max_count1 = VL_RAND_RESET_I(4);
    top__DOT__reset = VL_RAND_RESET_I(1);
    top__DOT__estado = VL_RAND_RESET_I(2);
    __VinpClk__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk_2 = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__clk_3 = VL_RAND_RESET_I(1);
}
