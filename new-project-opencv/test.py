import cv2
import sys

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py <image_path>")
        return -1

    img = cv2.imread(sys.argv[1], cv2.IMREAD_UNCHANGED)
    if img is None:
        print("Error: Could not read image.")
        return -1

    cv2.namedWindow("Example1", cv2.WINDOW_AUTOSIZE)
    cv2.imshow("Example1", img)
    cv2.waitKey(0)
    cv2.destroyWindow("Example1")
    return 0

if __name__ == "__main__":
    sys.exit(main())

