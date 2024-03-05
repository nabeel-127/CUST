module tb_sequentialMultiplier;

	reg [7:0] A;
	reg [7:0] B;
	reg clk, rst, start;

	wire done;
	wire [15:0] product;

	sequentialMultiplier inst1(clk, rst, start, A, B, done, product);

	initial
	begin
		clk = 0;
		rst = 0;
		start = 0;
		A = 0;
		B = 0;

		#100 clk = 1;
		rst = 0;
		start = 1;
		A = 4;
		B = 4;

		#100 clk = 1;
		rst = 0;
		start = 1;
		A = 5;
		B= 6;
	end

	always
		#20 clk = !clk;

	initial
		$monitor($time, " A = %d, B = %d, product = %d", A, B, product);

	initial
		#1000 $stop;
endmodule