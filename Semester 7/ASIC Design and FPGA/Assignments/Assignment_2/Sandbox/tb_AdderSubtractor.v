module tb_AdderSubtractor;

	reg [3: 0] a , b; 
	reg sel;
	wire [3: 0] out;
	wire cout;
	integer fhandle, i, j, x, y;

	AdderSubtractor #(4) inst1(a, b, sel, out, cout);
	
	initial
	begin
		for (i = 0; i <= 15; i = i + 1)
		begin
			for (j = 0; j <= 15; j = j + 1)
			begin
				#5 a = i; b = j; sel = 0;
			end
		end
		#10
		for (i = 0; i <= 15; i = i + 1)
		begin
			for (j = 0; j <= 15; j = j + 1)
			begin
				#5 a = i; b = j; sel = 1;
			end
		end

		#10000 $fclose(fhandle);
	end
	
	initial
	begin
		for (x = 0; x <= 15; x = x + 1)
		begin
			for (y = 0; y <= 15; y = y + 1)
			begin
				
				if ({cout, out} != (i + j))
				begin
					$fwrite(fhandle, $time, "A = %b, B = %b, Cout = %b Out = %b\n", a, b, cout, out);
				end
			end
		end
		
		for (x = 0; x <= 15; x = x + 1)
		begin
			for (y = 0; y <= 15; y = y + 1)
			begin
				
				if ({cout, out} != (i - j))
				begin
					$fwrite(fhandle, $time, "A = %b, B = %b, Cout = %b Out = %b\n", a, b, cout, out);
				end
			end
		end
	end

	initial
		fhandle	= $fopen("Testing.out");

	initial
		$monitor($time, " A = %b, B = %b, Selection Line = %b, Cout = %b, Out = %b", a, b, sel, cout, out);

	initial
		#10000 $stop;

endmodule