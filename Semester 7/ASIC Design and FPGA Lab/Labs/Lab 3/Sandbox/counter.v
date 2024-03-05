module counter(clk,rst,q);

input clk,rst;
output [3:0]q;
wire [3:0]qn;

flip f1(clk, rst, qn[0], q[0], qn[0]);

flip f2(qn[0], rst, qn[1], q[1], qn[1]);

flip f3(qn[1], rst, qn[2], q[2], qn[2]);

flip f4(qn[2], rst, qn[3], q[3], qn[3]); 

endmodule
