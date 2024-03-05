module upCounter(clk, rst, counter);

	input clk, rst;
	output reg [3: 0] counter;
	
	initial
		counter = 0;

	always @ (posedge clk, negedge rst)
	begin
		if (!rst)
			counter = 0;
		else
			counter = counter + 1;
	end

endmodule
