//ASIC Design & FPGA
// Student Name : SYED HASSHAM ALI 
// Registration No.: BEE173071 
// Section No.: 1 
// Assignment No.: 3 
// Question No.: 4

module MULTIPLY_revision (
  input              clk, reset, start,
  input       [7:0]  A_in, B_in,
  output reg         done_tick,
  output wire [15:0] product 
);

localparam [1:0]
    idle  = 2'b00,
    op    = 2'b01,
    shift = 2'b10;

// signal declaration
reg       carry, next_carry;
reg [1:0] state, next_state;
reg [7:0] reg_PL, PL, reg_PH, PH, reg_a_multiplicand, a_multiplicand;   
reg [4:0] counter, next_counter;

assign product = {reg_PH, reg_PL};

always @(posedge clk, posedge reset)
  if (reset) begin
    state              <= idle;
    counter            <= 0;
    carry              <= 0;
    reg_PL             <= 0;
    reg_PH             <= 0;
    reg_a_multiplicand <= 0;
  end
  else begin
    state              <= next_state;
    carry              <= next_carry;
    counter            <= next_counter;
    reg_PL             <= PL;
    reg_PH             <= PH;
    reg_a_multiplicand <= a_multiplicand; 
  end

// next state logic 
always @ * begin
  done_tick      = 1'b0;
  PL             = reg_PL;
  PH             = reg_PH;
  a_multiplicand = reg_a_multiplicand; 
  next_carry     = carry;
  next_counter   = counter;
  next_state     = state;

  case(state)
    idle: begin
      if(start) begin
        next_counter   = 7; // load 7 for 8 bits down counter
        PL             = B_in; // load multiplier into lower half
        PH             = 8'b0; // clear upper half. 
        a_multiplicand = A_in; // load A multiplicand into register. 
        next_state     = op;
      end
    end

    op: begin
      if(reg_PL[0] == 1) begin
        {next_carry,PH} = reg_PH + reg_a_multiplicand;      // add A multiplicand to upper half with carry bit. 
      end
      next_counter = counter - 1;
      next_state   = shift;             
    end

    shift: begin
      {next_carry,PH,PL} = {carry,reg_PH,reg_PL} >> 1;  // putting everything back together and shifting everything to the right once. 
      if(next_counter == 0) begin
        next_state = idle;
      end
      else begin
        next_state = op;
      end
    end

    default: begin
      next_state = idle;
    end
  endcase
end


endmodule