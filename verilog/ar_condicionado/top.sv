// DESCRIPTION: Verilator: Systemverilog example module
// with interface to switch buttons, LEDs, LCD and register display

parameter NINSTR_BITS = 32;
parameter NBITS_TOP = 8, NREGS_TOP = 32, NBITS_LCD = 64;
module top(input  logic clk_2,
					 input  logic [NBITS_TOP-1:0] SWI,
					 output logic [NBITS_TOP-1:0] LED,
					 output logic [NBITS_TOP-1:0] SEG,
					 output logic [NBITS_LCD-1:0] lcd_a, lcd_b,
					 output logic [NINSTR_BITS-1:0] lcd_instruction,
					 output logic [NBITS_TOP-1:0] lcd_registrador [0:NREGS_TOP-1],
					 output logic [NBITS_TOP-1:0] lcd_pc, lcd_SrcA, lcd_SrcB,
						 lcd_ALUResult, lcd_Result, lcd_WriteData, lcd_ReadData, 
					 output logic lcd_MemWrite, lcd_Branch, lcd_MemtoReg, lcd_RegWrite);

enum logic [1:0] {reset_state, }

logic reset;
logic aumenta;
logic diminui;

logic real;
logic desejo;
logic pingando;

always_comb begin
	aumenta <= SWI[1];
	diminui <= SWI[0];
	reset   <= SWI[7];
end

endmodule
