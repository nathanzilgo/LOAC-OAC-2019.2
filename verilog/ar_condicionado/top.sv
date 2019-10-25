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

enum logic [1:0] {estavel, aumentando, diminuindo} state;

logic reset;
logic aumenta;
logic diminui;

logic real;
logic desejo;
logic pingando;

parameter temp_max = 27;
parameter temp_min = 20;

always_comb begin
	aumenta <= SWI[1];
	diminui <= SWI[0];
	reset   <= SWI[7];
end

always_ff@(posedge clk_2 or posedge reset)begin

	if(reset)begin
		state 	<= estavel;
		real 	<= 20;
		desejo 	<= 20;
	end

	else begin

		unique case(state)
			estavel:
				if(aumenta && !diminui && real < temp_max)begin
					state <= aumentando;
					real <= real + 1;
				end
				else if(diminui && !aumenta && real > temp_min)begin
					state <= diminuindo;
					real <= real - 1;
				end
				else begin
					state <= estavel;
				end
			
			aumentando:
end
endmodule
