module bitAdder_4(A, B, Cin, S, Cout);

	input Cin;
	input [3: 0] A, B;
	output reg [3: 0] S;
	output reg Cout;

	always @ (*)
	begin
		{Cout, S} = A + B + Cin;
	end

endmodule
