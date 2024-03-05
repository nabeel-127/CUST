module tb_Accumulator;
  
  reg [7: 0] a;
  reg sel, clk, rst;
  wire [7: 0] out;
  
  Accumulator inst1(a, sel, clk, rst, out);
  
  initial
  clk = 0;
  always
  #5 clk = ~clk;
  
  initial
  begin
    rst = 0;
    #5 rst = 1;
    #5 a = 8'h01; sel = 0;
  end
  
  initial
  $monitor($time, "A = %b, Sel = %b, Clock = %b, Reset = %b, Out = %b", a, sel, clk, rst, out);
  
  initial
  #200 $stop;
  
endmodule