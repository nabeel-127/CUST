module ClockDivider(clk, rst, clkOut);
  
  input clk, rst;
  output reg clkOut;
  parameter dividefactor = 1;
  reg [7: 0] counter;
  
  initial
  begin
    clkOut = 0;
    counter = 0;
  end

  always @ (posedge clk, negedge rst)
  begin
    if (!rst)
      begin
        counter = 8'h00;
        clkOut = 0;
      end
    else
      begin
        counter = counter + 1;
        if (counter >= (dividefactor - 1))
          begin
            clkOut <= ~clkOut;
            counter <= 8'h00;
          end
      end
  end

endmodule