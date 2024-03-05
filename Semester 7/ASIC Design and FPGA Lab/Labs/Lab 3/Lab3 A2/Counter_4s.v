module Counter_4s(clk, rst, Q);

	input clk, rst;
	output [3:0] Q;
	wire [3:0] Qn;

	flipflop_D inst1(Qn[0], clk, rst, Q[0], Qn[0]);
	flipflop_D inst2(Qn[1], Qn[0], rst, Q[1], Qn[1]);
	flipflop_D inst3(Qn[2], Qn[1], rst, Q[2], Qn[2]);
	flipflop_D inst4(Qn[3], Qn[2], rst, Q[3], Qn[3]); 

endmodule
