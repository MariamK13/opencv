#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv)
{
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty()) return -1;
	//putting text
	cv::Mat imgText = img.clone();
	cv::putText(imgText, "Forgotten Gods", cv::Point(50, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(300, 200, 200));
	cv::imshow("Original image", img);
	cv::imshow("Image with Text", imgText);
	//drowing a line
	cv::Point A = cv::Point(200, 80);
	cv::Point B = cv::Point(450, 80);
	cv::line(imgText, A, B, cv::Scalar(100, 100, 255), 4, cv::LINE_AA);
	cv::imshow("image with a line", imgText);
	//drowing a rectangle
	cv::Point Start = cv::Point(300, 200);
	cv::Point End = cv::Point(450, 350);
	cv::rectangle(imgText, Start, End, cv::Scalar(200, 100, 260), 5, cv::LINE_8);
	cv::imshow("image with a rectangle", imgText);
	//drowing a filled and non-filled circles
	cv::circle(imgText, cv::Point(200, 200), 100, cv::Scalar(0, 255, 0), -1, cv::LINE_AA);
	cv::Mat finalImg = imgText.clone();
	cv::imshow("image with a filled circle", imgText);
	cv::circle(finalImg, cv::Point(300, 300), 200, cv::Scalar(150, 0, 200), 1, cv::LINE_AA);
	cv::imshow("image with a non-filled circl", finalImg);
	cv::imwrite("finalImg.jpg", finalImg);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
	
