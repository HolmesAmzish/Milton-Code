%% KNN对鸢尾花数据集进行分类预�?
clc
clear
clf
load fisheriris %�β�����ݼ�
X = meas;
Y = species;
% rng(0);%�������ʼ��

%% ���ݼ�����
C = randperm(size(X,1));
Training_X=X(C(1:130),:);
Training_Y=Y(C(1:130),:);
Test_X=X(C(131:150),:);
Test_Y=Y(C(131:150),:);
ACC=zeros(1,1); %Ԥ��׼ȷ�ʳ�ʼ��
tic %�򿪼�ʱ������ʼ��ʱ
for k=1:200 % ������K����
    Mdl = fitcknn(Training_X,Training_Y,'NumNeighbors',k); % KNNģ��ѵ��
    Predict_Y = predict(Mdl,Test_X);                       % ģ��Ԥ��
    ACC(k)=0;
    for m=1:length(Test_Y)
        if isequal(Predict_Y{m},Test_Y{m})
            ACC(k)=ACC(k)+1/length(Test_Y); %Ԥ��׼ȷ�ʼ���
        end
    end
end
toc %��ʱ���رգ����ʱ��
plot(ACC) %��ͼ