module muxtb;

 reg io,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2;
 wire y;

 mux muxtb_inst(io,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,y);

 initial
 begin
 #5 io = 1; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; s0 = 0 ; s1=0; s2=0;

#5 io = 0; i1 = 1; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; s0 = 0 ; s1=0; s2=1;

#5 io = 0; i1 = 0; i2 = 1; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; s0 = 0 ; s1=1; s2=0;

#5 io = 0; i1 = 0; i2 = 0; i3 = 1; i4 = 0; i5 = 0; i6 = 0; i7 = 0; s0 = 0 ; s1=1; s2=1;

#5 io = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 1; i5 = 0; i6 = 0; i7 = 0; s0 = 1 ; s1=0; s2=0;

#5 io = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 1; i6 = 0; i7 = 0; s0 = 1 ; s1=0; s2=1;

#5 io = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 1; i7 = 0; s0 = 1 ; s1=1; s2=0;

#5 io = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 1; s0 = 1 ; s1=1; s2=1;


 end
  
 initial
 $monitor( $time, "i0 = %b ,i1 = %b ,i2 = %b ,i3= %b ,i3 = %b ,i5 = %b ,i6 = %b ,i7= %b,s0 = %b, s1=%b , s2=%b, y=%b" ,io,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,y);

 initial 
 #80  $stop;
  
endmodule


