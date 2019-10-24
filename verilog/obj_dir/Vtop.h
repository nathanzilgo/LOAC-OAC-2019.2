// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_2,0,0);
    VL_IN8(SWI,7,0);
    VL_OUT8(LED,7,0);
    VL_OUT8(SEG,7,0);
    VL_OUT8(lcd_pc,7,0);
    VL_OUT8(lcd_SrcA,7,0);
    VL_OUT8(lcd_SrcB,7,0);
    VL_OUT8(lcd_ALUResult,7,0);
    VL_OUT8(lcd_Result,7,0);
    VL_OUT8(lcd_WriteData,7,0);
    VL_OUT8(lcd_ReadData,7,0);
    VL_OUT8(lcd_MemWrite,0,0);
    VL_OUT8(lcd_Branch,0,0);
    VL_OUT8(lcd_MemtoReg,0,0);
    VL_OUT8(lcd_RegWrite,0,0);
    VL_OUT(lcd_instruction,31,0);
    VL_OUT64(lcd_a,63,0);
    VL_OUT64(lcd_b,63,0);
    VL_OUT8(lcd_registrador[32],7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__clk_3,0,0);
    VL_SIG8(top__DOT__state,1,0);
    VL_SIG8(top__DOT__reset,0,0);
    VL_SIG8(top__DOT__contadorGotas,7,0);
    VL_SIG16(top__DOT__contador3,15,0);
    VL_SIG16(top__DOT__contador5,15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__VinpClk__TOP__top__DOT__clk_3,0,0);
    VL_SIG8(__Vclklast__TOP__clk_2,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_3,0,0);
    VL_SIG8(__Vchglast__TOP__top__DOT__clk_3,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
