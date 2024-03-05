module tb_Dflipflop;

	reg D, clk, rst;
	wire Q, Qnot;

	Dflipflop inst1(D, clk, rst, Q, Qnot);

	initial
		clk = 0;
	always
		#5 clk = ~clk;

	initial
	begin
		rst = 1; D = 0;
		#5 rst = 0; D = 1;
		#50 D = 0;
		#50 D = 1;
	end

	initial
		$monitor($time, " D = %b, Clock = %b, Reset = %b, Q = %b, Qnot = %b", D, clk, rst, Q, Qnot);
	initial
		#500 $stop;

endmodule