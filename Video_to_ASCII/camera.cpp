#include <opencv2/opencv.hpp>
#include <iostream>

//int main()
//{
//	cv::VideoCapture video(0);
//
//	if (!video.isOpened())
//	{
//		std::cout << "Camera is not available !" << std::endl;
//		return -1;
//	}
//
//	cv::Mat frame;
//	while (true)
//	{
//		video.read(frame);
//		cv::imshow("Camera", frame);
//
//		if (cv::waitKey(30) == 27) {
//			return 0;
//		}
//	}
//
//	return 0;
//}