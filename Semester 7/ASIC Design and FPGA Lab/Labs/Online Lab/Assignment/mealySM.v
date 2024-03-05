module mealySM(clk, rst, a, out);

parameter S0 = 2'b00;
parameter S1 = 2'b01;
parameter S2 = 2'b10;
parameter S3 = 2'b11;

input clk, rst, a;
output reg out;
reg [1:0] state, nextstate;


always @ (state, a)
begin
	case (state)
		S0:
		begin
			if (a)
				nextstate = S1;
			else
				nextstate = S0;
		end
		S1:
		begin
			if (a)
				nextstate = S2;
			else 
				nextstate = S0;
		end
		S2:
		begin
			if (a)
				nextstate = S1;
			else
				nextstate = S3;
		end
		S3:
		begin
			if (a)
				nextstate = S0;
			else
				nextstate = S0;
		end
		default: nextstate = S0;
	endcase
end

always @ (posedge clk, negedge rst)
begin
	if (!rst)
		state <= S0;
	else
		state <= nextstate;
end

always @ (a, state)
begin
	out = (a & state == S3);
end


endmodule