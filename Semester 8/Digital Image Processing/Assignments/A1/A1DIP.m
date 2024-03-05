
A = imread('download.jpg');
%imshow(A)
I = rgb2gray(A);

%imshow(I)
[rows, columns, numberOfColorChannels] = size(I);
% Preallocate histogram.

h1 = zeros(1, 256)
%cast(h,'uint8');
for row = 1 : rows
    for col = 1 : columns
        % Now get the gray level
        grayLevel5 = I(row, col); % Assumes gray scale image.
        % Compute histogram, h.  The index is the gray level for uint8 and the gray level/256 for uint16.  Add 1 to the existing value.
       
        h1(grayLevel5+1)= h1(grayLevel5+1)+1
    end
end
 

h = zeros(1, 256)
%cast(h,'uint8');
for row = 1 : rows;
    for col = 1 : columns;
        % Now get the gray level
        s(row, col) = 100+((60/255)*(I(row, col)-1)); % Assumes gray scale image.
        % Compute histogram, h.  The index is the gray level for uint8 and the gray level/256 for uint16.  Add 1 to the existing value.
       grayLevel=s(row, col)
        h(grayLevel+1)= h(grayLevel+1)+1;
    end
end
 

z = zeros(1, 256)
%cast(h,'uint8');
for row = 1 : rows;
    for col = 1 : columns;
        % Now get the gray level
        s1(row, col) = 1+((255/60)*(s(row, col)-100)); % Assumes gray scale image.
        % Compute histogram, h.  The index is the gray level for uint8 and the gray level/256 for uint16.  Add 1 to the existing value.
       grayLevel1=s1(row, col)
        z(grayLevel1+1)= z(grayLevel1+1)+1;
    end
end
x=[1:1:256]

subplot(3,1,1)
plot(x,h1)
subplot(3,1,2)
plot(x,h)
subplot(3,1,3)
plot(x,z) 
