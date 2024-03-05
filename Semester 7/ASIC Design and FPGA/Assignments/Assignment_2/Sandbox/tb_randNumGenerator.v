module tb_randNumGenerator;

	reg clk, rst;
	wire [15: 0] out;

	randNumGenerator inst1(clk, rst, out);

	initial
		clk = 0;
	always
		#5 clk = ~clk;

	initial
	begin
		rst = 1;
		#5 rst = 0;
	end
	
	initial
	begin
		$monitor($time, " Clock = %b, Reset = %b, Output = %b", clk, rst, out);
		#1000 $stop;
	end

endmodule