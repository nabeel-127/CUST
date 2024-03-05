module flipflop_D(D, clk, rst, Q, Qn);

	input D, clk, rst;
	output reg Q, Qn;

	always @ (posedge clk ,negedge rst)
	begin
		if(!rst)
		begin
			Q <= 1'b0;
			Qn  <= 1'b1;
		end
		else
		begin
			Q <= D;
			Qn <= ~D;
		end	   
	end

endmodule
