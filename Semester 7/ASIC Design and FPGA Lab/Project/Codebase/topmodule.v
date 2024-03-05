module topModule;

	reg switch1, switch2, clk, rst;
	wire [3: 0] anode;
	wire [7: 0] cathode;
	wire [3: 0] counter;
	wire [7: 0] dutyCycle;
	wire outSwitch1, outSwitch2;
	wire OUT;
	
	initial
		clk = 0;

	always
		#10 clk = ~clk;

	clearDebouncing inst1(switch1, switch2, outSwitch1, outSwitch2);
	cases inst2(outSwitch1, outSwitch2, counter, dutyCycle);
	sevensegcontroller inst3(clk, anode, cathode, counter);
	PWMclockDivider #(5000) inst4(clk, rst, dutyCycle, OUT);
	
	initial
	begin
		rst = 1;
		#5 rst = 0;
		switch1 = 0; switch2 = 0;
		#10 switch1 = 1;
		#21000 switch1 = 0;
		#21000 switch1 = 1;

		
	end

	initial
		$monitor($time, "Output = %b", OUT);

	initial
		#1000000 $stop;
endmodule
