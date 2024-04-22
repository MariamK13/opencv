#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv) {
	cv::Mat img = cv::imread(argv[1],-1);
	if(img.empty()) return -1;
	cv::Mat resizedImg;
	cv::resize(img, resizedImg, cv::Size(500, 500));
	cv::imshow("Original", img);
	cv::imwrite("original_img.jpg", img);
	cv::imshow("Resized", resizedImg);
	cv::imwrite("resized_img.jpg", resizedImg);
	cv::Mat flippedH;
	cv::flip(resizedImg, flippedH, 1);
	cv::imshow("Flipped Horizontally", flippedH);
	cv::imwrite("horizontal.jpg", flippedH);
	cv::Mat flippedV;
	cv::flip(resizedImg, flippedV, 0);
	cv::imshow("Flipped Vertically", flippedV);
	cv::imwrite("vertical.jpg", flippedV);
	cv::Rect roi(80, 80, 300, 300);
	cv::Mat croppedImg = resizedImg(roi).clone();
	cv::imshow("Cropped Image", croppedImg);
	cv::imwrite("cropped.jpg", croppedImg);
	cv::Mat rotatedImg;
	cv::rotate(croppedImg, rotatedImg, cv::ROTATE_90_CLOCKWISE);
	cv::imshow("Rotated Image", rotatedImg);
	cv::imwrite("rotated.jpg", rotatedImg);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
	
}
