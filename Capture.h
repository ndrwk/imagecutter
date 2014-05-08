#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Capture
{
	VideoCapture capture;
	Mat frame;


public:
	Capture(int);
	~Capture();
	bool isOpened();
	void grabFrame(int limit, string);

};

