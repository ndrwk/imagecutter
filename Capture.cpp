#include "Capture.h"
#include <iostream>
#include <mutex>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


Capture::Capture(int cameraNumber)
{
	capture.open(cameraNumber);
}

Capture::Capture(string fileName)
{
	capture.open(fileName);
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

void Capture::grabVideo(int timeLimit, string filename)
{
	seconds firstTime = duration_cast<seconds>(high_resolution_clock::now().time_since_epoch());

	if (!isOpened())
	{
		cout << "Camera not found" << endl;
		return;
	}
	Size videoSize = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH),(int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	int ex = static_cast<int>(capture.get(CV_CAP_PROP_FOURCC));
	VideoWriter writer(filename, CV_FOURCC('D', 'I', 'V', 'X'), 20, videoSize, true);

	if (!writer.isOpened())
	{
		cout << "Could not open the output video for write: " << filename << endl;
		return;
	}
	while ((duration_cast<seconds>(high_resolution_clock::now().time_since_epoch())-firstTime).count()<timeLimit)
	{
		capture >> frame;
		writer << frame;
	}

}


