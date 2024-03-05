module tb_carrySelectAdder_8;

	reg [7: 0] A, B;
	reg Cin;
	wire [7: 0] S;
	wire Cout;
	
	carrySelectAdder_8 inst1(A, B, Cin, S, Cout);
	
	initial
	begin
		A = 8'd3; B = 8'd3; Cin = 0;
		#50 A = 8'd5; B = 8'd3;
	end

	initial
		$monitor($time, "A = %d, B = %d, OUT = %d", A, B, {Cout, S});
	initial
		#100 $stop;

endmodule
