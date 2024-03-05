module tb_UART_reciever;

	reg clk, rst, rx;
	reg [7:0] DATA;
	wire [7:0] dout;
	wire rx_done_tick;
	integer i;
	
	UART_reciever inst1(rx, clk, dout, rx_done_tick, rst);
	
	always 
		#1 clk = ~clk;	

	initial 
	begin
		clk = 0; rst = 1; rx = 1;
		#50 rst = 0;	
		#200 DATA = 8'd1; rx = 0; rst = 1;
	
		for (i = 0; i < 8; i = i+1) 
		begin
			#30 rx = DATA[i];
		end
	end

	initial
		#1000 $stop;

endmodule
