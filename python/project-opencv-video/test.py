import cv2 as cv
import numpy as np
import sys


def main():
	cap = cv.VideoCapture(0)
	if not cap.isOpened():	
   		sys.exit("Error opening video stream")
	flippedH = False
	flippedV = False
	rotated = False    
	
	while True:
		ret, frame = cap.read() 
		if not ret:
			sys.exit("unable to open")
		
		button = cv.waitKey(1)
		if button == ord('v'):
            		flippedV = not flippedV
		if flippedV:
			frame = cv.flip(frame, 0)
			cv.putText(frame, "Vertical", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
		
		button1 = cv.waitKey(1)
		if button1 == ord('h'):
			flippedH = not flippedH
			
		
		if flippedH:
			frame = cv.flip(frame, 1)
			cv.putText(frame, "horizontal", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
		
		button2 = cv.waitKey(1)
		if button2 == ord('r'):
			rotated = not rotated
		
		if rotated:
			frame = cv.rotate(frame, cv.ROTATE_90_CLOCKWISE)
			cv.putText(frame, "Rotated", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))		
		
		colorFrame = np.zeros_like(frame)
		button3 = cv.waitKey(1)
		if button3 == ord('o'):
			cv.imshow("Original", frame)
		elif  button3 == ord('g'):	
			cv.cvtColor(frame, colorFrame, cv.COLOR_BGR2GRAY)
			cv.putText(colorFrame, "Grayscale", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
			cv.imshow("grayScale video", colorFrame) 
		elif  button3 == ord('c'):
			cv.cvtColor(frame, colorFrame, cv.COLOR_BGR2HSV)
			cv.putText(colorFrame, "HSV", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
			cv.imshow("hsv video", colorFrame)
		elif  button3 == ord('b'):
			cv.cvtColor(frame, colorFrame, cv.COLOR_BGR2Lab)
			cv.putText(colorFrame, "LAB", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
			cv.imshow("lab video", colorFrame)
		elif  button3 == ord('p'):
			cv.blur(frame, frame, (10, 10))
			cv.putText(frame, "blurred", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
			cv.imshow("Blurred", frame)
		elif  button3 == ord('m'):
			cv.medianBlur(frame, colorFrame, 5)
			cv.putText(colorFrame, "medianblurred", (20, 50), cv.FONT_HERSHEY_TRIPLEX, 1.5, (100, 500, 100))
			cv.imshow("Median blurred", colorFrame)
			
		#drowing a rectangle and a circle
		cv.imshow("Original", frame)
		Start = (200, 200)
		End = (350, 400)
		cv.rectangle(frame, Start, End, (200, 100, 260), 5, cv.LINE_8)
		cv.circle(frame, (100, 300), 80, (255, 100, 100), 5, cv.LINE_8)
		cv.imshow("Regtangle and Circle", frame)
		
		if cv.waitKey(33) == ord('q'):
			break 
	cap.release()
	cv.destroyAllWindows()

if __name__ == "__main__":
	main() 
