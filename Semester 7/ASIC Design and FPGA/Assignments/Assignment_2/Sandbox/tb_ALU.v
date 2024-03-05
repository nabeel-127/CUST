module tb_ALU;

	reg [31: 0] a, b;
	reg [1: 0] sel;
	wire [7: 0] out1;
	wire [15: 0] out2;
	wire [31: 0] out3;
	wire CF8, PF8, SF8, OF8, CF16, PF16, SF16, OF16, CF32, PF32, SF32, OF32;

	ALU #(8) inst1(a[7: 0], b[7: 0], sel, out1, CF8, PF8, SF8, OF8);
	ALU #(16) inst2(a[15: 0], b[15: 0], sel, out2, CF16, PF16, SF16, OF16);
	ALU #(32) inst3(a[31: 0], b[31: 0], sel, out3, CF32, PF32, SF32, OF32);	

	initial
	begin
		#5 a = 32'h0000_00ff; b = 32'h0000_00ff; sel = 2'b00;
		#5 sel = 2'b01;
		#5 sel = 2'b10;
		#5 sel = 2'b11;
	end

	initial
	begin
		$monitor($time, " A = %h, B = %h, Select Line = %d, Out 1 = %b, Out 2 = %b, Out 3 = %b, CF8 = %b, PF8 = %b, SF8 = %b, OF8 = %b, CF16 = %b, PF16 = %b, SF16 = %b, OF16 = %b, CF32 = %b, PF32 = %b, SF32 = %b, OF32 = %b", a, b, sel, out1, out2, out3, CF8, PF8, SF8, OF8, CF16, PF16, SF16, OF16, CF32, PF32, SF32, OF32);
		#200 $stop;
	end

endmodule