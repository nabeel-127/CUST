module tb_shiftRegister16;

	reg [15: 0] D;
	reg Din, load, clk, rst;
	wire [15: 0] A;

	shiftRegister16 inst1(D, Din, load, clk, rst, A);

	initial
		clk = 0;
	always
		#5 clk = ~clk;

	initial
	begin
		D = 0; Din = 0; load = 1; rst = 1;
		#5 rst = 0; D = 16'h1234;
		#50 load = 0;
		#55 Din = 1;
	end
	
	initial
	begin
		$monitor($time, " D = %b, Din = %b, load = %b, Clock = %b, Reset = %b, Output = %b", D, Din, load, clk, rst, A);
		#500 $stop;
	end

endmodule