// program: output the position of 1
// date: 2024-09-28

module top_module (
    input [3:0] in,
    output reg[1:0] pos
);
    always @(*) begin
        pos = 2'b00;
        if (in[3]) pos = 2'd3;
        else if (in[2]) pos = 2'd2;
        else if (in[1]) pos = 2'd1;
        else if (in[0]) pos = 2'd0;
    end

endmodule