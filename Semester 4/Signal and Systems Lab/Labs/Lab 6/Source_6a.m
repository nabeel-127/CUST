close all
clear all
clc

% inc = 0.01;
% t = -10:inc:10;
% f = 0.1;
% t0 = 2;
% x = sin(2 * pi * f * t);
% y = sin(2 * pi * f * (t - t0));
% plot(t, x);
% hold on
% plot(t, y, 'r');
% grid on

% inc = 0.01;
% t = -10:inc:10;
% f = 0.1;
% t0 = 2;
% x = sin(2 * pi * f * t);
% y = sin(2 * pi * f * (t - t0));
% stem(t, x);
% hold on
% stem(t, y, 'r');
% grid on

% A lot of shit here

% x = [0: 10];
% n = 0: 10;
% stem(n, x);
% w = fliplr(x);
% n1 = -10: 0;
% figure
% stem(n1, w);

% n = -10: 10;
% x = @n * (n >= 0);
% xe - (x(n) + x(-n)) / 2;
% xo - (x(n) - x(-n)) / 2;

% n = -10: 10;
% x = @(n) n.* (n >= 0);
% xe = (x(n) + x(-n)) / 2;
% xo = (x(n) - x(-n)) / 2;
% subplot(3, 1, 2);
% stem(n, x(n));
% title('x(n)');
% subplot(3, 1, 2);
% stem(n, xe);

stem(n, abs(x));
angle(x);
 

% %a1
% n=-10:10;
% x=@(n) n.*(n>0);
% xe=(x(n)+x(-n))/2;
% xo=(x(n)-x(-n))/2;
% subplot(4,1,1)
% stem(n,x(n),'*r');
% title('X(n) Before');
% subplot(4,1,2)
% stem(n,xe,'*g');
% title('X(e)');
% subplot(4,1,3)
% stem(n,xo,'*b');
% title('X(o)');
% n2=xe+xo;
% subplot(4,1,4)
% stem(n,n2,'*g');

% % A3
% clc
% n=-10:0.5:10;
% w=100;
% A=1;
% m=0.5;
% xh=cos(w*n);
% xl=cos(n);
% stem(n,xl);
% figure
% y=A.*(1+m*xl).*(xh);
% stem(n,y);

% %A2
% n=-10:10;
% x=@(n) 1.*(n>=0)&(n<10);
% xe=(x(n)+x(-n))/2;
% xo=(x(n)-x(-n))/2;
% subplot(4,1,1)
% stem(n,x(n),'*r');
% title('X(n) Before');
% subplot(4,1,2)
% stem(n,xe,'*g');
% title('X(e)');
% subplot(4,1,3)
% stem(n,xo,'*b');
% title('X(o)');
% n2=xe+xo;
% subplot(4,1,4)
% stem(n,n2,'*g');











