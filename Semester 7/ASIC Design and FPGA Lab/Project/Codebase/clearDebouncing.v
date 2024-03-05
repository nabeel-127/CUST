module clearDebouncing(in1, in2, out1, out2);

	input in1, in2;
	output reg out1, out2;

	always @ (*)
	begin
		#20000 out1 <= in1; out2 <= in2;
	end

endmodule
