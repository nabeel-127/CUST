module Dflipflop(D, clk, rst, Q, Qnot);

	input D, clk, rst;
	output reg Q, Qnot;
	
	always @ (posedge clk, posedge rst)
	begin
		if (rst)
		begin
			Q = 1'b0;
			Qnot = 1'b1;
		end
		else
		begin
			Q = D;
			Qnot = ~Q;
		end
	end

endmodule