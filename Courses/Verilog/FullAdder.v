module FullAdder(
    input a, b;
    input cin;
    output s;
    output cout;
);
    assign s = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);
endmodule