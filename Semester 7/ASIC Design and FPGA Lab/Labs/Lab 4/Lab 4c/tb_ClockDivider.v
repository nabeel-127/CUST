module tb_ClockDivider;
  
  reg clk, rst;
  wire clkOut;
  
  ClockDivider #(8) inst1(clk, rst, clkOut);
  
  initial
  begin
    clk = 0;
    rst = 1'b1;
  end
  always
  #5 clk = ~clk;
  
  initial
  $monitor($time, "Clock = %b, New clock = %b", clk, clkOut);
  initial
  #2000 $stop;
  
endmodule