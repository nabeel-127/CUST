module flip(clk,rst,d,q,qn);

input clk,rst,d;
output reg q,qn;

always @ (posedge clk ,negedge rst)

begin

if(!rst)
  begin
    q <= 1'b0;
    qn <= 1'b1;
  end
 else
   begin
     q <= d;
     qn <= ~d;
   end
   
end

endmodule





