module MUX(i0, i1, i2, i3, s0, s1, out);
  
  input i0, i1, i2, i3, s0, s1;
  output out;
  wire y0, y1, y2, y3, s0n, s1n;
  
  not g1(s0n, s0);
  not g2(s1n, s1);
  
  and g3(y0, i0, s1n, s0n);
  and g4(y1, i1, s1n, s0n);
  and g5(y2, i2, s1n, s0n);
  and g6(y3, i3, s1n, s0n);
  
  or g7(out, y0, y1, y2, y3);
    
endmodule