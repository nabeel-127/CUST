module tb_ALU;

	reg [3: 0] a, b;
	reg [2: 0] sel;
	wire [3: 0] out;

	ALU inst1(a, b, sel, out);

	initial
	begin
		a = 0; b = 0; sel = 0;
		#5 a = 4'h02; b = 4'h01; sel = 3'b000;
		#5 sel = 3'b001;
		#5 sel = 3'b010;
		#5 sel = 3'b011;
		#5 sel = 3'b100;
		#5 sel = 3'b101;
		#5 sel = 3'b110;
		#5 sel = 3'b111;
	end

	initial
		$monitor($time, " A = %b, B = %b, Selection Line = %b, Out = %b", a, b, sel, out);

	initial
		#200 $stop;

endmodule