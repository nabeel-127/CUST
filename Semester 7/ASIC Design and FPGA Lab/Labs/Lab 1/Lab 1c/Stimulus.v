module Stimulus;
  
  reg I0, I1, I2, I3, S0, S1;
  wire Out;
  
  MUX inst1(I0, I1, I2, I3, S0, S1, Out);
  
  initial
  begin
    #5 I0 = 1; I1 = 0; I2 = 0; I3 = 0; S0 = 0; S1 = 0;
    #5 I0 = 0; I1 = 1; I2 = 0; I3 = 0; S0 = 0; S1 = 1;
    #5 I0 = 0; I1 = 0; I2 = 1; I3 = 0; S0 = 1; S1 = 0;
    #5 I0 = 0; I1 = 0; I2 = 0; I3 = 1; S0 = 1; S1 = 1;
  end
  
  initial
  $monitor($time, "I0 = %b, I1 = %b, I2 = %b, I3 = %b, S0 = %b, S1 = %b", I0, I1, I2, I3, S0, S1);
  
  initial
  #200  $stop;
  
endmodule