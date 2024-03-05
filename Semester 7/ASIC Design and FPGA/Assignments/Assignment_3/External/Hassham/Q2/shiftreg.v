module shiftreg(clk, rst, load, datain, dataout, bitin, bitout);

	parameter N = 4;

	input clk, rst, load;
	input bitin;
	input [N - 1: 0] datain;
	output reg [N - 1: 0] dataout;
	output bitout;

	assign bitout = dataout[0];

	always @ (posedge clk, negedge rst)
	begin
		if (!rst)
			dataout <= 4'd0;
		else if (load)
			dataout <= datain;
		else 
			dataout <= {bitin, dataout[N - 1: 1]};
	end

endmodule
