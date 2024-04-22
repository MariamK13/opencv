#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv)
{	
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty()) return -1;
	cv::Mat rgbImg;
	cv::cvtColor(img, rgbImg, cv::COLOR_BGR2RGB);
	cv::imwrite("rgbImg.jpg", rgbImg);
	cv::Mat hsvImg;
	cv::cvtColor(img, hsvImg, cv::COLOR_BGR2HSV);
	cv::imwrite("hsvImg.jpg", hsvImg);
	cv::Mat labImg;
	cv::cvtColor(img, labImg, cv::COLOR_BGR2Lab);
	cv::imwrite("labImg.jpg", labImg);
	cv::Mat grayscaleImg;
	cv::cvtColor(img, grayscaleImg, cv::COLOR_BGR2GRAY);
	cv::imwrite("grayscale.jpg", grayscaleImg);
	cv::Mat blurredImg;
	cv::GaussianBlur(img, blurredImg, cv::Size(5, 5), 0, 0); //whole window
	cv::imwrite("blurred.jpg", blurredImg);
	cv::Mat customKernel = (cv::Mat_<float>(3,5) << 1, 4, 7, 4, 1, 7, 26, 9, 26, 7, 1, 4, 7, 4, 1);
	customKernel /= 15.0;
	cv::Mat sharpenedImg;
	cv::filter2D(blurredImg, sharpenedImg, -1, customKernel);
	cv::imwrite("sharpened.jpg", sharpenedImg);
	cv::Mat medianBlurredImg;
	cv::medianBlur(img, medianBlurredImg, 5);
	cv::imwrite("median.jpg", medianBlurredImg);
	cv::imshow("RGB image", rgbImg);
	cv::imshow("HSV image", hsvImg);
	cv::imshow("Lab image", labImg);
	cv::imshow("Grayscale image", grayscaleImg);
	cv::imshow("Sharpened Image", sharpenedImg);
	cv::imshow("Median blurred image", medianBlurredImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

}
