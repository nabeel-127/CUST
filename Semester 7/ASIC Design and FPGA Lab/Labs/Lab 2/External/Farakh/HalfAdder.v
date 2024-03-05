module HA(a,b,s,cout);

input a,b;
output cout,s;

xor g1(s, a, b);
and g3(c, a, b);

endmodule