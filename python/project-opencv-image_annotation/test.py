import cv2 as cv
import sys
import numpy as np

def main():
	img = cv.imread(sys.argv[1],-1)
	if img is None:
		sys.exit("unable to read")
	#putting text
	imgText = img.copy();
	cv.putText(imgText, "Forgotten Gods", (50, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (300, 200, 200))
	cv.imshow("Original image", img)
	cv.imshow("Image with Text", imgText)
	#drowing a line
	A = (200, 80)
	B = (450, 80)
	cv.line(imgText, A, B, (100, 100, 255), 4, cv.LINE_AA)
	cv.imshow("image with a line", imgText)
	#drowing a rectangle
	Start = (300, 200)
	End = (450, 350)
	cv.rectangle(imgText, Start, End, (200, 100, 260), 5, cv.LINE_8)
	cv.imshow("image with a rectangle", imgText)
	#drowing a filled and non-filled circles
	cv.circle(imgText, (200, 200), 100, (0, 255, 0), -1, cv.LINE_AA)
	finalImg = imgText.copy()
	cv.imshow("image with a filled circle", imgText)
	cv.circle(finalImg, (300, 300), 200, (150, 0, 200), 1, cv.LINE_AA)
	cv.imshow("image with a non-filled circl", finalImg)
	cv.imwrite("finalImg.jpg", finalImg)
	cv.waitKey(0)
	cv.destroyAllWindows()
	
if __name__ == "__main__":
	main()
	
