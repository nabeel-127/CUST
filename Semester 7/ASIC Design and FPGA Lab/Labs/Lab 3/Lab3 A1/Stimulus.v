module Stimulus;
  
  reg s, clk, rst;
  wire [3: 0] Q;
  
  Counter_4s inst1(s, clk, rst, Q);
  
  always
  #5 clk = ~clk;
  
  initial
  begin
    clk = 1'b0; s = 0;
    #5 rst = 0;
    #5 rst = 1;
    #100 s = 1;
    
  end
  
  initial
  $monitor($time, " Clock = %b, Reset = %b, Out = %d", clk, rst, Q);
  
  initial
  #200 $stop;
  
endmodule
