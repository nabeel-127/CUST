module sequencedetector(clk,rest,in,out);
input clk,rest,in;
output out;
parameter IDLE = 7'b0000001,
S0 = 7'b0000010,
S1 = 7'b0000100,
S2 = 7'b0001000,
S3 = 7'b0010000,
S4 = 7'b0100000,
S5 = 7'b1000000;

reg [6:0] present,next;

always@(posedge clk)
begin
if(rest)
present <= IDLE;
else
present <=next;
end

always @(present,in)
begin
next = IDLE;
	case(present)
		IDLE : begin if(in) next = IDLE; 	else next=S0;	 end
		S0   : begin if(in) next = S1; 		else next = S0; 	end
		S1   : begin if(in) next = S2; 		else next = S1;	 end
		S2   : begin if(in) next = IDLE; 	else next = S3; 	end
		S3   : begin if(in) next = S4; 		else next = S5; 	end
		S4   : begin if(in) next = S2; 		else next = S0; 	end
		S5   : begin if(in) next = S1; 		else next = S0; 	end
	endcase
end
assign out = (present == S3) ? 1: 0; //1 = Unlock and 0 =False-Code
endmodule



