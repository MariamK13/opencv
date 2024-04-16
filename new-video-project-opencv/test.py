import sys
import cv2

if len(sys.argv) != 2:
    print("Usage: python3 test.py <video_file>")
    sys.exit(1)

cv2.namedWindow("Example", cv2.WINDOW_AUTOSIZE)

cap = cv2.VideoCapture()

cap.open(sys.argv[1])

while True:
    ret, frame = cap.read()
    
    if not ret or frame is None:
        break
    
    cv2.imshow("Example", frame)
    
    if cv2.waitKey(33) >= 0:
        break

cap.release()
cv2.destroyAllWindows()
