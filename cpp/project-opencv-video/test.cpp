#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <ctime>

int main() {
	cv::VideoCapture cap(0);
	if(!cap.isOpened()){
   		std::cout << "Error opening video stream" << std::endl;
       		 return -1;
 	}
	
	bool flippedH = false;
	bool flippedV = false;
	bool rotated = false;
	int codec = cv::VideoWriter::fourcc('D', 'I', 'V', 'X'); //to be checked
	double fps = 15.0; //to be checked
	cv::VideoWriter writer; //to be checked
	std::string filename; //to be checked for error handling
	cv::Size frameSize(cap.get(cv::CAP_PROP_FRAME_WIDTH), cap.get(cv::CAP_PROP_FRAME_HEIGHT));//to be checked
	writer.open(filename, codec, fps, frameSize, true);//to be checked
	
	for(;;) {
		cv::Mat frame;
		cap >> frame;
		if(frame.empty()) break;
		int button = cv::waitKey(1);
		if (button == 'v') {
			flippedV = !flippedV;
		} 
		if (flippedV) {
			cv::flip(frame, frame, 0);
			cv::putText(frame, "Vertical", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
		}
		int button1 = cv::waitKey(1);
		if(button1 == 'h') {
			flippedH = !flippedH;
		}
		if(flippedH) {
			cv::flip(frame, frame, 1);
			cv::putText(frame, "horizontal", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
		}
		int button2 = cv::waitKey(1);
		if (button2 == 'r') {
			rotated = !rotated;
		}
		if (rotated) {
			cv::rotate(frame, frame, cv::ROTATE_90_CLOCKWISE);
			cv::putText(frame, "Rotated", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
			rotated = true;
		}
		
		cv::Mat colorFrame;
		int button3 = cv::waitKey(1);
		switch(button3){
			case 'o':
				cv::imshow("Original", frame);
				break;
			case 'g':	
				cv::cvtColor(frame, colorFrame, cv::COLOR_BGR2GRAY);
				cv::putText(colorFrame, "Grayscale", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
				cv::imshow("grayScale video", colorFrame);  
				break;
			case 'c':
				cv::cvtColor(frame, colorFrame, cv::COLOR_BGR2HSV);
				cv::putText(colorFrame, "HSV", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
				cv::imshow("hsv video", colorFrame);
				break;
			case 'b':
				cv::cvtColor(frame, colorFrame, cv::COLOR_BGR2Lab);
				cv::putText(colorFrame, "LAB", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
				cv::imshow("lab video", colorFrame);
				break;
			case 'p':
				cv::blur(frame, frame, cv::Size(10, 10));
				cv::putText(frame, "blurred", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
				cv::imshow("Blurred", frame);
				break;
			case 'm':
				cv::medianBlur(frame, colorFrame, 5);
				cv::putText(colorFrame, "medianblurred", cv::Point(20, 50), cv::FONT_HERSHEY_TRIPLEX, 1.5, cv::Scalar(100, 500, 100));
				cv::imshow("Median blurred", colorFrame);
				break;
			default:
				cv::imshow("Original", frame);
		}
		//drowing a rectangle and a circle
		cv::Point Start = cv::Point(200, 200);
		cv::Point End = cv::Point(350, 400);
		cv::rectangle(frame, Start, End, cv::Scalar(200, 100, 260), 5, cv::LINE_8);
		cv::circle(frame, cv::Point(100, 300), 80, cv::Scalar(255, 100, 100), 5, cv::LINE_8);
		cv::imshow("Regtangle and Circle", frame);
		//current time
		std::time_t now = time(0);
		tm *ltm = localtime(&now);
		char time[9];
		std::strftime(time, sizeof(time), "%H:%M:%S", ltm);
		cv::putText(frame, time, cv::Point(50,50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 0));
		writer.write(frame);
		cv::imshow("time", frame);
		if (cv::waitKey(33) == 'q') break;
	}
	cap.release();
	writer.release();
	cv::destroyAllWindows();
	return 0;
}
