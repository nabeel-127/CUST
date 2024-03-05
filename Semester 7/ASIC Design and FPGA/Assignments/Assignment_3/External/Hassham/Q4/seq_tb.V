//ASIC Design & FPGA
// Student Name : SYED HASSHAM ALI 
// Registration No.: BEE173071 
// Section No.: 1 
// Assignment No.: 3 
// Question No.: 4

module tb_seqmul;

reg [7:0] A;
reg [7:0] B;
reg clk;
reg reset;
reg start;

wire done;
wire [15:0] prod;

seqmul SM1 (clk, reset, start, A, B,done, prod);

initial
 begin
    clk = 0;
    reset = 0;
    start = 0;
    A = 0;
    B = 0;

    #100 clk = 1;
    reset = 0;
    start = 1;
    A = 4;
    B = 4;

    #100 clk = 1;
    reset = 0;
    start = 1;
    A = 5;
    B= 6;

    end

always
#20 clk = !clk;


endmodule