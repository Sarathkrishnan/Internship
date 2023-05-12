import cv2
image1 = cv2.imread('watch.jpg')
image1 = cv2.resize(image1,(500,500))

image2 = cv2.imread('road.jpg')
image2 = cv2.resize(image2,(500,500))

dest_or = cv2.bitwise_or(image2,image1,mask=None)
cv2.imshow('Bitwise OR', dest_or)


if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows() 