#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

void detectDisplay(cv::Mat frame);

cv::CascadeClassifier face_cascade;

int main()
{
  std::string face_cascade_name = "/home/mariam/libdc1394-2.2.6/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";

  if (!face_cascade.load(face_cascade_name)) {
	  std::cout <<  "Error loading face cascade\n";
	  return -1;
  };

  cv::VideoCapture capture(0);
  if(!capture.isOpened()) 
  {
	std::cout << "Error opening video capture\n";
	return -1;
  }

  cv::Mat frame;
  while(capture.read(frame))
  {
	if(frame.empty()) {
		std::cout << "No captured frame -- Break!\n";
		break;
	}
	detectDisplay(frame);
	if (cv::waitKey(10) == 'q') 
	{
		break;
	}
  }
  return 0;
 
}

void detectDisplay(cv::Mat frame)
{
	cv::Mat frame_gray;
	cv::cvtColor(frame, frame_gray, cv::COLOR_RGB2GRAY);

	std::vector<cv::Rect> faces;
	face_cascade.detectMultiScale (frame_gray, faces);
	for (size_t i = 0; i < faces.size(); ++i) {
		cv::Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
		cv::ellipse(frame, center, cv::Size(faces[i].width/2, faces[i].height/2), 0, 0, 360, cv::Scalar(0, 0, 255), 6); 
		cv::Mat faceROI = frame_gray(faces[i]);
		cv::rectangle(frame, cv::Point(faces[i].x, faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), cv::Scalar(200, 100, 0), 5, cv::LINE_8);
	}

	cv::imshow("Capture - face detection", frame);
}


