module tb_bitSerialAdder;

	reg clk, rst, start, cin;
	reg [3:0] a,b;
	wire cout;
	wire [3:0] sum;

	bitSerialAdder #(4) inst1(clk, rst, start, a, b, cin, cout, sum);

	initial
	begin
		rst = 1'b1; clk = 1'b0;
		#10 rst = 1'b0;
		#20 rst = 1'b1;
		#100 cin = 0; a=4'b0011; b= 4'b0000_1011; start = 1'b1;
		#200 cin = 0; a=4'b0011; b= 4'b0001; start = 1'b1;
	end
	
	always
		#50 clk = ~clk;
	
	
	initial
		$monitor ($time, "a= %b , b=%b, start = %b, output = %b , cout = %b ", a, b, start, sum, cout);
	
	initial
		#5000 $stop;

endmodule