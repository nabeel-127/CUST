A = imread('Capture.jpg');
imshow(A);

I = rgb2gray(A);
imshow(I);

[rows, columns] = size(I);
h = zeros(1, 256);
%cast(h,'uint8');
for row = 1 : rows
    for col = 1 : columns
        s = I(row, col); 
        h(s+1) = h(s+1)+1;
    end
end

h1 = zeros(1, 256);
% cast(h1,'uint8');
for row = 1 : rows
    for col = 1 : columns
        b(row, col) = 100+((60/256)*(I(row, col)-1)); 
        s1=b(row, col);
        h1(s1+1)= h1(s1+1)+1;
    end
end
imshow(b)
h2 = zeros(1, 256);
%cast(h2,'uint8');
for row = 1 : rows
    for col = 1 : columns
        c(row, col) = 1+((256/60)*(b(row, col)-100));
        s2=c(row, col);
        h2(s2+1)= h2(s2+1)+1;
    end
end
imshow(c)

for r = 1 : 256
    h3(r)=h1(r)/(rows*columns);
end

x=[1:1:256];
subplot(4,1,1)
plot(x,h)
title('Original histogram of B');
subplot(4,1,2)
plot(x,h1)
title('histogram of C');
subplot(4,1,3)
plot(x,h2) 
title('histogram of D');
subplot(4,1,4)
plot(x,h3)
title('histogram of E');