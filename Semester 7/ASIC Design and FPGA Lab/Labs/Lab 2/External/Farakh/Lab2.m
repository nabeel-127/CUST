% fs=10;
% n=0: (1/fs): 0.3;
% N=1024;
% f=125;
% F = [-N/2+1 : N/2]*fs/N;
% 
%  x=cos(2*pi*f*n);
%  y=abs(fftshift(fft(x,N)));
%  
% n2= length(x)/2;
% 
% m = [1 2 3 4 5 6];
% y1=fftshift(m);
% plot(m)
% hold on
%  plot(F,y/n2)
% hold on
% stem(n,x)



% load handel.mat
% filename = 'handel.wav';
% audiowrite(filename,y,Fs);
% clear y Fs


load handel.mat
audiowrite('audio.wav',y,Fs);
player= audioplayer (y,Fs)