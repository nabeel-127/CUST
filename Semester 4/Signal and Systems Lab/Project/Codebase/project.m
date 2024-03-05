
%%The Execution Of File May Takes Acdbout 15-20 Seconds

fs=44100; %Sampling Frequency


[voice,fs]=audioread('last.wav');
dft_voice=abs(fft(voice)); %Fourier Trransform of Voice Signal
subplot(4,1,1), plot(dft_voice);title('Voice Signal'); %Frequency Spectrum of voice signal






%noisy=voice+0.2.*randn(size(voice)); %Adding Random noise to the signal
noisy=awgn(voice,10); %Adding Guassian Noise to the Signal
dft_noisy=abs(fft(noisy)); %Fourier Trransform of noisy Signal
subplot(4,1,2),plot(dft_noisy);title('Noisy Signal');%Frequency Spectrum of noisy signal

y1=filter(low1,noisy);
dft_y1=abs(fft(y1)); %Fourier Trransform of LowPass Filtered Signal
subplot(4,1,3),plot(dft_y1);title('LowPass Filtered Signal');%Frequency Spectrum of LowPass Filtered signal

y2=filter(bandpass,noisy);
dft_y2=abs(fft(y2)); %Fourier Trransform of BandPass Filtered Signal
subplot(4,1,4),plot(dft_y2);title('BandPass Filtered Signal');%Frequency Spectrum of bandPass filtered signal

% sound(voice,fs);
% sound(noisy,fs);
% sound(y1,fs); %LowPass Filtered Sound
% sound(y2,fs);%BandPass Filtered Sound


choice = menu('Menu','Original voice', 'Noisy signal', 'Lowpass', 'Highpass');
%generate time and trig function vectors
%t = (0.0 : 0.05 : 1.0);
switch (choice)
 case 1 % sine
 sound(voice,fs);
 %goto choice
 case 2 % cosine
 sound(noisy,fs);
 case 3
 sound(y1,fs);
 case 4
 sound(y2,fs);
 otherwise
 return
end


choice = menu('Menu','Original voice', 'Noisy signal', 'Lowpass', 'Highpass');
%generate time and trig function vectors
%t = (0.0 : 0.05 : 1.0);
switch (choice)
 case 1 % sine
 sound(voice,fs);
 case 2 % cosine
 sound(noisy,fs);
 case 3
 sound(y1,fs);
 case 4
 sound(y2,fs);
 otherwise
 return
end


choice = menu('Menu','Original voice', 'Noisy signal', 'Lowpass', 'Highpass');
%generate time and trig function vectors
%t = (0.0 : 0.05 : 1.0);
switch (choice)
 case 1 % sine
 sound(voice,fs);
 case 2 % cosine
 sound(noisy,fs);
 case 3
 sound(y1,fs);
 case 4
 sound(y2,fs);
 otherwise
 return
end

choice = menu('Menu','Original voice', 'Noisy signal', 'Lowpass', 'Highpass');
%generate time and trig function vectors
%t = (0.0 : 0.05 : 1.0);
switch (choice)
 case 1 % sine
 sound(voice,fs);
 case 2 % cosine
 sound(noisy,fs);
 case 3
 sound(y1,fs);
 case 4
 sound(y2,fs);
 otherwise
 return
end