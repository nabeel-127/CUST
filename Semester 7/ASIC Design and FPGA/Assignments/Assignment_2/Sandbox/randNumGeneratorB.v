module randNumGeneratorB(clk, rst, out);

	input clk, rst;
	output reg [15: 0] out;

	always @ (posedge clk, posedge rst)
	begin
		if (rst || (out == 0))
			out <= 16'hffff;
		else
		begin
			out[14:0] <= out[15:1];
			out[15] <= out[3] ^ out[6] ^ out[9] ^ out[12];
		end
	end

endmodule