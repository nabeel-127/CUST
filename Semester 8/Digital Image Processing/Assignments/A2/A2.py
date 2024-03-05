from PIL import Image
import numpy as np
from scipy.ndimage.filters import median_filter
import cv2
from matplotlib import pyplot as plt


#1
def imtoarr(im):
    row,col = im.size
    data=[] 
    pixels=im.load()
    for i in range(row):
        for j in range(col):
            data.append(pixels[i,j]+(i,j))
    return data


#2
def rgbtogray(img):
    pix = img.load()
    cols,rows = img.size
    mat = [[0 for x in range(cols)] for y in range(rows)]
    for x in range(cols):
        for y in range(rows):
            try:
                mat[x][y] = 0
            except:
                break
    for x in range(cols):
        for y in range(rows):
            val = img.getpixel((x, y))
            try:
                mat[x][y] = val[2]*0.299+val[1]*0.587+val[0]*0.114
            except:
                break
    return mat


#3
def averageFilter(img):
    cols,rows = img.shape
    mask = np.ones([3, 3], dtype = int)
    mask = mask / 9
    img_new = np.zeros([cols, rows])
    i=2
    while(i!=0):
        for i in range(1, cols-1):
            for j in range(1, rows-1):
                temp = img[i-1, j-1]*mask[0, 0]+img[i-1, j]*mask[0, 1]+img[i-1, j + 1]*mask[0, 2]+img[i, j-1]*mask[1, 0]+ img[i, j]*mask[1, 1]+img[i, j + 1]*mask[1, 2]+img[i + 1, j-1]*mask[2, 0]+img[i + 1, j]*mask[2, 1]+img[i + 1, j + 1]*mask[2, 2]
                img_new[i, j] = temp
        i=i-1
    img_new = img_new.astype(np.uint8)
    return img_new


#4
def gaussianFilter(size=3,sigma=1):
    center=(int)(size/2)
    kernel=np.zeros((size,size))
    for i in range(size):
        for j in range(size):
            diff=np.sqrt((i-center)**2+(j-center)**2)
            kernel[i,j]=np.exp(-(diff**2)/(2*sigma**2))
    return kernel/np.sum(kernel)


#5
def difference(img1, img2):
    row1,col1 = img1.size
    data1=[] 
    pixels=img1.load()
    for i in range(row1):
        for j in range(col1):
            data1.append(pixels[i,j]+(i,j))
    row2,col2 = img2.size
    data2=[] 
    pixels=img2.load()
    for i in range(row2):
        for j in range(col2):
            data2.append(pixels[i,j]+(i,j))
    diff = data1 - data2
    return diff


#6
def medianFilter(img):
    m, n = img.shape
    img_new1 = np.zeros([m, n])
    for i in range(1, m-1):
        for j in range(1, n-1):
            temp = [img[i-1, j-1],
                    img[i-1, j],
                    img[i-1, j + 1],
                    img[i, j-1],
                    img[i, j],
                    img[i, j + 1],
                    img[i + 1, j-1],
                    img[i + 1, j],
                    img[i + 1, j + 1]]
            temp = sorted(temp)
            img_new1[i, j]= temp[4]
    img_new1 = img_new1.astype(np.uint8)
    return img_new1


#7
def medianFilter2(img):
    m, n = img.shape
    img_new1 = np.zeros([m, n])
    for i in range(1, m-1):
        for j in range(1, n-1):
            temp = [img[i-1, j-1],
                    img[i-1, j],
                    img[i-1, j + 1],
                    img[i, j-1],
                    img[i, j],
                    img[i, j + 1],
                    img[i + 1, j-1],
                    img[i + 1, j],
                    img[i + 1, j + 1],
                    img[i + 1, j-1],
                    img[i + 1, j],
                    img[i + 1, j + 1],
                    img[i + 1, j-1],
                    img[i + 1, j],
                    img[i + 1, j + 1]]
            temp = sorted(temp)
            img_new1[i, j]= temp[4]
    img_new1 = img_new1.astype(np.uint8)
    return img_new1


def difference2(img1, img2):
    row1,col1 = img1.size
    data1=[] 
    pixels=img1.load()
    for i in range(row1):
        for j in range(col1):
            data1.append(pixels[i,j]+(i,j))
    row2,col2 = img2.size
    data2=[] 
    pixels=img2.load()
    for i in range(row2):
        for j in range(col2):
            data2.append(pixels[i,j]+(i,j))
    diff = data1 - data2
    return diff


#8
def enhancement(img):
    cols,rows = img.shape
    mask = np.ones([3, 3], dtype = int)
    mask = mask / -9
    img_new = np.zeros([cols, rows])
    for i in range(1, cols-1):
        for j in range(1, rows-1):
            temp = img[i-1, j-1]*mask[0, 0]+img[i-1, j]*mask[0, 1]+img[i-1, j + 1]*mask[0, 2]+img[i, j-1]*mask[1, 0]+ img[i, j]*mask[1, 1]+img[i, j + 1]*mask[1, 2]+img[i + 1, j-1]*mask[2, 0]+img[i + 1, j]*mask[2, 1]+img[i + 1, j + 1]*mask[2, 2]

            img_new[i, j] = temp
    img_new = img_new.astype(np.uint8)
    return img_new


#9
def unsharp(img):
    gray_image = median_filter(img, 1)
    lap = cv2.Laplacian(gray_image,cv2.CV_64F)
    sharp = img - 0.7*lap
    return sharp



image = Image.open('E:/BACKUP/UNIVERSITY FILES/8th Semester/dip/Different scenes.jpg')
image2 = cv2.imread('E:/BACKUP/UNIVERSITY FILES/8th Semester/dip/Different scenes.jpg',0)
A = imtoarr(image)
B = rgbtogray(image)
C = averageFilter(image2)
D = gaussianFilter(5,1)
E = difference(C, D)
F = medianFilter(image2)
G = medianFilter2(image2)
diff = difference2(F, G)
H = enhancement(B)
H = unsharp(B)