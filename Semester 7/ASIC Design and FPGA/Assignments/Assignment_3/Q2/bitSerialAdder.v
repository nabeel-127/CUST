module bitSerialAdder(clk, reset, start, A, B, Cin, Cout , sum);

	parameter N = 4;

	input clk, reset, Cin, start;
	input [N - 1: 0] A, B;
	output reg [N - 1: 0] sum;
	output Cout;

	reg Cout;
	wire loadreg, ready;
	wire bitA, bitB, bittemp;
	wire [N - 1: 0] dataregA, dataregB, dataregSum;
	reg Creg, Crout, bitSum;

	controller bitSerialCtrl(clk, reset, start, loadreg, ready);
	shiftReg #(N) regA(clk, reset, loadreg, A, dataregA, 0, bitA);
	shiftReg #(N) regB(clk, reset, loadreg, B, dataregB, 0, bitB);
	shiftReg #(N) regSum(clk, reset, 0, 0, dataregSum, bitSum, bittemp);

	always @ (bitA, bitB, Creg)
		{Crout,bitSum} = bitA + bitB + Creg;

	always @ (posedge clk , negedge reset)
	begin
		if (!reset)
			Creg <= 0;
		else
			Creg <= Crout;
	end

	always @ (ready)
	begin
		if (ready)
		begin
			sum = dataregSum;
			Cout = Creg;
		end
	end

endmodule
