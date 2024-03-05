close all
clear all
clc

% names = char('Region1', 'Region2', 'Distr. 3', 'Distr. 4');
% data = [1200, 500, 300, 120];
% pie(data)
% for i = 1:4
%     gtext(names(i,:));
% end
% title('Sales', 'fontsize', 15)

% x = randn(10000, 1);
% nbins = 25;
% h = histogram(x, nbins);

% x = -30:30;
% y = x.^2;
% bar(x,y);

% x = linspace(0, 8*pi, 300);
% y = x.*cos(x);
% comet(x, y, .6)

% t = 1:5
% r = t .* exp(i * t * 36 * (pi / 180));
% compass(r)

% t = 0: pi / 50 : 10 * pi;
% plot3(sin(t), cos(t), t, 'r.'), grid on,...
% xlabel('x'), ylabel('y'), zlabel('z'), title('3D Helix')

% x = [1 2 3 4];
% y = [5 6 7];
% [xx, yy] = meshgrid(x, y)
% x = linspace(-1, 1, 50);
% y = x;
% a = 3;
% c = 0.5;
% [xx, yy] = meshgrid(x, y)
% z = c * sin(2 * pi * a * sqrt(xx .^ 2 + yy .^ 2));
% surf(xx, yy, z), colorbar, xlabel('x'), ylabel('y'), zlabe('z'), title('f(x,y)=csin(2\pie\surf(x^2+y^2))')
% figure;
% mesh(xx, yy, z), colorbar, xlabel('x'), ylabel('y'), zlabe('z'), title('f(x,y)=csin(2\pie\surf(x^2+y^2))')

% % Activity 1
% x = -100: 100;
% 
% % y = 1 ./ x;
% % plot(x, y);
% % 
% % y = sin(x) .* cos(x);
% % plot(x, y);
% % 
% % y = 2 .* x.^2 - 3 .* x + 1;
% % plot(x, y);

% % Activity 2
% fi = 0:360;
% a = 1;
% b = 1.5;
% c = 0.3;
% s = a .* cos(fi) + sqrt(b.^2 - (a .* sin(30) - c).^2);
% plot(s)

% % Acitivity 3
% c = 5;
% t = 0: 10*pi;
% x = sin(t ./ 2 * c) .* cos(t);
% y = sin(t ./ 2 * c) .* sin(t);
% z = cos(t ./ 2 * c);
% plot3(x, y, z)

% % Activity 4
% [u,v] = meshgrid(0:2*pi, 0:2*pi);
% x = sin(u);
% y = sin(v);
% z = sin(u+v);
% surf(x, y, z)

% % Activity 5
% x1 = -1:0.1:5;
% y1 = exp(x1);
% x2 = -5: 0.1: 1
% y2 = exp(-1.*x2);
% hold on
% plot(x1, y1, '--b');
% plot(x2, y2, '--r');
% hold off

% % Activity 6
% R2 = 1000;
% R1 = 100:1:3000;
% Req = 1 ./ ((1 ./ R1) + (1 ./ R2));
% plot(Req)

% % Activity 7
% t = linspace(2, 20, 91);
% y = (exp(t ./ 20) .* cos(3 .* t)) ./ (t.^2 + 3);
% hold on
% plot(y, 'o-');
% plot(y, '--black');
% title('(exp(t/20) * cos(3*t)) / (t^2 + 3)');
% hold off

% bill = input('Enter the amount of the bill (in dollars): ');
% if (bill <= 10)
%     tip = 1.8;
% elseif ((bill > 10) && (bill <= 60))
%         tip = bill * .18;
% else
%     tip = bill * .2;
% end
% disp('The tip is (in dollars): ')
% disp(tip);

% choice = menu('Menu','Sine','Cosine','Quit');
% t = (0.0 : 0.05 : 1.0);
% switch(choice)
%     case 1
%         f=sin(2*pi*t);
%     case 2
%         f=cos(2*pi*t);
%     otherwise
%         disp('Quit');
%         return
% end
% figure(1)
% plot(t,f);

% % Activity 8
% x = 0: .1: 2*pi;
% hold on
% y1 = sin(x);
% y2 = (exp(x ./ 20) .* cos(3 .* x)) ./ (x.^2 + 3);
% plot(x, y1, x, y2);
% hold off









