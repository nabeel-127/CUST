module sadder_tb;

reg clk,rst,start;

reg [3:0]a,b;

wire cout;

wire[3:0]sum;


serialadder inst1(clk, rst, start, a, b, cout , sum );

initial
begin
rst = 1'b1; clk = 1'b0;
#20 rst = 1'b0;
#30 rst = 1'b1;

#100 a=4'b0011; b= 4'b1011;start = 1'b1;

#200 a=4'b0011; b= 4'b011; start = 1'b1;
end

always
#50 clk = ~clk;


initial
$monitor ($time, "a= %b , b=%b, start = %b, output = %b , cout = %b ",a,b,start,sum,cout);

initial
#5000 $stop;

endmodule