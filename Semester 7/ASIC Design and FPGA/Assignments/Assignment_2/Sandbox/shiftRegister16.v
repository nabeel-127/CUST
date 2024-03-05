module shiftRegister16(D, Din, load, clk, rst, A);

	input [15: 0] D;
	input Din, load, clk, rst;
	output [15: 0] A;
 
	reg [15: 0] d;
	wire [15: 0] Anot;

	Dflipflop inst1(d[15], clk, rst, A[15], Anot[15]);
	Dflipflop inst2(d[14], clk, rst, A[14], Anot[14]);
	Dflipflop inst3(d[13], clk, rst, A[13], Anot[13]);
	Dflipflop inst4(d[12], clk, rst, A[12], Anot[12]);
	Dflipflop inst5(d[11], clk, rst, A[11], Anot[11]);
	Dflipflop inst6(d[10], clk, rst, A[10], Anot[10]);
	Dflipflop inst7(d[9], clk, rst, A[9], Anot[9]);
	Dflipflop inst8(d[8], clk, rst, A[8], Anot[8]);
	Dflipflop inst9(d[7], clk, rst, A[7], Anot[7]);
	Dflipflop inst10(d[6], clk, rst, A[6], Anot[6]);
	Dflipflop inst11(d[5], clk, rst, A[5], Anot[5]);
	Dflipflop inst12(d[4], clk, rst, A[4], Anot[4]);
	Dflipflop inst13(d[3], clk, rst, A[3], Anot[3]);
	Dflipflop inst14(d[2], clk, rst, A[2], Anot[2]);
	Dflipflop inst15(d[1], clk, rst, A[1], Anot[1]);
	Dflipflop inst16(d[0], clk, rst, A[0], Anot[0]);

	always @ (*)
	begin
		d = (load == 1) ? D : {Din, A[15: 1]};
	end


endmodule