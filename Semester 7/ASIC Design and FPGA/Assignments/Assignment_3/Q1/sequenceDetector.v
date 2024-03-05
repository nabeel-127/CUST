module sequenceDetector(clk, rst, inBit, out);

	parameter idle = 4'd0;
	parameter s0 = 4'd1;
	parameter s1 = 4'd2;
	parameter s2 = 4'd3;
	parameter s3 = 4'd4;
	parameter d0 = 4'd5;
	parameter d1 = 4'd6;
	parameter d2 = 4'd7;
	parameter d3 = 4'd8;

	input clk, rst , inBit;
	output reg out;

	reg [3:0] state, nextstate;

	always @(posedge clk, negedge rst)
	begin
		if (!rst)
			state <= idle;
		else
			state <= nextstate;
	end

	always @( inBit ,state )
	begin
		case (state)
		idle: 	if (inBit)
				nextstate = d0;
			else
				nextstate = s0;

		s0: 	if (inBit)
				nextstate = s1;
			else
				nextstate = d1;

		s1: 	if (inBit)
				nextstate = s2;
			else
				nextstate = d2;

		s2: 	if (inBit)
				nextstate = d3;
			else
				nextstate = s3;

		s3: 	if (inBit)
				nextstate = s1;
			else
				nextstate = s0;

		d0: 	if (inBit)
				nextstate = d1;
			else
				nextstate = d1;

		d1: 	if (inBit)
				nextstate = d2;
			else
				nextstate = d2;

		d2: 	if (inBit)
				nextstate = d3;
			else
				nextstate = d3;

		d3: 	if (inBit)
				nextstate = idle;
			else
				nextstate = idle;

		default: nextstate = idle;
		endcase
	end

	always @ (inBit, state)
		out = (state == s3);

endmodule