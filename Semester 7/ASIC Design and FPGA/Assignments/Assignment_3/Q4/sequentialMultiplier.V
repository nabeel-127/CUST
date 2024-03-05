module sequentialMultiplier(clk, rst, start, A, B,done, product);

	parameter idle = 2'b00, op = 2'b01, shift = 2'b10;

	input clk, rst, start;
	input [7:0] A, B;
	output reg done;
	output wire [15:0] product;

	reg carry, next_carry;
	reg [1:0] state, next_state;
	reg [7:0] reg_PL, PL, reg_PH, PH, reg_a_multiplicand, a_multiplicand;
	reg [4:0] counter, next_counter;

	assign product = {reg_PH, reg_PL};

	always @ (posedge clk, posedge rst)
		if (rst)
		begin
			state <= idle;
			counter <= 0;
			carry <= 0;
			reg_PL <= 0;
			reg_PH <= 0;
			reg_a_multiplicand <= 0;
		end
		else
		begin
			state <= next_state;
			carry <= next_carry;
			counter <= next_counter;
			reg_PL <= PL;
			reg_PH <= PH;
			reg_a_multiplicand <= a_multiplicand; 
		end
	
	always @ (*)
	begin
		done = 1'b0;
		PL = reg_PL;
		PH = reg_PH;
		a_multiplicand = reg_a_multiplicand; 
		next_carry = carry;
		next_counter = counter;
		next_state = state;
	
		case(state)
		
		idle:
		begin
			if(start)
			begin
				next_counter = 7;
				PL = B;
				PH = 8'b0;
				a_multiplicand = A;
				next_state = op;
			end
		end

		op:
		begin
      			if(reg_PL[0] == 1)
			begin
				{next_carry,PH} = reg_PH + reg_a_multiplicand;
			end
			next_counter = counter - 1;
			next_state = shift;
		end

		shift:
		begin
			{next_carry,PH,PL} = {carry,reg_PH,reg_PL} >> 1;
			if(next_counter == 0)
				next_state = idle;
			else
				next_state = op;
		end

		default:
			next_state = idle;

		endcase
	end

endmodule