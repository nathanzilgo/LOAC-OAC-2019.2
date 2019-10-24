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

enum logic [1:0] {off, slow, fast} state;

logic reset ;
logic [6:0] chuva ;
logic clk_3 ;
logic[7:0] contadorGotas;
logic[15:0] contador3;
logic[15:0] contador5;
logic [2:0] limpador ; 

/*
Atribui os switchs as variaveis
*/
always_comb begin
  reset <= SWI[7];
  chuva <= SWI[6:0];
end

/*
retarda o clock em 1/2
*/
always_ff@(posedge clk_2)begin
   clk_3 <= !clk_3 ; 
end
/*
Faz a baguncinha na california
*/
always_ff@(posedge clk_3)begin

    if(reset)begin
          state <= off;
          contador3 <= 0; 
          contador5 <= 0;

    end 

    else begin
        contadorGotas <= SWI[0] + SWI[1] + SWI[2] + SWI[3] + SWI[4] + SWI[5] + SWI[6];

        if(contadorGotas >= 3 && contadorGotas < 6)begin
              contador3 <= contador3 + 1;
              contador5 <= 0;
            end
            else if (contadorGotas >= 5)begin
              contador5 <= contador5 + 1;
              contador3 <= contador3 + 1;            
            end
            else begin
              contador3 <= 0;
              contador5 <= 0;
            end
        end

        unique case (state)
          off:

            if(contador3 >= 3 && contador5 < 2)begin
              state <= slow;
            end
            else if(contador5 >= 2)begin
              state <= fast;
            end
            else begin
              state <= off;
            end

          slow:
            if(contadorGotas < 4)begin
              
              state <= off;
              contador3 <= 0;
              contador5 <= 0;

            end
            else if(contador5 >= 2)  begin
              state <= fast;
            end
            else if(contadorGotas < 6 && contadorGotas >= 3)begin
              contador5 <= 0;
              state <= slow;
            end
            else if(contadorGotas < 4) begin
              state <= off;
              contador3 <= 0;
            end

         fast:
            if(contadorGotas < 4)begin
              state <= off;
              contador3 <= 0;
              contador5 <= 0;
          end
            else if(contadorGotas >= 3 && contadorGotas < 6)begin
              state <= slow;
              contador5 <= 0;
            end
            else if(contadorGotas > 5)begin
              state <= fast;
            end 
        endcase

      end
    

/*
Exibe as saídas
*/
always_comb begin
    
    LED[7] <= clk_3;        // clock relevante
    LED[1:0] <= state;   // saída do limpador
end






endmodule
