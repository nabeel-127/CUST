module controller(clk,rst,start,loadreg,ready);
	
	parameter SIdle = 3'b000;
	parameter S0 = 3'b001;
	parameter S1 = 3'b010;
	parameter S2 = 3'b011;
	parameter S3 = 3'b100;
	parameter S4 = 3'b101;


	input clk,rst,start;
	reg [2:0]state;
	output loadreg, ready;
	reg loadreg, ready;

	reg [2:0] next_state;
	
	always @ (posedge clk , negedge rst)
	begin

		if(!rst)
		state <= SIdle;
		else
		state <= next_state;
	end
	
	always @ (*)
	begin
		case (state)
		SIdle : 
		begin 
			if(start == 1)
			begin
				next_state = S0; loadreg = 1'b1; ready = 1'b0;
			end
			else
			begin 
				next_state = SIdle; loadreg = 1'b0; ready = 1'b1;
			end 
		end

		S0: 
		begin 
			next_state = S1; loadreg = 1'b0; ready = 1'b0; 
		end

		S1: 
		begin 
			next_state = S2; loadreg = 1'b0; ready = 1'b0; 
		end

		S2: 
		begin 
			next_state = S3; loadreg = 1'b0; ready = 1'b0; 
		end

		S3: 
		begin 
			next_state = S4; loadreg = 1'b0; ready = 1'b0; 
		end

		S4: 
		begin 
			next_state = SIdle; loadreg = 1'b0; ready =1'b1; 
		end

		default: 
		begin 
			next_state = SIdle; loadreg = 1'b0; ready = 1'b1; 
		end	
		endcase
	
	end

endmodule