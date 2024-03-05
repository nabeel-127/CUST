module BCD_control(d1,d2,d3,d4,refreshcounter,dout);
input [3:0]d1;
input [3:0]d2;
input [3:0]d3;
input [3:0]d4;
input [1:0]refreshcounter;
output reg [3:0] dout = 0;

always @(refreshcounter)

	begin
		case(refreshcounter)
			2'b00: dout = d1;
			2'b01: dout = d2;
			2'b10: dout = d3;
			2'b11: dout = d4;
		endcase
	end
	
endmodule