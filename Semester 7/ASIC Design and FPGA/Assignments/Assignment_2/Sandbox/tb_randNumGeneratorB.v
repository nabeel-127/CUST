module tb_randNumGeneratorB;

	reg clk, rst;
	wire clkDiv;
	wire [15: 0] out;

	clockDivider #(10) inst1(clk, clkDiv, rst);
	//randNumGeneratorB inst2(clkDiv, rst, out);

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
		$monitor($time, " Clock = %b, Reset = %b", clkDiv, rst);
		#10000 $stop;
	end

endmodule