module tb_bitMultiplier_4;

	reg [3: 0] A, B;
	reg Cin;
	wire [7: 0] C;

	bitMultiplier_4 inst1(A, B, Cin, C);

	initial
	begin
		A = 4'd1; B = 4'd3; Cin = 0;
		#50 A = 4'd15; B = 4'd15;
	end

	initial
		$monitor($time, "A = %b, B = %b, Out = %b", A, B, C);

	initial
		#1000 $stop;

endmodule
