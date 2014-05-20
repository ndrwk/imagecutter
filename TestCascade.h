#pragma once
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;


class TestCascade
{
	CascadeClassifier cascade;
	const string window_name = "pic";

	void detectAndDisplay(Mat);

public:
	TestCascade(string, string);
	~TestCascade();
};

