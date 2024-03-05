module muxtb;

 reg io,i1,i2,i3,s0,s1;
 wire y;

 mux muxtb_inst(io,i1,i2,i3,s0,s1,y);

 initial
 begin
 #5 io = 0; i1 = 0; i2 = 0; i3 = 0; s0 = 1 ; s1=0;
 #5 io = 0; i1 = 0; i2 = 0; i3 = 1; s0 = 1 ; s1=1;
 #5 io = 1; i1 = 0; i2 = 0; i3 = 0; s0 = 1 ; s1=1;
 #5 io = 0; i1 = 0; i2 = 0; i3 = 1; s0 = 0 ; s1=0;

 
 end
  
 initial
 $monitor( $time, "i0 = %b ,i1 = %b ,i2 = %b ,i3= %b ,s0 = %b, s1=%b , y=%b" ,io,i1,i2,i3,s0,s1,y);

 initial 
 #80  $stop;
  
endmodule



