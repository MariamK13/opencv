import cv2 as cv
import numpy as np
import sys

def main():
	
	img = cv.imread(sys.argv[1], -1)
	if img is None:
		sys.exit("unable to read")
	rgbImg = cv.cvtColor(img, cv.COLOR_BGR2RGB)
	cv.imwrite("rgbImg.jpg", rgbImg)
	hsvImg = cv.cvtColor(img, cv.COLOR_BGR2HSV)
	cv.imwrite("hsvImg.jpg", hsvImg)
	labImg = cv.cvtColor(img, cv.COLOR_BGR2Lab)
	cv.imwrite("labImg.jpg", labImg)
	grayscaleImg = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
	cv.imwrite("grayscale.jpg", grayscaleImg)
	blurredImg = cv.GaussianBlur(img, (5, 5), 0, 0) #whole window
	cv.imwrite("blurred.jpg", blurredImg)
	customKernel = np.array([[0, -1, 0],
				             [-1, 5, -1],
            				 [0, -1, 0]], dtype=np.float32)
	customKernel /= 5.0
	sharpenedImg = cv.filter2D(blurredImg, -1, customKernel)
	cv.imwrite("sharpened.jpg", sharpenedImg)
	medianBlurredImg = cv.medianBlur(img, 5)
	cv.imwrite("median.jpg", medianBlurredImg)
	cv.imshow("RGB image", rgbImg)
	cv.imshow("HSV image", hsvImg)
	cv.imshow("Lab image", labImg)
	cv.imshow("Grayscale image", grayscaleImg)
	cv.imshow("Sharpened Image", sharpenedImg)
	cv.imshow("Median blurred image", medianBlurredImg)
	cv.waitKey(0)
	cv.destroyAllWindows()

if __name__ == "__main__":
	main()
