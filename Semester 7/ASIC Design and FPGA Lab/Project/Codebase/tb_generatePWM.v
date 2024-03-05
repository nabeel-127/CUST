module tb_PWMclockDivider;

	reg clk, rst;
	reg [7: 0] dutyCycle;
	wire clkDiv;

	PWMclockDivider #(5000) inst1(clk, rst, dutyCycle, clkDiv);

	initial
		clk = 0;
	always
		#10 clk = ~clk;

	initial
	begin
		rst = 1; dutyCycle = 90;
		#10 rst = 0;
		#1000 dutyCycle = 75;
		#1000 dutyCycle = 25;
	end
	
	initial
	begin
		$monitor($time, " Clock = %b, Clock Divided = %b, Reset = %b", clk, clkDiv, rst);
		#100000 $stop;
	end

endmodule
