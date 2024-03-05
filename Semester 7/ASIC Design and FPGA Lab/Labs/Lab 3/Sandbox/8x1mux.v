module mux(i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,y);

input i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2;
output reg y;

always @ (*)

begin

if({s0,s1,s2}== 3'b000)
  y=i0;
  
else if({s0,s1,s2}== 3'b001)
  y=i1;
  
else if({s0,s1,s2}== 3'b010)
  y=i2;
  
else if({s0,s1,s2}== 3'b011)
  y=i3;
  
else if({s0,s1,s2}== 3'b100)
  y=i4;
  
else if({s0,s1,s2}== 3'b101)
  y=i5;
  
else if({s0,s1,s2}== 3'b110)
  y=i6;
  
else if({s0,s1,s2}== 3'b111)
  y=i7;

 end

endmodule


