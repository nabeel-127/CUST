module Stimulus;
  
  reg input1, input2, Cin;
  wire sum, Cout;
  
  FA FA_inst(input1, input2, Cin, sum, Cout);
  
  initial
  begin
  #5 input1 = 1'b0; input2 = 1'b0; Cin = 1'b0;
  #5 input1 = 0; input2 = 0; Cin = 1; 
  #5 input1 = 0; input2 = 1; Cin = 0;  
  #5 input1 = 0; input2 = 1; Cin = 1;  
  #5 input1 = 1; input2 = 0; Cin = 0;
  #5 input1 = 1; input2 = 0; Cin = 1;
  #5 input1 = 1; input2 = 1; Cin = 0;
  #5 input1 = 1; input2 = 1; Cin = 1;
  end
  
  initial
  $monitor($time, "Input1 = %b, Input2 = %b, Cin = %b, Sum = %b, Cout = %b", input1, input2, Cin, sum, Cout);
  
  initial
  #200  $stop;
  
endmodule



