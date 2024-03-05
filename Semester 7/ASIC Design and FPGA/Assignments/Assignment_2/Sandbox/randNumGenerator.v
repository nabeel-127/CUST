module randNumGenerator(clk, rst, out);

	input clk, rst;
	output [15: 0] out;

	reg [15: 0] D;
	reg Din, load;

	shiftRegister16 inst1(D, Din, load, clk, rst, out);

	initial
	begin
		D = 16'hffff; load = 0;
	end

	always @ (*)
	begin
		Din = out[3] ^ out[6] ^ out[9] ^ out[12];
		if (out == 0)
		begin
			D = 16'hffff;		
		end
	end

endmodule