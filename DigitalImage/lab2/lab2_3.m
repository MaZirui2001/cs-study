% 3、灰度直方图
% 要求：输入一幅图像，显示它的灰度直方图，可以根据输入的参数（上限、下限）显示特定范围的灰度直方图。
pic_pre = imread('../image/flower1.jpg');
pic = im2double(im2gray(pic_pre));
low = input("input low: ");
high = input("input high: ");
figure;
histogram(pic,"BinLimits",[low, high]);
