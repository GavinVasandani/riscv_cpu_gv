module pc_reg #(
    parameter ADDRESS_WIDTH = 32
)(
    input logic [ADDRESS_WIDTH-1:0] ImmOp,
    input logic [ADDRESS_WIDTH-1:0] jalr_PC, // comes from the alu block, is supposed to decide pc only when jalr is asserted
    input logic                     PCsrc,
    input logic [1:0]               J, // for jalr instruction
    input logic                     clk,
    input logic                     rst,
    output logic [ADDRESS_WIDTH-1:0] PC,
    output logic [ADDRESS_WIDTH-1:0] pc_alu
);
    logic [ADDRESS_WIDTH-1:0] inc_PC;
    logic [ADDRESS_WIDTH-1:0] alt_PC;
    logic PCsrc_inter;

assign PCsrc_inter = J[0] | PCsrc;


logic [ADDRESS_WIDTH-1:0] next_PC;

// handles assigning individual control values to the mux block
assign alt_PC = PC + ImmOp;
assign inc_PC = PC + 32'h4;

assign pc_alu = inc_PC; // for just the jalr and jal operations, writes the value of pc in a register

always_comb begin
    if (J[1]) next_PC = jalr_PC; // //specifially for the jalr instruction
    else begin
        next_PC = PCsrc_inter ? alt_PC : inc_PC; // PCsrc is 1 during regular jump or branch operation
    end 
end

always_ff @(posedge clk) begin
        if(rst) PC <= {ADDRESS_WIDTH{1'b0}};
        else    PC <= next_PC;
    end
endmodule
