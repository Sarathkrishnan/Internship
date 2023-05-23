import cv2 
import numpy as np 

image1 = cv2.imread('watch.jpg')
image1 = cv2.resize(image1,(500,500))

image2 = cv2.imread('road.jpg')
image2 = cv2.resize(image2,(500,500))

weightedSum = cv2.addWeighted(image1, 0.5, image2, 0.4, 1)

cv2.imshow('Weighted Image', weightedSum)

if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows()