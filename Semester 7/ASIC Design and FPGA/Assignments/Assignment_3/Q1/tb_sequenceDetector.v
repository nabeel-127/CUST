module tb_sequenceDetector;

	reg clk, rst, inBit;
	wire outBit;
	
	sequenceDetector inst1(clk, rst, inBit, outBit );
	
	initial
	begin
		rst = 1'b1; clk = 1'b0;
		#2 rst = 1'b0;
		#4 rst = 1'b1;
	end
	
	always
		#10 clk = ~clk;
	
	initial
	begin
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 0;
		
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 0;
		
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 0;
		
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 0;
		
		@ (posedge clk) inBit = #5 0;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 1;
		@ (posedge clk) inBit = #5 0;
	end

	initial
		$monitor ($time, " output = %d ", outBit);
		
	initial
		#1000 $stop;

endmodule
