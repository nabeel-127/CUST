`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:35:56 01/08/2021 
// Design Name: 
// Module Name:    topModule 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module topModule(clk,switch1,switch2,rst,cathode,anode);

	input wire switch1, switch2, clk, rst;
	output [3:0] anode;
	output [7: 0] cathode;
	wire [3: 0] counter;
	wire [7: 0] dutyCycle;
	wire outSwitch1, outSwitch2;
	wire OUT;
	
	clearDebouncing inst1(switch1, switch2, outSwitch1, outSwitch2);
	cases inst2(outSwitch1, outSwitch2, counter, dutyCycle);
	sevensegcontroller inst3(clk, anode, cathode, counter);
	PWMclockDivider #(5000) inst4(clk, rst, dutyCycle, OUT);


endmodule
