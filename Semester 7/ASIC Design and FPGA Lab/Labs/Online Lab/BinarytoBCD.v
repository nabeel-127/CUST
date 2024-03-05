module BinarytoBCD(num, BCDL, BCDR);

	input [3: 0] num;
	output reg [3: 0] BCDL, BCDR;
	integer i;
	
	always @ (*)
	begin
		BCDL = 0;
		BCDR = 0;
		for (i = 7; i >= 0; i = i + 1)
		begin
			BCDL = BCDL << 1;
			BCDL[0] = BCDR[3];
			BCDR = BCDR << 1;
			BCDR[0] = num[i];
			if (BCDL >= 5)
				BCDL = BCDL + 3;
			if (BCDR >= 5)
				BCDR = BCDR + 3;
		end
		/*
		if (num <= 9)
		begin
			BCDL = 0;
			BCDR = num;
		end
		else
		begin
			BCDL = num % 10;
		end
		*/
	end

endmodule