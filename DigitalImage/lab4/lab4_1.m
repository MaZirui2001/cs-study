% 读取图像并获取灰度图像
rect1 = imread('../image/Rect1.bmp');
rect2 = imread('../image/Rect2.bmp');

% 对图像进行二维傅里叶变换
F1 = fft2(rect1);
F2 = fft2(rect2);

% 将低频移到中心点
F1 = fftshift(F1);
F2 = fftshift(F2);

% 显示频谱
figure;
subplot(2,2,1);imshow(rect1);title('原始图像 1');
subplot(2,2,2);imshow(log(abs(F1)),[]);title('原始图像 1 的频谱');
subplot(2,2,3);imshow(rect2);title('原始图像 2');
subplot(2,2,4);imshow(log(abs(F2)),[]);title('原始图像 2 的频谱');

% 对 F1 和 F2 进行反变换得到图像
I1 = ifft2(F1);
I2 = ifft2(F2);

% 显示反变换后的图像
figure;
subplot(1,2,1);imshow(abs(I1),[]);title('用幅度进行反变换的图像 1');
subplot(1,2,2);imshow(abs(I2),[]);title('用幅度进行反变换的图像 2');

% 获取 F1 和 F2 的相位
phase1 = angle(F1);
phase2 = angle(F2);

% 根据相位构造新的复数数组
magnitude1 = abs(F1);
magnitude2 = abs(F2);
newF1 = magnitude1 .* exp(1i*phase1);
newF2 = magnitude2 .* exp(1i*phase2);

% 对新的复数数组进行反变换得到图像
newI1 = ifft2(newF1);
newI2 = ifft2(newF2);

% 显示反变换后的图像
figure;
subplot(1,2,1);imshow(abs(newI1),[]);title('用相位进行反变换的图像 1');
subplot(1,2,2);imshow(abs(newI2),[]);title('用相位进行反变换的图像 2');

% 获取 F1 和 F2 的共轭
conjF1 = conj(F1);
conjF2 = conj(F2);

% 将 F1 和 F2 的共轭置为其本身，构造新的复数数组
newF1 = F1 .* conjF1;
newF2 = F2 .* conjF2;

% 对新的复数数组进行反变换得到图像
newI1 = ifft2(newF1);
newI2 = ifft2(newF2);

% 显示反变换后的图像并与原始图像进行比较
figure;
subplot(2,2,1);imshow(rect1);title('原始图像 1');
subplot(2,2,2);imshow(abs(newI1),[]);title('共轭反变换后的图像 1');
subplot(2,2,3);imshow(rect2);title('原始图像 2');
subplot(2,2,4);imshow(abs(newI2),[]);title('共轭反变换后的图像 2');
