module mux(i0,i1,i2,i3,s0,s1,y);

input i0,i1,i2,i3,s0,s1;
output y;
wire y0,y1,y2,y3,n0,n1;


not g1(n0,s0);
not g2(n1,s1);
and g3(y0, i0,n0,n2);
and g4(y1, i1,n1,s0);
and g5(y2, i2,s1,n0);
and g6(y3, i3,s0,s1);

or g7(y,y0,y1,y2,y3);

endmodule