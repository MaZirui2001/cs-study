% 读入图像 pout.bmp 和 Girl.bmp
pout = imread('../image/pout.bmp');
girl = imread('../image/Girl.bmp');

% 理想低通滤波器
D0 = 50; % 截止频率
H = lpfilter('ideal', size(pout,1), size(pout,2), D0);
lp_pout = freqfilter(pout, H);
H = lpfilter('ideal', size(girl,1), size(girl,2), D0);
lp_girl = freqfilter(girl, H);

% 巴特沃斯低通滤波器
D0 = 50; % 截止频率
n = 5; % 阶数
H = lpfilter('btw', size(pout,1), size(pout,2), D0, n);
lp_pout_btw = freqfilter(pout, H);
H = lpfilter('btw', size(girl,1), size(girl,2), D0, n);
lp_girl_btw = freqfilter(girl, H);

% 高斯低通滤波器
D0 = 50; % 截止频率
H = lpfilter('gaussian', size(pout,1), size(pout,2), D0);
lp_pout_gauss = freqfilter(pout, H);
H = lpfilter('gaussian', size(girl,1), size(girl,2), D0);
lp_girl_gauss = freqfilter(girl, H);

% 显示不同低通滤波器处理后的图像
figure;
subplot(3,3,1), imshow(uint8(pout)), title('pout原图');
subplot(3,3,2), imshow(uint8(girl)), title('girl原图');
subplot(3,3,4), imshow(uint8(lp_pout)), title('理想低通滤波器');
subplot(3,3,5), imshow(uint8(lp_pout_btw)), title('巴特沃斯低通滤波器');
subplot(3,3,6), imshow(uint8(lp_pout_gauss)), title('高斯低通滤波器');
subplot(3,3,7), imshow(uint8(lp_girl)), title('理想低通滤波器');
subplot(3,3,8), imshow(uint8(lp_girl_btw)), title('巴特沃斯低通滤波器');
subplot(3,3,9), imshow(uint8(lp_girl_gauss)), title('高斯低通滤波器');

% 加椒盐噪声和高斯噪声
noisy_girl_sp = imnoise(girl, 'salt & pepper', 0.05);
noisy_girl_gauss = imnoise(girl, 'gaussian', 0, 0.01);

% 对加噪声后的图像进行去噪
% 理想低通滤波器去噪
D0 = 50; % 截止频率
H = lpfilter('ideal', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0);
lp_noisy_girl_sp = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('ideal', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0);
lp_noisy_girl_gauss = freqfilter(double(noisy_girl_gauss), H);

% 巴特沃斯低通滤波器去噪
D0 = 50; % 截止频率
n = 5; % 阶数
H = lpfilter('btw', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0, n);
lp_noisy_girl_sp_btw = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('btw', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0, n);
lp_noisy_girl_gauss_btw = freqfilter(double(noisy_girl_gauss), H);

% 高斯低通滤波器去噪
D0 = 50; % 截止频率
H = lpfilter('gaussian', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0);
lp_noisy_girl_sp_gauss = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('gaussian', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0);
lp_noisy_girl_gauss_gauss = freqfilter(double(noisy_girl_gauss), H);

% 显示去噪后的图像
figure, 
subplot(3,3,1), imshow(noisy_girl_sp), title('椒盐噪声');
subplot(3,3,2), imshow(noisy_girl_gauss), title('高斯噪声');
subplot(3,3,4); imshow(lp_noisy_girl_sp); title('椒盐噪声理想低通滤波器');
subplot(3,3,5); imshow(lp_noisy_girl_sp_btw); title('椒盐噪声巴特沃斯低通滤波器');
subplot(3,3,6); imshow(lp_noisy_girl_sp_gauss); title('椒盐噪声高斯低通滤波器');
subplot(3,3,7); imshow(lp_noisy_girl_gauss); title('高斯噪声理想低通滤波器');
subplot(3,3,8); imshow(lp_noisy_girl_gauss_btw); title('高斯噪声巴特沃斯低通滤波器');
subplot(3,3,9); imshow(lp_noisy_girl_gauss_gauss); title('高斯噪声高斯低通滤波器');

function H = lpfilter(type, M, N, D0, n)
    
    % Initialize filter
    % Compute distance from center for each pixel
    D = zeros(M, N);
    for i = 1:M
        for j = 1:N
            D(i,j) = sqrt((i-M/2-1)^2 + (j-N/2-1)^2);
        end
    end
    
    % Generate filter based on type
    switch type
        case 'ideal'
            H = double(D <= D0);
        case 'btw'
            if n == 0
                error('The order of Butterworth filter cannot be 0.');
            end
            H = 1./(1 + (D./D0).^(2*n));
        case 'gaussian'
            H = exp(-(D.^2)./(2*(D0^2)));
        otherwise
            error('Unsupported filter type.');
    end
    
    end
    function output = freqfilter(img, H)
        
        % Compute the Fourier transform of the input image
        F = fft2(double(img));
        
        % Shift the zero-frequency component to the center of the spectrum
        F = fftshift(F);
        
        % Apply the frequency domain filter to the spectrum
        G = F .* H;
        
        % Shift the zero-frequency component back to the top-left corner
        G = ifftshift(G);
        
        % Compute the inverse Fourier transform to obtain the filtered image
        output = real(ifft2(G));
        
        % Truncate any negative values and convert to uint8
        output(output < 0) = 0;
        output = uint8(output);
    
        end