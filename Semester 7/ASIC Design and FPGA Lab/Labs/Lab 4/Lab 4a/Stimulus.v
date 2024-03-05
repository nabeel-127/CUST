module Stimulus;
  
  reg [7: 0] a, b;
  reg s;
  wire [7: 0] out;
  
  Adder_Subtractor inst1(a, b, s, out);
  
  initial
  begin
    #5 a = 8'b0000_0001; b = 8'b0000_0001; s = 0;
    #5 a = 8'b0000_0001; b = 8'b0000_0001; s = 1;
  end
  
  initial
  $monitor($time, "A = %b, B = %b, Out = %b", a, b, out);
  
  initial
  #200 $stop;
  
endmodule
