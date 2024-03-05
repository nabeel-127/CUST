import cv2
import numpy as np
from scipy import ndimage

image=cv2.imread('Different scenes.jpg')
cv2.imshow('image',image)
enlarged = cv2.resize(image, (image.shape[0]*2,image.shape[0]*2), interpolation=cv2.INTER_AREA)

rotate = ndimage.rotate(enlarged, 45)
cv2.imshow('resize',enlarged)
cv2.imshow('rotate',rotate)

yuv_image=cv2.cvtColor(image, cv2.COLOR_BGR2YUV)
cv2.imshow('image_yuv',yuv_image)
enlarged_yuv = cv2.resize(yuv_image, (image.shape[0]*2,image.shape[0]*2), interpolation=cv2.INTER_AREA)

rotate_yuv = ndimage.rotate(enlarged_yuv, 45)
cv2.imshow('resize_yuv',enlarged_yuv)
cv2.imshow('rotate_yuv',rotate_yuv)






cv2.waitKey(0)
cv2.destroyAllWindows()
