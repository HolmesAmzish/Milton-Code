% Program: DataDrawing
% Date: 2024.05.15
% Description: Draw the data on a picture

data = load("ex1data1.txt");
x = data(:, 1);
y = data(:, 2);
m = length(y); % the number of training samples
figure;
plot(x, y, 'rx', 'MarkerSize', 10); %Plot the data
pause