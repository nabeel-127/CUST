module FA(s, cout, a, b, cin);
  
  input a, b, cin;
  output s, cout;
  wire x, y, z;
  
  xor g1(x, a, b);
  and g2(y, a, b);
  
  and g3(z, x, cin);
  
  xor g4(s, x, cin);
  or g5(cout, z, y);
  
endmodule
