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

  always_comb begin
    // LED <= SWI | clk_2;
    SEG <= SWI;
    lcd_WriteData <= SWI;
    lcd_pc <= 'h12;
    lcd_instruction <= 'h34567890;
    lcd_SrcA <= 'hab;
    lcd_SrcB <= 'hcd;
    lcd_ALUResult <= 'hef;
    lcd_Result <= 'h11;
    lcd_ReadData <= 'h33;
    lcd_MemWrite <= SWI[0];
    lcd_Branch <= SWI[1];
    lcd_MemtoReg <= SWI[2];
    lcd_RegWrite <= SWI[3];
    for(int i=0; i<NREGS_TOP; i++) lcd_registrador[i] <= i+i*16;
    // lcd_a <= {56'h1234567890ABCD, SWI};
    // lcd_b <= {SWI, 56'hFEDCBA09876543};
  end

	logic clk_3;

	logic car0;
	logic car1;

	logic [3:0] car_count0;
	logic [3:0] car_count1;

	logic [3:0] actual_count0;
	logic [3:0] actual_count1;

	logic [3:0] max_count0;
	logic [3:0] max_count1;


	logic reset;

	

	enum logic [1:0] {rr, rg, gr} estado;

 
  always_ff @(posedge clk_2) begin
    clk_3 <= !clk_3;
  end
  
  always_comb begin
		reset <= SWI[7];
		car0 <= SWI[0];
		car1 <= SWI[1];
  end

  always_ff @(posedge clk_3) begin
		if(reset) begin
			estado <= rr;

			car_count0 <= 0;
			car_count1 <= 0;
			actual_count0 <= 0;
			actual_count1 <= 0;
			max_count0 <= 2;
			max_count1 <= 2;
			
		end
		else begin
			unique case(estado)
				rr: begin
					if(!car0 && !car1) begin
						estado <= rr;
					end else begin
						if(car0) estado <= rg;
						else if(car1) estado <= gr;
					end
				end

				rg: begin

					if(car0) car_count0 <= car_count0 + 1;

					if(actual_count0 == max_count0) begin
						if(car_count0 == max_count0) max_count0 <= 5;
						else max_count0 <= 2;

						car_count0 <= 0;
						actual_count0 <= 0;

						if(car1) estado <= gr;
						else estado <= rr;

						
					end 
					else actual_count0 <= actual_count0 + 1;

				end


				gr: begin

					if(car1) car_count1 <= car_count1 + 1;

					if(actual_count1 == max_count1) begin
						if(car_count1 == max_count1) max_count1 <= 5;
						else max_count1 <= 2;

						car_count1 <= 0;
						actual_count1 <= 0;

						if(car0) estado <= gr;
						else estado <= rr;

						
					end 
					else actual_count1 <= actual_count1 + 1;

				end

			endcase
		end
  end

  always_comb begin
    SEG[7] <= clk_3;
		LED[0] <= !(estado == rg);
		LED[1] <= !(estado == gr);

		lcd_a[3:0] <= actual_count0;
		lcd_a[7:4] <= actual_count1;

  end

endmodule
