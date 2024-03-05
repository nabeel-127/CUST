close all
clear all
clc

% fs = 500000;
% f = 1000;
% nCyl = 5;
% t = 0: 1 / fs: 5 /f;
% x = cos(2 * pi * f * t);
% plot(t, x)
% hold on
% stem(t, x, 'r');
% title('Continuous Sinusoidal Signal');
% xlabel('Time(s)');
% ylabel('Amplitude');

% fs = 500000;
% f = 1000;
% nCyl = 5;
% t = 0: 1 / fs: 5 /f;
% x = cos(2 * pi * f * t);
% fs1 = 30e3;
% t1 = 0: 1 / fs1: 5 * 1 / f;
% x1 = cos(2 * pi * f * t1);
% fs2 = 50e3;
% t2 = 0: 1 / fs2: 5 * 1 / f;
% x2 = cos(2 * pi * f * t2);
% subplot(2, 1, 1);
% plot(t, x);
% hold on
% stem(t1, x1);
% subplot(2, 1, 2);
% plot(t, x);
% stem(t2, x2);
% hold off

% % Activity 3
% t = 0: 0.01: 10;
% f = 0.5;
% for i = 3: 25
%     x = cos(i * pi * f * t) + cos(2 * pi * f * t) + cos(i * 3 * pi * f * t);
% end
% plot(t, x);

% % Activity 4
% t = 0: 0.01: 10;
% f = 0.5;
% x = sin(t);
% for i = 3: 2: 100
%     x = x + sin(i * t) ./ i;
% end
% plot(t, x);



























