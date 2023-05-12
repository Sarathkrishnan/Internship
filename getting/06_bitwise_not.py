import cv2 
import numpy as np 

img1 = cv2.imread('road.jpg')  
img2 = cv2.imread('watch.jpg')
img1 = cv2.resize(img1,(500,500))
img2 = cv2.resize(img2,(500,500))

dest_not1 = cv2.bitwise_not(img1, mask=None)

dest_not2 = cv2.bitwise_not(img2, mask=None)


cv2.imshow('Bitwise NOT on image 1', dest_not1)
cv2.imshow('Bitwise NOT on image 2', dest_not2)

if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows() 