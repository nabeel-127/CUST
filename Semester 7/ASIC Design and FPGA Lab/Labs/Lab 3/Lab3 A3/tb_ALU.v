module tb_ALU;

	reg [15: 0] a, b;
	reg s0, s1;
	wire  [15: 0] out;

	ALU inst1(a, b, s0, s1, out);

	initial
	begin
		#5 = a = 16'h0001; b = 16'b0001; s0 = 0; s1 = 0;	
		#5 = a = 16'h0001; b = 16'b0001; s0 = 0; s1 = 1;
		#5 = a = 16'h0001; b = 16'b0001; s0 = 1; s1 = 0;
		#5 = a = 16'h0001; b = 16'b0001; s0 = 1; s1 = 1;
	end

	initial
	$monitor($time, "A = %b, B = %b, s0 = %b, s1 = %b, Out = %b" a, b, s0, s1, out);

	initial
	#200 $stop;

endmodule
