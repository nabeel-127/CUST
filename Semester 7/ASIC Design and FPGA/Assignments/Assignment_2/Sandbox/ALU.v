module ALU(a, b, sel, out, carryFlag, parityFlag, signFlag, overflowFlag);

	parameter N = 1;

	input [N - 1: 0] a, b;
	input [1: 0] sel;
	output reg [N - 1: 0] out;
	output reg carryFlag, parityFlag, signFlag, overflowFlag;

	always @ (*)
	begin
		case (sel)
			2'b00: {carryFlag, out} = a + b;
			2'b01: {carryFlag, out} = a - b;
			2'b10: {carryFlag, out} = a & b;
			2'b11: {carryFlag, out} = a ^ b;
		endcase
		parityFlag = ^out;
		signFlag = out[N - 1];
		if (((a[N - 1] ^ b[N - 1]) == 0) && (out[N - 1] != a[N - 1]))
		overflowFlag = 1;
		else
		overflowFlag = 0;
	end

endmodule