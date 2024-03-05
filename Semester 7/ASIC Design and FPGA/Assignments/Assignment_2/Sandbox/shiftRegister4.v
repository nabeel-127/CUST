module shiftRegister4(D, Din, load, clk, rst, A);

	input [3: 0] D;
	input Din, load, clk, rst;
	output [3: 0] A;

	reg [3: 0] d;
	wire [3: 0] Anot;

	Dflipflop inst1(d[3], clk, rst, A[3], Anot[3]);
	Dflipflop inst2(d[2], clk, rst, A[2], Anot[2]);
	Dflipflop inst3(d[1], clk, rst, A[1], Anot[1]);
	Dflipflop inst4(d[0], clk, rst, A[0], Anot[0]);	

	always @ (*)
	begin
		d = (load == 1) ? D : {Din, A[3: 1]};
	end


endmodule