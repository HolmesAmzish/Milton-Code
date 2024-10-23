module decoder38(
    input A, B, C,
    output reg F0, F1, F2, F3, F4, F5, F6, F7
);

    always @(*) begin
        {F0, F1, F2, F3, F4, F5, F6, F7} = 8'b00000000;
    
        case ({A, B, C})
            3'b000: F0 = 1;
            3'b001: F1 = 1;
            3'b010: F2 = 1;
            3'b011: F3 = 1;
            3'b100: F4 = 1;
            3'b101: F5 = 1;
            3'b110: F6 = 1;
            3'b111: F7 = 1;
            default: ;
        endcase
    end

endmodule
