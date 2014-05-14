#include "Capture.h"
#include <iostream>
#include <mutex>
#include <ctime>
using namespace std;


Capture::Capture(int cameraNumber)
{
	capture.open(cameraNumber);
}

Capture::~Capture()
{

}

bool Capture::isOpened()
{
	return capture.isOpened();
}


void Capture::grabFrame(int limit, string path)
{
	if (!isOpened())
	{
		cout << "Camera not found" << endl;
		return;
	}
	int frameCount = 0;
	while (frameCount < limit)
	{
		capture >> frame;
		cvtColor(frame, frame, CV_BGR2GRAY);
		stringstream ss;
		ss << path << "img" << frameCount << ".bmp";
		string filename = ss.str();
		imwrite(filename, frame);
		cout << filename << endl;
		frameCount++;
		waitKey(100);

	}

}


