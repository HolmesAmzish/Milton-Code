module testbench;
    reg A, B, C;
    wire F0, F1, F2, F3, F4, F5, F6, F7;

    // 实例化你写的模块
    decoder38 uut (
        .A(A), .B(B), .C(C),
        .F0(F0), .F1(F1), .F2(F2), .F3(F3), .F4(F4), .F5(F5), .F6(F6), .F7(F7)
    );

    // 生成输入信号
    initial begin
        $monitor("A=%b B=%b C=%b -> F0=%b F1=%b F2=%b F3=%b F4=%b F5=%b F6=%b F7=%b", A, B, C, F0, F1, F2, F3, F4, F5, F6, F7);
        
        A = 0; B = 0; C = 0; #10;
        A = 0; B = 0; C = 1; #10;
        A = 0; B = 1; C = 0; #10;
        A = 0; B = 1; C = 1; #10;
        A = 1; B = 0; C = 0; #10;
        A = 1; B = 0; C = 1; #10;
        A = 1; B = 1; C = 0; #10;
        A = 1; B = 1; C = 1; #10;
        
        $finish;
    end
endmodule
