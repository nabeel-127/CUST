module cases(switch1, switch2, counter, dutyCycle);
	
	input switch1, switch2;
	output reg [7: 0] dutyCycle;
	output reg [3: 0] counter = 0;

	always @ (posedge switch1, posedge switch2)
	begin 
		if(counter == 4'd0 && switch2  == 1)
		counter <= 4'd0;
		
		else if (counter == 4'd10 && switch1 == 1)
		counter <= 4'd10;
		
		else if(switch1 == 1)
		counter = counter + 1;
		
		else if (switch2 == 1)
		counter = counter - 1;

		dutyCycle = counter * 10;
	end

endmodule
