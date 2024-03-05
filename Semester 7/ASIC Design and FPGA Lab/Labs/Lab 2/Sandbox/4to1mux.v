module mux(i0,i1,i2,i3,s0,s1,y);

input i0,i1,i2,i3,s0,s1;
output y;
wire y0,y1,y2,y3,n0,n1;

assign n0 = ( ~s0);
assign n1 = ( ~s1);


assign y0 = (i0 & n0 & n1);
assign y1 = (i1 & n0 & s1);
assign y2 = (i2 & s0 & n1);
assign y3 = (i3 & s0 & s1);

assign y = (y0 | y1 | y2 | y3);

endmodule

