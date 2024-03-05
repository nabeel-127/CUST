module tb_upCounter;

	reg clk, rst;
	wire [3: 0] counter;

	upCounter inst1(clk, rst, counter);

	always
		#5 clk = ~clk;
	
	initial
	begin
		clk = 0; rst = 0;
		#5 rst = 1;
	end
	
	initial
		$monitor($time, "Counter = %b, Clock = %b, Reset = %b", counter, clk, rst);

	initial
		#2000 $stop;

endmodule