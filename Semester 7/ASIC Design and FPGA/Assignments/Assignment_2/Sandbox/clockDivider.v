module clockDivider(clkin, clkout, rst);
	
	parameter divideFactor = 1;

	input clkin, rst;
	output reg clkout;

	reg [15:0] count;

	always @ (posedge clkin, posedge rst)
	begin
		if (rst)
		begin
			clkout <= 0;
			count	<= 0;
		end
		else
		begin
			if (count == (divideFactor / 2 - 1))
			begin
				count <= 0;
				clkout <= ~clkout;
			end
			else
				count <= count + 1;
		end
	end

endmodule