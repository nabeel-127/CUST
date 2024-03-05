module mytest;

// Inputs
reg clk;
reg reset;
reg start;
reg [7:0] A_in;
reg [7:0] B_in;

// Outputs
wire done_tick;
wire [15:0] product;

// Instantiate the Unit Under Test (UUT)
MULTIPLY_revision uut (
    .clk(clk), 
    .reset(reset), 
    .start(start), 
    .A_in(A_in), 
    .B_in(B_in), 
    .done_tick(done_tick), 
    .product(product)
);


initial begin
    // Initialize Inputs
    clk = 0;
    reset = 0;
    start = 0;
    A_in = 0;
    B_in = 0;

    // Wait 100 ns for global reset to finish
    #100;

            clk = 1;
    reset = 0;
    start = 1;
    A_in = 4;
    B_in = 4;

    #100

    clk = 1;
    reset = 0;
    start = 1;
    A_in = 5;
    B_in = 6;

    end

always
#20 clk = !clk;


endmodule