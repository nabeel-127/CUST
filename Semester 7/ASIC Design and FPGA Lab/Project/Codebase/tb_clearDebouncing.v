module tb_clearDebouncing;

	reg in1, in2;
	wire out1, out2;

	clearDebouncing inst1(in1, in2, out1, out2);

	initial
	begin
		in1 = 0; in2 = 0;
		#5 in1 = 1; in2 = 1;
		#5 in1 = 0; in2 = 0;
		#5 in1 = 1; in2 = 1;
		#20000 in1 = 0; in2 = 0;
		#10000 in1 = 1;
	end
	
	initial
		$monitor($time, " Input 1 = %b, Input 2 = %b, Output 1 = %b, Output 2 = %b", in1, in2, out1, out2);

	initial
		#100000 $stop;

endmodule
