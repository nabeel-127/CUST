module tb_Counter_4s;

	reg clk, rst;
	wire [3:0] Q;

	Counter_4s inst1(clk, rst, Q);

	always
		#5 clk = ~clk;
 
	initial
	begin   
		clk = 1'b0; rst = 1'b1;
		#5 rst = 1'b0; 
		#5 rst = 1'b1; 
	end


	initial
		$monitor($time, " Clock = %b, Reset = %b, Q = %d", clk, rst, Q);

	initial 
		#10000  $stop;
  
endmodule
