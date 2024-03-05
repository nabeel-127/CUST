module FA(a, b, cin, sum, cout);
  
  input a, b, cin;
  output sum, cout;
  wire out1, out2, t1;
  
  HA inst1(a, b, out1, out2);
  HA inst2(out1, cin, sum, t1);
  
  or g1(cout, t1, out2);
  
endmodule