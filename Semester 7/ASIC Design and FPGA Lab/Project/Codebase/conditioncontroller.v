module condition(counter,d1,d2,d3,d4);
input [3: 0] counter;
output reg [3:0]d1,d2,d3,d4;


always@(*)
	begin
		case(counter)
			
			4'd0: begin d1 = 0; d2 = 0; d3 = 0; d4= 0; end
			4'd1: begin d1 = 0; d2 = 4'd1; d3 = 0; d4 = 0; end //display 10;
			4'd2: begin d1 = 0; d2  = 4'd2; d3 = 0; d4 = 0; end // display 20;
			4'd3: begin d1 = 0; d2  = 4'd3; d3 = 0; d4 = 0; end
			4'd4: begin d1 = 0; d2  = 4'd4; d3 = 0; d4 = 0; end
			4'd5: begin d1 = 0; d2  = 4'd5; d3 = 0; d4 = 0; end
			4'd6: begin d1 = 0; d2  = 4'd6; d3 = 0; d4 = 0; end
			4'd7: begin d1 = 0; d2  = 4'd7; d3 = 0; d4 = 0; end
			4'd8: begin d1 = 0; d2  = 4'd8; d3 = 0; d4 = 0; end
			4'd9: begin d1 = 0; d2  = 4'd9; d3 = 0; d4 = 0; end
			4'd10: begin d1 = 0; d2  = 0; d3 = 4'd1; d4 = 0; end //display 100;
		endcase
	end

endmodule