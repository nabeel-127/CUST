module AdderSubtractor(a, b, sel, out, cout);

	parameter N = 1;

	input [N - 1: 0] a, b;
	input sel;
	output reg [N - 1: 0] out;
	output reg cout;

	always @ (*)
	begin
		case (sel)
			1'b0: {cout, out} = a + b;
			1'b1: {cout, out} = a - b;
		endcase
	end

endmodule