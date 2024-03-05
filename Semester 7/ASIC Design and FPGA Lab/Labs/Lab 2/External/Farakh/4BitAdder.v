module 4bitadder(a0,a1,a2,a3,b0,b1,b2,b3,cin,s0,s1,s2,s3,cout);

input a,b,cin;
output cout,s;
wire s1,c1,c2;

 HA ha1_inst(a,b, s1,c1);
 HA ha12_inst(s1,cin, s,c2 );
or  g5(cout, c1, c2);

endmodule



