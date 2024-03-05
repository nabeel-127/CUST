%% Task list
% tf
% bode(sys)
% [M, P] = bode(sys, w)
% [M, P] = bode(sys, [w])
% 10e3 rad/sec -> 10e4 rad/sec

%% Task 1
close all
clear all
clc
R = 220;
C = 1e-6;
num = [1];
denum = [R*C 1];
system = tf(num, denum)

%% Task 2
close all
clear all
clc
R = 220;
C = 1e-6;
num = [1];
denum = [R*C 1];
system = tf(num, denum)
fc = 1 / (2*pi*R*C);
w = 2*pi*fc;
bode(system), grid on

%% Task 3
close all
clear all
clc
R = 220;
C = 1e-6;
num = [1];
denum = [R*C 1];
system = tf(num, denum)
fc = 1 / (2*pi*R*C);
w = 2*pi*fc
[mag, phase] = bode(system, w)
bode(system), grid on

%% Task 4(Bode Plot)
close all
clear all
clc
R = 220;
C = 1e-6;
num = [1];
denum = [R*C 1];
system = tf(num, denum)
fc = 1 / (2*pi*R*C);
w = 2*pi*fc
[mag, phase] = bode(system, [1e6 .4e6 .1e6 30e3 10e3])
bode(system), grid on

%% Task 5
close all
clear all
clc
R = 220;
C = 1e-6;
num = [1];
denum = [R*C 1];
system = tf(num, denum)
fc = 1 / (2*pi*R*C);
w = 2*pi*fc;
[mag, phase] = bode(system, w)
[mag, phase] = bode(system, [1e6 .4e6 .1e6 30e3 10e3])
bode(system, {1e2 1e4}), grid on
% subplot(row, column, position)
subplot(2,1,1), bode(system), grid on
subplot(2,1,2), bode(system, {1e2 1e4}), grid on

