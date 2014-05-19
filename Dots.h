#pragma once
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <string>
#include <array>
using namespace std;
using namespace cv;

class Dots
{
	const string picName = "pic";
	Point point;
	Mat frame;

public:
	static void onMouse(int evt, int x, int y, int flags, void* param) 
	{
		if (evt == CV_EVENT_LBUTTONDOWN)
		{
			Point* ptPtr = (Point*)param;
			ptPtr->x = x;
			ptPtr->y = y;
//			cout << "leftClick " << x << " " << y << endl;
		}
	}

public:
	Dots(Mat);
	string getPoints(string);
	~Dots();
};

