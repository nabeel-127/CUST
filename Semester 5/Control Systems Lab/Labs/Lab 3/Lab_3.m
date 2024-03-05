%% Task 1
close all
clear all
clc
num = [25];
denum = [1 10 25];
system = tf(num, denum);
step(system)
stepinfo(system)

%% Task 2
close all
clear all
clc
num = [500];
denum = [1 14.14 100];
system = tf(num, denum);
step(system)
stepinfo(system)

%% Task 3
close all
clear all
clc
num = [500];
denum = [1 10 500];
system = tf(num, denum);
step(system)
stepinfo(system)

%% Task 4
close all
clear all
clc
num = [25];
denum = [1 0 25];
system = tf(num, denum);
roots(denum)
step(system)
stepinfo(system)

%% Task 5
close all
clear all
clc
num = [100];
denum = [1 0 -25];
system = tf(num, denum);
roots(denum)
step(system)
stepinfo(system)
