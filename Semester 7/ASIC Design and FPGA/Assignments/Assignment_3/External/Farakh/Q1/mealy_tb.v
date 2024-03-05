// TESTBENCH
module mealy_tb;

reg clk, reset, inbit;

wire outbit;

mealy inst1(clk, reset, inbit, outbit );
initial

begin
reset = 1'b1; clk = 1'b0;

#20 reset = 1'b0;

#30 reset = 1'b1;

end

always
#100 clk = ~clk;

initial

begin

@(posedge clk) inbit = #5 0;

@(posedge clk) inbit = #5 1;

@(posedge clk) inbit = #5 1;

@(posedge clk) inbit = #5 0;

@(posedge clk) inbit = #5 1;

@(posedge clk) inbit = #5 1;

@(posedge clk) inbit = #5 0;

@(posedge clk) inbit = #5 1;

@(posedge clk) inbit = #5 0;

end

initial
$monitor ($time, " output = %d ",outbit);

initial

#3000 $stop;

endmodule