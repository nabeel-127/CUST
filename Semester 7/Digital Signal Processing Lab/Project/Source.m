% [b,a] = cheby1(n,Rp,Wp)
% [b,a] = cheby1(n,Rp,Wp,ftype)

clc
close all;
clear all;

% wp1 = ;
% wp2 = ;
% ws1 = ;
% ws2 = ;
% 
% Rp = 2000;
% Rs = 8000;
% ws = .4;
% 
% Wp1 = (wp1 / (ws / 2));
% Wp2 = (wp2 / (ws / 2));
% 
% Ws1 = (ws1 / (ws / 2));
% Ws2 = (ws2 / (ws / 2));

%[n, Wp] = cheb1ord([Wp1 Wp2], [Ws1 Ws2], Rp, Rs);

% Wp = 40 / 500;
% Ws = 150 / 500;
% Rp = 3;
% Rs = 60;

% Wp = 2 * (fp / f)
% Ws = 2 * (fs / f)















% % Low Pass Filter
% 
% f = 1000;
% fs = 150;
% fp = 40;
% Rp = 3;
% Rs = 60;
% 
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% 
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% 
% [num, dnum] = cheby1(n, Rp, Wp);
% 
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% 
% freqz(num, dnum);















% % Band Pass Filter
% 
% f = 1000;
% fp = [60 200];
% fs = [50 250];
% Rp = 3;
% Rs = 40;
% 
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% 
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% 
% [num, dnum] = cheby1(n, Rp, Wp);
% 
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% 
% freqz(num, dnum);















% % Band Pass Filter
% 
% f = 1000;
% fp = [60 200];
% fs = [50 250];
% Rp = 3;
% Rs = 40;
% 
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% 
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% 
% [num, dnum] = cheby1(n, Rp, Wp);
% 
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% 
% freqz(num, dnum);















% % Band Stop Filter
% 
% f = 1000;
% fp = [100 300];
% fs = [50 99];
% Rp = 5;
% Rs = 40;
% 
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% 
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% 
% [num, dnum] = cheby1(n, Rp, Wp, 'stop');
% 
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% 
% freqz(num, dnum);















% Band Stop Filter

f = 1000;
fp = [100 300];

Rp = 5;

Wp = 2 * (fp / f)

n = 3;

[num, dnum] = cheby1(n, Rp, Wp, 'stop');

string = 'The order of your Filter is: ';
disp(string);
disp(n);

freqz(num, dnum);















% % High Pass Filter
% 
% f = 1000;
% 
% fp = 300;
% Rp = .5;
% 
% Wp = 2 * (fp / f);
% n = 9;
% 
% [z, p, k] = cheby1(n, Rp, Wp, 'high');
% 
% sos = zp2sos(z, p, k);
% 
% fvtool(sos, 'Analysis', 'freq')















% rp=0.2;
% rs=20;
% fp=200;
% fs=600;
% f=2000;
% wp=2*(fp/f);
% ws=2*(fs/f);
% [n,wn]=buttord(wp,ws,rp,rs);
% [b,a]=butter(n,wn,'high');
% [h,w]=freqz(b,a);
% subplot(2,1,1);
% plot(w/pi,20*log(abs(h)));
% subplot(2,1,2);
% plot(w/pi,angle(h));















rp=0.2;
rs=20;
fp=200;
fs=600;
f=2000;
wp=2*(fp/f);
ws=2*(fs/f);
[n,wn]=buttord(wp,ws,rp,rs);
wn=[wp,ws];
[b,a]=butter(n, wn, 'stop');
[h,w]=freqz(b,a);
subplot(2,1,1);
plot(w/pi,20*log(abs(h)));
subplot(2,1,2);  plot(w/pi,angle(h));





