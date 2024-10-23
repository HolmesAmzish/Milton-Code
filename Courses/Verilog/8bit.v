module mux2(
    input [3:0] d0,
    input [3:0] d1,
    input s,       
    output y
);
    assign y = s ? d1 : d0;
endmodule

module 8BitsMux2(
    input [7:0] d0,        
    input [7:0] d1,        
    input s,               
    output [7:0] y
);
    mux2 inst0(d0[3:0], d1[3:0], s, y[3:0]);
    mux2 inst1(d0[7:4], d1[7:4], s, y[7:4]);
endmodule