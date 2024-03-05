module PWMclockDivider(clkin, rst, dutyCycle, clkout);
	
	parameter divideFactor = 1;

	input clkin, rst;
	input [7: 0] dutyCycle;
	output reg clkout;
	integer condition;

	reg [15:0] count;

	initial
		condition = 0;

	always @ (posedge clkin, posedge rst)
	begin
		if (rst)
		begin
			clkout <= 0;
			count <= 0;
			condition <= 1;
		end
		else
		begin
			if ((condition == 0) & (count >= ((divideFactor * dutyCycle / 100) - 1)))
			begin
				count <= 0;
				clkout <= 1'b0;
				condition <= 1;
			end
			else if ((condition == 1) & (count >= ((divideFactor * (100 - dutyCycle) / 100) - 1)))
			begin
				count <= 0;
				clkout <= 1'b1;
				condition <= 0;
			end
			else
				count <= count + 1;
		end
	end

endmodule
