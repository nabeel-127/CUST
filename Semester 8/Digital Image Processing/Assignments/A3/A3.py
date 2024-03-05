import cv2
import numpy as np

image=cv2.imread('Different scenes.jpg',0)

# applying fast fourier transform
fast = np.fft.fft(image).real

cv2.imshow('fast fourier',fast)
lap = cv2.Laplacian(image,ddepth=5)
im3 = fast*lap
cv2.imshow('im3',im3)
inverse = np.fft.ifft(lap).real
cv2.imshow('inverse fourier',inverse)

blur = cv2.blur(fast,(5,5))
cv2.imshow('blur',blur)

cv2.waitKey(0)
cv2.destroyAllWindows()
