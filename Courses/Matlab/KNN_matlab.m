%% KNN瀵归涪灏捐姳鏁版嵁闆嗚繘琛屽垎绫婚娴?
clc
clear
clf
load fisheriris %鸢尾花数据集
X = meas;
Y = species;
% rng(0);%随机数初始化

%% 数据集划分
C = randperm(size(X,1));
Training_X=X(C(1:130),:);
Training_Y=Y(C(1:130),:);
Test_X=X(C(131:150),:);
Test_Y=Y(C(131:150),:);
ACC=zeros(1,1); %预测准确率初始化
tic %打开计时器，开始计时
for k=1:200 % 超参数K设置
    Mdl = fitcknn(Training_X,Training_Y,'NumNeighbors',k); % KNN模型训练
    Predict_Y = predict(Mdl,Test_X);                       % 模型预测
    ACC(k)=0;
    for m=1:length(Test_Y)
        if isequal(Predict_Y{m},Test_Y{m})
            ACC(k)=ACC(k)+1/length(Test_Y); %预测准确率计算
        end
    end
end
toc %计时器关闭，输出时间
plot(ACC) %绘图