module bitMultiplier_4(A, B, Cin, C);

	input Cin;
	input [3: 0] A, B;
	output reg [7: 0] C;
	reg [3: 0] a1, b1, a2, b2, a3, b3;
	wire [3: 0] s1, s2, s3;
	wire cO1, cO2, cO3;

	bitAdder_4 inst1(a1, b1, 0, s1, cO1);
	bitAdder_4 inst2(a2, b2, 0, s2, cO2);
	bitAdder_4 inst3(a3, b3, 0, s3, cO3);


	always @ (*)
	begin
		C[0] = A[0] & B[0];

		a1[0] = A[0] & B[1];
		a1[1] = A[0] & B[2];		
		a1[2] = A[0] & B[3];
		a1[3] = 0;

		b1[0] = A[1] & B[0];
		b1[1] = A[1] & B[1];
		b1[2] = A[1] & B[2];
		b1[3] = A[1] & B[3];

		C[1] = s1[0];
		
		a2[0] =  s1[1];
		a2[1] =  s1[2];		
		a2[2] =  s1[3];
		a2[3] = cO1;

		b2[0] = A[2] & B[0];
		b2[1] = A[2] & B[1];
		b2[2] = A[2] & B[2];
		b2[3] = A[2] & B[3];
		
		C[2] = s2[0];

		a3[0] =  s2[1];
		a3[1] =  s2[2];		
		a3[2] =  s2[3];
		a3[3] = cO2;

		b3[0] = A[3] & B[0];
		b3[1] = A[3] & B[1];
		b3[2] = A[3] & B[2];
		b3[3] = A[3] & B[3];
		
		C[3] = s3[0];
		C[4] = s3[1];
		C[5] = s3[2];
		C[6] = s3[3];

		C[7] = cO3;

	end


endmodule
