module carrySelectAdder_4(A, B, Cin, S, Cout);

	input [3: 0] A, B;
	input Cin;
	output reg [3: 0] S;
	output reg Cout;
	wire [3: 0] S0, S1;
	wire C0, C1;

	bitAdder_4 inst1(A, B, 1'b0, S0, C0);
	bitAdder_4 inst2(A, B, 1'b1, S1, C1);

	always @ (*)
	begin
		S = (Cin == 0) ? S0: S1;
		Cout = (Cin == 0) ? C0: C1;
	end


endmodule
