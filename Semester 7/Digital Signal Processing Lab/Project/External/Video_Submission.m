close all
clear all
clc



% Chebyshev
% Low Pass Filter
f = 1000;
fs = 150;
fp = 40;
Rp = 3;
Rs = 60;
Wp = 2 * (fp / f);
Ws = 2 * (fs / f);
[n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
[num, dnum] = cheby1(n, Rp, Wp);
string = 'The order of your Filter is: ';
disp(string);
disp(n);
freqz(num, dnum);

% Butterworth
% Low Pass Filter
rp=0.2;
rs=20;
fp=200;
fs=600;
f=2000;
wp=2*(fp/f);
ws=2*(fs/f);
[n,wn]=buttord(wp,ws,rp,rs);
[b,a]=butter(n,wn);
[h,w]=freqz(b,a);
subplot(2,1,1);










% %Chebyshev
% % Band Pass Filter
% f = 1000;
% fp = [60 200];
% fs = [50 250];
% Rp = 3;
% Rs = 40;
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% [num, dnum] = cheby1(n, Rp, Wp);
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% freqz(num, dnum);

% % Butterworth
% % Band Pass Filter
% rp=0.2;
% rs=20;
% fp=200;
% fs=600;
% f=2000;
% wp=2*(fp/f);
% ws=2*(fs/f);
% [n,wn]=buttord(wp,ws,rp,rs);
% wn=[wp,ws];
% [b,a]=butter(n, wn);
% [h,w]=freqz(b,a);
% subplot(2,1,1);
% plot(w/pi,20*log(abs(h)));
% grid;
% xlabel("nf");
% ylabel("mag");
% title("mag response");
% subplot(2,1,2);
% plot(w/pi,angle(h));
% grid;
% xlabel("nf");
% ylabel("angle");
% title("phaseresponse");










% % Chebyshev
% % Band Stop Filter
% f = 1000;
% fp = [100 300];
% Rp = 5;
% Wp = 2 * (fp / f)
% n = 3;
% [num, dnum] = cheby1(n, Rp, Wp, 'stop');
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% freqz(num, dnum);

% % Butterworth
% % Band Stop Filter
% rp=0.2;
% rs=20;
% fp=200;
% fs=600;
% f=2000;
% wp=2*(fp/f);
% ws=2*(fs/f);
% [n,wn]=buttord(wp,ws,rp,rs);
% wn=[wp,ws];
% [b,a]=butter(n, wn, 'stop');
% [h,w]=freqz(b,a);










% % Chebyshev
% % High Pass Filter
% f = 1000;
% fp = 300;
% fs = 60;
% Rp = .5;
% Rs = 20;
% Wp = 2 * (fp / f);
% Ws = 2 * (fs / f);
% [n, Wp] = cheb1ord(Wp, Ws, Rp, Rs);
% [num, dnum] = cheby1(n, Rp, Wp, 'High');
% string = 'The order of your Filter is: ';
% disp(string);
% disp(n);
% freqz(num, dnum);

% % Butterworth
% % High Pass Filter
% rp=0.2;
% rs=20;
% fp=200;
% fs=600;
% f=2000;
% wp=2(fp/f);
% ws=2(fs/f);
% [n,wn]=buttord(wp,ws,rp,rs);
% [b,a]=butter(n, wn,'high');
% [h,w]=freqz(b,a);
% subplot(2,1,1);
% plot(w/pi,20*log(abs(h)));
% subplot(2,1,2);
% plot(w/pi,angle(h));