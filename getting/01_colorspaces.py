import cv2

image = cv2.imread('road.jpg')
image = cv2.resize(image,(600,600))
# using opencv 'split' function seperating the color channels
B,G,R = cv2.split(image)

cv2.imshow('original image',image)
cv2.waitKey(0)

cv2.imshow('blue',B)
cv2.waitKey(0)

cv2.imshow('blue',G)
cv2.waitKey(0)

cv2.imshow('blue',R)
cv2.waitKey(0)

cv2.destroyAllWindows()