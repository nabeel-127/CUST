module fbitadder(a0,a1,a2,a3,b0,b1,b2,b3,cin,s0,s1,s2,s3,cout);

input a0,a1,a2,a3,b0,b1,b2,b3,cin;
output s0,s1,s2,s3,cout;
wire c1,c2,c3;

 FA fa1_inst(a0 , b0 , cin , s0 , c1);
 FA fa2_inst(a1 , b1 , c1  , s1 , c2);
 FA fa3_inst(a2 , b2 , c2  , s2 , c3);
 FA fa4_inst(a3 , b3 , c3  , s3 , cout);


endmodule
