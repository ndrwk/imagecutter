#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
using namespace std;
using namespace cv;

class FileReader
{
	vector <int> coordinates;
	Mat recfile;
	int points;
	int LeftEye = 0;
	int RightEye = 1;
	int Mouth = 2;
	int LeftEar1 = 3;
	int LeftEar2 = 4;
	int LeftEar3 = 5;
	int RightEar1 = 6;
	int RightEar2 = 7;
	int RightEar3 = 8;
	string recName;
	Mat rotate(Mat, double, Point2f);


public:
	FileReader(string,string,string, string);
	~FileReader();
	vector<int> getCoordinates();
	string cutFaces(Mat);
};

