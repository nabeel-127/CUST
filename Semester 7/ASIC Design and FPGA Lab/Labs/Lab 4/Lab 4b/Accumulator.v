module Accumulator(a, sel, clk, rst, out);
  
  input [7: 0] a;
  input sel, clk, rst;
  output reg [7: 0] out;
  reg [7: 0] aNOT, atemp, y;
  
  always @ (posedge clk, negedge rst)
  begin
    if (rst)
      out = y;
    else
      y = 0;
  end
  
  always @ (*)
  begin
    aNOT = ~a;
    atemp = (sel == 0) ? a: aNOT;
    y = atemp + sel + out;
  end
  
endmodule