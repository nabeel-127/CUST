module sevensegcontroller(clk,anode,cathode,counter);
input wire clk;
input wire [3: 0] counter;
output wire [3:0] anode;
output wire [7:0] cathode;

wire [3:0] d1,d2,d3,d4;
wire refreshclock;
wire [1:0] refreshcounter;


Clock_divider g1(clk,refreshclock);

refreshcounter g2(refreshclock,refreshcounter);

anode_control g3(refreshcounter,anode);

condition g4(counter,d1,d2,d3,d4);

BCD_control g5(d1,d2,d3,d4,refreshcounter,dout);

BCD_cathode g6(dout,cathode);


endmodule