module Counter_4s(s, clk, rst, Q);

	input s, clk, rst;
	output reg [3:0] Q;

  always @ (posedge clk, negedge rst, edge s)
  begin
    if (!rst)
      begin
        if (s == 0)
          begin
            Q = 0;
          end
        else
          begin
            Q = 15;
          end
      end
    else
      begin
        if (s == 0)
          begin
            Q = Q + 1;
          end
        else
          begin
            Q = Q - 1;
          end
      end
  end

endmodule
