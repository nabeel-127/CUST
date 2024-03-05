module ALU(a, b, s0, s1, out);

	input [15: 0] a, b;
	input s0, s1;
	output reg [15: 0] out;

	always @ (*)
	begin
		case ({s0, s1})
		2'b00: out = a + b;
		2'b01: out = a - b;
		2'b10: out = a & b;
		2'b11: out = a | b;
		endcase
	end

endmodule
