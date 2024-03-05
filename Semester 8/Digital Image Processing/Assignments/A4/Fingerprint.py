img=cv2.imread('fingerprint.png')
print(img)

[[[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]

 [[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]

 [[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]

 ...

 [[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]

 [[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]

 [[255 255 255]
  [255 255 255]
  [255 255 255]
  ...
  [255 255 255]
  [255 255 255]
  [255 255 255]]]
  
  
from google.colab.patches import cv2_imshow
cv2_imshow(img)


gray=cv2.cvtColor(img, cv2.COLOR_BGR2GRAY )
cv2_imshow(gray)


dst = cv2.medianBlur(img,5)

cv2_imshow(dst)


kernel = np.ones((5,5), np.uint8)
img_erosion = cv2.erode(dst, kernel, iterations=1)
cv2_imshow(img_erosion)