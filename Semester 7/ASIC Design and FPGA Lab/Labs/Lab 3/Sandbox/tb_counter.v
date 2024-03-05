module countertb;
reg clk,rst;
wire [3:0]q;

 counter countertb_inst(clk,rst,q);
 
 initial 
 
 begin
   
 clk = 1'b0;rst=1'b1;
 
 #5 rst = 1'b0;
 
 #5 rst = 1'b1;
 
 end
 
always 
begin
  #5 clk = ~clk;
end

 initial
 $monitor( $time, "clk = %b ,rst = %b ,cout=%d " ,clk,rst,q);

 initial 
 #200  $stop;
  
endmodule


