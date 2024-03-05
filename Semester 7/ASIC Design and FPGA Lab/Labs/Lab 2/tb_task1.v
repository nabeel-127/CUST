module task1tb;

 reg in1,in2,cin;
 wire sum,cout;

 FA Fulladder_inst(in1,in2,cin,sum,cout);

 initial
 begin
 #5 in1 = 0; in2 = 0; cin = 0;
 #5 in1 = 0; in2 = 0; cin = 1; 
 #5 in1 = 0; in2 = 1; cin = 0;
 #5 in1 = 0; in2 = 1; cin = 1;
 #5 in1 = 1; in2 = 0; cin = 0;
 #5 in1 = 1; in2 = 0; cin = 1;
 #5 in1 = 1; in2 = 1; cin = 0;
 #5 in1 = 1; in2 = 1; cin = 1;
 
 end
  
 initial
 $monitor( $time, "in1 = %b ,in2 = %b ,cin = %b ,sum = %b ,cout = %b" , in1,in2,cin,sum,cout);

 initial 
 #200  $stop;
  
endmodule

