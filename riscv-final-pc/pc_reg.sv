module pc_reg #(
    parameter ADDRESS_WIDTH = 12
)(
    // inputs and corresponding outputs from left to right
    input logic [ADDRESS_WIDTH-1:0] ImmOp,
    input logic                     PCsrc,
    input logic                     clk,
    input logic                     rst,
    output logic [ADDRESS_WIDTH-1:0] PC
);

    logic [ADDRESS_WIDTH-1:0] branch_PC;
    logic [ADDRESS_WIDTH-1:0] inc_PC;

// intermediate output from the mux block, should be decided based on the value of PCsrc
logic [ADDRESS_WIDTH-1:0] next_PC;

// handles assigning individual control values to the mux block
assign branch_PC = PC + ImmOp;
assign inc_PC = PC + 12'h4;


// handles the mux block
assign next_PC = PCsrc ? branch_PC : inc_PC;

// handles the PC register, note that this part is clocked
always_ff @(posedge clk)
    // synchronous reset
    if(rst) PC <= {ADDRESS_WIDTH{1'b0}};
    else    PC <= next_PC;

endmodule
