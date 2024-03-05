module bitserialadder(clk, reset, start, A, B, Cin, Cout , sum);
	
	input clk, reset, Cin, start;
	input [3:0] A, B;
	output [3:0] sum;
	output Cout;
	reg [3:0] sum;
	reg Cout;
	wire loadreg, ready;
	wire bitA,bitB,bittemp;
	wire [3:0] dataregA, dataregB, dataregSum;
	reg Creg,Crout,bitSum;



	controller bitserialctrl(clk, reset, start, loadreg, ready);
	shiftreg regA (clk, reset, loadreg, A, dataregA, 1'b0, bitA);
	shiftreg regB (clk, reset, loadreg, B, dataregB, 1'b0, bitB);
	shiftreg regSum (clk, reset, 1'b0, 4'd0, dataregSum, bitSum, bittemp);


	always @ (bitA, bitB, Creg)
		{Crout,bitSum} = bitA + bitB + Creg;



	always @(posedge clk , negedge reset)
	begin
		if(!reset)
			Creg <= 0;
		else
			Creg <= Crout;
	end



	always @(ready)
		if(ready)
		begin
		sum = dataregSum;
		Cout = Creg;
		end

endmodule

