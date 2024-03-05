module tb_mealySM;

reg clk, rst, inbit;
wire outbit;

mealySM inst1(clk, rst, inbit, outbit);

initial
begin
	clk = 0; rst = 1;
	#20 rst = 1'b0;
	#30 rst = 1'b1;
end

always
	#100 clk = ~clk;
initial
begin
	@ (posedge clk) inbit = #5 0;
	@ (posedge clk) inbit = #5 1;
	@ (posedge clk) inbit = #5 1;
	@ (posedge clk) inbit = #5 0;
	@ (posedge clk) inbit = #5 1;
	@ (posedge clk) inbit = #5 1;
	@ (posedge clk) inbit = #5 0;
	@ (posedge clk) inbit = #5 1;
	@ (posedge clk) inbit = #5 0;
end

initial
	$monitor ($time, " Out = %d", outbit);

initial
	#3000 $stop;

endmodule