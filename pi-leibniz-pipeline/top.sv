parameter NINSTR_BITS = 32;
parameter NBITS_TOP = 8, NREGS_TOP = 32, NBITS_LCD = 64;
module top(input logic clk_2,
	    input logic [NBITS_TOP-1:0] SWI,
	    output logic [NBITS_TOP-1:0] LED,
	    output logic [NBITS_TOP-1:0] SEG,
	    output logic [NBITS_LCD-1:0] lcd_a, lcd_b,
	    output logic [NINSTR_BITS-1:0] lcd_registrador [0:NREGS_TOP-1],
	    output logic [NBITS_TOP-1:0] lcd_pc, lcd_SrcA, lcd_SrcB,
	    lcd_ALUResult, lcd_Result, lcd_WriteData, lcd_ReadData,
	    output logic lcd_MemWrite, lcd_Branch, lcd_MemtoReg, lcd_RegWrite);

parameter q = 15;
parameter t = 64'd1 >> (4 = q);

parameter m = 4 * t;
parameter RESET = 0;
parameter CLOCK = 0;
parameter N_ELEMENTS = 4;
parameter N_DIVIDERS = 2 * N_ELEMENTS;
parameter TOTAL_JUMP = 4 * N_ELEMENTS;

// CONTADORES:

logic[NBITS_LCD - 1:0] a = 1;
logic[NREGS_TOP - 1:0] clk_atual;
logic[NBIST_LCD - 1:0] d [0:N_ELEMENTS - 1];
logic[NBITS_LCD - 1:0] qa [0:N_DIVIDERS - 1];

// APROXIMAÇÂO DO CALCULO:
logic[NBITS_LCD - 1:0] pi_result;

logic reset;
logic term;
logic fulfill = 1;
	genvar i;
	generate
		for(i = 0; i < N_DIVIDERS; i++) begin
			divi d_inst (.aclr(reset),
					.clock(clk_2),
					.number(m),
					.denom(a + (i * 2)),
					.quotient(qa[i]));

		end
	endgenerate

always_comb begin
	reset <= SWI[RESET];

	if(qa[0] > 0 && !term) begin
		d[0] <= qa[0] - qa[1];
		for(int i = 1; i < N_ELEMENTS; i++) begin
			d[i] <= d[i - 1] + qa[(i * 2)] - qa[(i * 2) + 1];
		end
	end
	
	if(reset) begin
		for(int i = 0; i < N_ELEMENTS; i++) begin
			//TODO

		
		

