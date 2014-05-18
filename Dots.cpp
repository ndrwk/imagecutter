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

string Dots::getPoints()
{
	Mat tmpFrame(frame);
	string result;
	imshow(picName, tmpFrame);
	setMouseCallback(picName, onMouse, (void*)&point);
	for (int i = 0; i < 9; i++)
	{
		while (1)
		{
			if (point.x!=-1) break;
		}
		circle(tmpFrame, point, 10, Scalar(255, 0, 0), -1);
		imshow(picName, tmpFrame);
		point = Point(-1, -1);
	}
	cout << point.x << " " << point.y << endl;
	waitKey();

	destroyWindow(picName);
	return result;
}


Dots::~Dots()
{
}
