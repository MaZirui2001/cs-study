% 读入图像 pout.bmp 和 Girl.bmp
pout = imread('../image/pout.bmp');
girl = imread('../image/Girl.bmp');


% 理想低通滤波器
D0 = 30; % 截止频率
H = lpfilter('ideal', size(pout,1), size(pout,2), D0);
lp_pout = freqfilter(double(pout), H);
H = lpfilter('ideal', size(girl,1), size(girl,2), D0);
lp_girl = freqfilter(double(girl), H);

% 巴特沃斯低通滤波器
D0 = 30; % 截止频率
n = 5; % 阶数
H = lpfilter('btw', size(pout,1), size(pout,2), D0, n);
lp_pout_btw = freqfilter(double(pout), H);
H = lpfilter('btw', size(girl,1), size(girl,2), D0, n);
lp_girl_btw = freqfilter(double(girl), H);

% 高斯低通滤波器
D0 = 30; % 截止频率
H = lpfilter('gaussian', size(pout,1), size(pout,2), D0);
lp_pout_gauss = freqfilter(double(pout), H);
H = lpfilter('gaussian', size(girl,1), size(girl,2), D0);
lp_girl_gauss = freqfilter(double(girl), H);

% 显示不同低通滤波器处理后的图像
figure;
subplot(2,3,1), imshow(pout), title();
subplot
imshow(uint8(lp_pout)), title('Ideal LPF pout');
figure, imshow(uint8(lp_pout_btw)), title('Butterworth LPF pout');
figure, imshow(uint8(lp_pout_gauss)), title('Gaussian LPF pout');
figure, imshow(uint8(lp_girl)), title('Ideal LPF girl');
figure, imshow(uint8(lp_girl_btw)), title('Butterworth LPF girl');
figure, imshow(uint8(lp_girl_gauss)), title('Gaussian LPF girl');

% 加椒盐噪声和高斯噪声
noisy_girl_sp = imnoise(girl, 'salt & pepper', 0.05);
noisy_girl_gauss = imnoise(girl, 'gaussian', 0, 0.01);

% 显示加噪声后的图像
figure, imshow(noisy_girl_sp), title('Salt & pepper noisy girl');
figure, imshow(noisy_girl_gauss), title('Gaussian noisy girl');

% 对加噪声后的图像进行去噪
% 理想低通滤波器去噪
D0 = 30; % 截止频率
H = lpfilter('ideal', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0);
lp_noisy_girl_sp = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('ideal', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0);
lp_noisy_girl_gauss = freqfilter(double(noisy_girl_gauss), H);

% 巴特沃斯低通滤波器去噪
D0 = 30; % 截止频率
n = 5; % 阶数
H = lpfilter('btw', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0, n);
lp_noisy_girl_sp_btw = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('btw', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0, n);
lp_noisy_girl_gauss_btw = freqfilter(double(noisy_girl_gauss), H);

% 高斯低通滤波器去噪
D0 = 30; % 截止频率
H = lpfilter('gaussian', size(noisy_girl_sp,1), size(noisy_girl_sp,2), D0);
lp_noisy_girl_sp_gauss = freqfilter(double(noisy_girl_sp), H);
H = lpfilter('gaussian', size(noisy_girl_gauss,1), size(noisy_girl_gauss,2), D0);
lp_noisy_girl_gauss_gauss = freqfilter(double(noisy_girl_gauss), H);

% 显示去噪后的图像
figure, imshow(uint8(lp_noisy_girl_sp)), title('Ideal LPF denoised girl (salt & pepper)');
figure, imshow(uint8(lp_noisy_girl_sp_btw)), title('Butterworth LPF denoised girl (salt & pepper)');
figure, imshow(uint8(lp_noisy_girl_sp_gauss)), title('Gaussian LPF denoised girl (salt & pepper)');
figure, imshow(uint8(lp_noisy_girl_gauss)), title('Ideal LPF denoised girl (gaussian)');
figure, imshow(uint8(lp_noisy_girl_gauss_btw)), title('Butterworth LPF denoised girl (gaussian)');
figure, imshow(uint8(lp_noisy_girl_gauss_gauss)), title('Gaussian LPF denoised girl (gaussian)');

function H = lpfilter(type, M, N, D0, n)
    % LPFILTER Create a lowpass butterworth filter
    %   H = LPFILTER(TYPE, M, N, D0, N) creates a frequency domain lowpass
    %   filter H of the specified TYPE and size (M-by-N). D0 is the cutoff
    %   frequency and n is the order of the filter.
    %
    %   Supported filter types:
    %       - 'ideal': Ideal lowpass filter
    %       - 'btw': Butterworth lowpass filter
    %       - 'gaussian': Gaussian lowpass filter
    
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