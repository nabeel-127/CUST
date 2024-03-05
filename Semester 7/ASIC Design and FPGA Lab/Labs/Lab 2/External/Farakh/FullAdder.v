module FA(a,b,cin,s,cout);

input a,b,cin;
output cout,s;
wire s1,c1,c2;

xor g1(s1, a, b);
xor g2(s, s1, cin);
and g3(c1, a, b);
and g4(c2, cin, s1);
or  g5(cout, c1, c2);

endmodule
