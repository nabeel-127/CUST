module mealy(clk, reset, a, y);

parameter S0 = 2'b00;
parameter S1 = 2'b01;
parameter S2 = 2'b10;
parameter S3 = 2'b11;

input clk, reset , a;
output reg y;

reg [1:0] state, nextstate;

// State Register
always @(posedge clk, negedge reset)
begin
	if (!reset)
		state <= S0;
	else
		state <= nextstate;

end

// Next State Logic
always @(state, a)
begin
	case (state)
		S0: 	if (a) nextstate = S1;
			else nextstate = S0;
		S1: 	if (a) nextstate = S2;
			else nextstate = S0;
		S2: 	if (a) nextstate = S1;
			else nextstate = S3;
		S3: 	if (a) nextstate = S0;
			else nextstate = S0;
		default: nextstate = S0;
	endcase
end

// Output Logic

always @ (a, state)
	y = (a & state == S3);

endmodule