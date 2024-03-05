module FA(a,b,cin,s,cout);

input a,b,cin;
output cout,s;
wire s1,a1,a2;
 

assign s1= ( a ^ b );
assign s= ( s1 ^ cin ); 
assign a1= ( a & b );
assign a2= ( cin & s1 );
assign cout= ( a1 | a2 );

endmodule

