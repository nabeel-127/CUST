module Adder_Subtractor(a, b, s, out);
  
  input [7: 0] a, b;
  input s;
  output reg [7: 0] out;
  reg [7: 0] btemp;
  
  always @ (*)
  begin
    if (s == 0)
      btemp = b;
    else
      btemp = ~b;
    //btemp = (s == 0) ? b: ~b;
    out = a + btemp + s;
  end
  
endmodule
