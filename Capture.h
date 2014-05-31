#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class Capture
{
	VideoCapture capture;
	Mat frame;


public:
	Capture(int);
	Capture(string);
	~Capture();
	bool isOpened();
	void grabFrame(int, string);
	void grabVideo(int, string);

};

