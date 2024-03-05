close all
clear all
clc

% %1
% RGB = imread('Different scenes.jpg');
% imshow(RGB) 
% 
% %2
% R = RGB(:, :, 1);
% G = RGB(:, :, 2);
% B = RGB(:, :, 3);
% newImage = zeros(size(RGB, 1), size(RGB, 2), 'uint8');
% for x = 1: size(RGB, 1)
%     for y = 1: size(RGB, 2)
%         newImage(x, y) = (R(x, y) * .333) + (G(x, y) * .333) + (B(x, y) * .333);
%     end
% end
% imshow(newImage)
% 
% [r, c] = size(newImage);
% for i = 1: r
%     for j = 1: c
%         f = newImage(i, j)
%         if f <= 50
%             newImage(i, j) = 10;
%         elseif f > 50 && f <= 100
%             newImage(i, j) = 70;
%         elseif f > 100 && f <= 180
%             newImage(i, j) = 150;
%         elseif f > 180 && f <= 255
%             newImage(i, j) = 210;
%         else
%             newImage(i, j) = 0;
%         end
%     end
% end
% figure, imshow(newImage);
% title('Quantized Image');
%
%3
% imshow(uint8(I2))
% I = imread(newImage);
% [x,y] = size(I);
% for i = 2:x-1
%     for j = 2:y-1
%         sum = 0;
%         for ii = i-1:i+1  
%             for jj = j-1:j+1
%                 sum = sum + I(ii,jj);
%             end
%         end
%         I2(i,j) = ceil(sum/9);
%     end
% end
% imshow(I2);
%
%4
I = imread('Different scenes.jpg');
figure, imshow(I)
J = imnoise(I,'salt & pepper',0.02);
K = medfilt2(J);
imshowpair(J,K,'montage')