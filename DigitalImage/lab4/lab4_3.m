% 读入图像 pout.bmp 和 Girl.bmp
pout = imread('../image/pout.bmp');
girl = imread('../image/Girl.bmp');

% 理想高通滤波器
D0 = 10;
H = lpfilter('ideal', size(pout, 1), size(pout, 2), D0);
lp_pout = freqfilter(pout, H);
H = lpfilter('ideal', size(girl, 1), size(girl, 2), D0, 2);
lp_girl = freqfilter(girl, H);

% 巴特沃斯高通滤波器
D0 = 10;
n = 5;
H = lpfilter('btw', size(pout, 1), size(pout, 2), D0, n);
lp_pout_btw = freqfilter(pout, H);
H = lpfilter('btw', size(girl, 1), size(girl, 2), D0, n);
lp_girl_btw = freqfilter(girl, H);

% 高斯高通滤波器
D0 = 10;
H = lpfilter('gaussian', size(pout, 1), size(pout, 2), D0);
lp_pout_gaussian = freqfilter(pout, H);
H = lpfilter('gaussian', size(girl, 1), size(girl, 2), D0, n);
lp_girl_gaussian = freqfilter(girl, H);

% 显示结果
figure;
subplot(2, 4, 1), imshow(pout), title('pout原图');
subplot(2, 4, 2), imshow(lp_pout), title('理想高通滤波器');
subplot(2, 4, 3), imshow(lp_pout_btw), title('巴特沃斯高通滤波器');
subplot(2, 4, 4), imshow(lp_pout_gaussian), title('高斯高通滤波器');
subplot(2, 4, 5), imshow(girl), title('girl原图');
subplot(2, 4, 6), imshow(lp_girl), title('理想高通滤波器');
subplot(2, 4, 7), imshow(lp_girl_btw), title('巴特沃斯高通滤波器');
subplot(2, 4, 8), imshow(lp_girl_gaussian), title('高斯高通滤波器');

% % 先高频增强滤波再直方图均衡化
% H = fspecial('unsharp');
% lp_pout_enhance = imfilter(pout, H);
% lp_pout_enhance_hist = histeq(lp_pout_enhance);

% % 先直方图均衡化再高频增强滤波
% lp_pout_histeq = histeq(pout);
% lp_pout_histeq_enhance = imfilter(lp_pout_histeq, H);


% figure;
% subplot(3,2,1), imshow(pout), title('原图');
% subplot(3,2,3), imshow(lp_pout_enhance), title('高频增强滤波');
% subplot(3,2,4), imshow(lp_pout_enhance_hist), title('高频增强滤波+直方图均衡化');
% subplot(3,2,5), imshow(lp_pout_histeq), title('直方图均衡化');
% subplot(3,2,6), imshow(lp_pout_histeq_enhance), title('直方图均衡化+高频增强滤波');

filtered1 = imgaussfilt(pout, 3); % 高斯滤波
high_freq1 = pout - filtered1; % 高频信号
sharp1 = imsharpen(pout, 'Amount', 1, 'Radius', 2, 'Threshold', 0); % 对原图进行unsharp masking高频增强
enhanced1 = sharp1 + high_freq1; % 高频增强后的图像
enhanced1 = histeq(enhanced1); % 直方图均衡化

enhanced2_eq = histeq(pout); % 直方图均衡化
filtered2 = imgaussfilt(enhanced2_eq, 3); % 高斯滤波
high_freq2 = enhanced2_eq - filtered2; % 高频信号
sharp2 = imsharpen(enhanced2_eq, 'Amount', 1, 'Radius', 2, 'Threshold', 0); % 对直方图均衡化后的图像进行unsharp masking高频增强
enhanced2 = sharp2 + high_freq2; % 高频增强后的图像

figure;
subplot(1, 3, 1), imshow(pout), title('原图');
subplot(1, 3, 2), imshow(enhanced1), title('高频增强+直方图均衡化');
subplot(1, 3, 3), imshow(enhanced2), title('直方图均衡化+高频增强');


function H = lpfilter(type, M, N, D0, n)
    % 构造频域网格
    u = 0:(M-1);
    v = 0:(N-1);
    idx = find(u>M/2);
    u(idx) = u(idx)-M;
    idy = find(v>N/2);
    v(idy) = v(idy)-N;
    [V, U] = meshgrid(v, u);
    D = sqrt(U.^2 + V.^2);   % 构造距离矩阵

    % 构造滤波器
    switch type
        case 'ideal'
            H = double(D > D0);
        case 'btw'
            H = 1 ./ (1 + (D0./D).^(2*n));
        case 'gaussian'
            H = 1.0 - exp(-(D.^2)./(2*(D0^2)));
        otherwise
            error("Unknown filter type.");
    end
end

function output = freqfilter(img, H)
    % 傅里叶变换
    F = fft2(img);

    F = fftshift(F);

    % 频域滤波
    G = H .* F;

    % 傅里叶反变换
    G = ifftshift(G);

    output = ifft2(G);

    output(output < 0) = 0;
    output = uint8(real(output));
end