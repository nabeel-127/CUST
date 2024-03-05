module tb_shiftRegister4;

	reg [3: 0] D;
	reg Din, load, clk, rst;
	wire [3: 0] A;

	shiftRegister4 inst1(D, Din, load, clk, rst, A);

	initial
		clk = 0;
	always
		#5 clk = ~clk;

	initial
	begin
		D = 0; Din = 0; load = 1; rst = 1;
		#5 rst = 0; D = 4'b1010;
		#5 load = 0;
	end
	
	initial
	begin
		$monitor($time, " D = %b, Din = %b, load = %b, Clock = %b, Reset = %b, Output = %b", D, Din, load, clk, rst, A);
		#500 $stop;
	end

endmodule
