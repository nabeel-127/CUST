module fmux(i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,y);

input i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2;
output y;
wire m1,m2,n3,g1,g2;

mux m1_inst(i0,i1,i2,i3,s1,s0,m1);
mux m2_inst(i4,i5,i6,i7,s1,s0,m2);

assign n2 = ( ~ s2);

assign g1 = (n2 & m1 );
assign g2 = (s2 & m2 );

assign y = ( g1 | g2 );

endmodule