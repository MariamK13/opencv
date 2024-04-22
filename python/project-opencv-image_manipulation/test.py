import cv2 as cv
import numpy as np
import sys

def main(): 
	img = cv.imread(sys.argv[1],-1)
	if img is None:
		sys.exit("unable to read")
	resizedImg = cv.resize(img, (500, 500))
	cv.imshow("Original", img)
	cv.imwrite("original_img.jpg", img)
	cv.imshow("Resized", resizedImg)
	cv.imwrite("resized_img.jpg", resizedImg)
	flippedH = cv.flip(resizedImg, 1)
	cv.imshow("Flipped Horizontally", flippedH)
	cv.imwrite("horizontal.jpg", flippedH)
	flippedV = cv.flip(resizedImg, 0)
	cv.imshow("Flipped Vertically", flippedV)
	cv.imwrite("vertical.jpg", flippedV)
	x, y, w, h = 80, 80, 300, 300
	croppedImg = resizedImg[y:y+h, x:x+w].copy()
	cv.imshow("Cropped Image", croppedImg)
	cv.imwrite("cropped.jpg", croppedImg)
	rotatedImg = cv.rotate(croppedImg, cv.ROTATE_90_CLOCKWISE)
	cv.imshow("Rotated Image", rotatedImg)
	cv.imwrite("rotated.jpg", rotatedImg)
	cv.waitKey(0)
	cv.destroyAllWindows()

if __name__ == "__main__":
	main()
