#include "Dots.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
using namespace cv;




Dots::Dots(Mat pic)
{
	resize(pic, frame, Size(800, 600));
	point = Point (-1, -1);
}

string Dots::getPoints(string fileName)
{
	Mat tmpFrame;
	frame.copyTo(tmpFrame);
	stringstream ss;
	ss << "9 ";
	imshow(picName, tmpFrame);
	setMouseCallback(picName, onMouse, (void*)&point);
	for (int i = 0; i < 9; i++)
	{
		waitKey();
		circle(tmpFrame, point, 10, Scalar(255, 0, 0), -1);
		imshow(picName, tmpFrame);
		ss << point.x << " " << point.y << " ";
		point = Point(-1, -1);
	}
	imwrite(fileName, frame);
	destroyWindow(picName);
	return ss.str();
}


Dots::~Dots()
{
}
