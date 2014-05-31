#include "FileReader.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
using namespace cv;


FileReader::FileReader(string filename, string path, string fileNumber, string destinationpath)
{
	recName = destinationpath + fileNumber + ".bmp";

	string delimiter = " ";
	ifstream file(filename);
	string textLine;
	getline(file, textLine);
	int pos = 0;
	string token;
	while ((pos = textLine.find(delimiter)) != string::npos)
	{
		token = textLine.substr(0, pos);
		int tmpInt;
		istringstream istr(token);
		istr >> tmpInt;
		coordinates.push_back(tmpInt);
		textLine.erase(0, pos + delimiter.length());
	}
	file.close();
}

FileReader::~FileReader()
{
}

vector<int> FileReader::getCoordinates()
{
	return coordinates;
}

string FileReader::cutFaces(Mat pic)
{
	if ((coordinates[6] < coordinates[10]) | (coordinates[6] < coordinates[16]))
		return "wrong";
	if (coordinates.size() == 19)
	{
		vector<Point> labels;

		labels.push_back(Point(coordinates[1], coordinates[2]));
		labels.push_back(Point(coordinates[3], coordinates[4]));
		labels.push_back(Point(coordinates[5], coordinates[6]));
		labels.push_back(Point(coordinates[7], coordinates[8]));
		labels.push_back(Point(coordinates[9], coordinates[10]));
		labels.push_back(Point(coordinates[11], coordinates[12]));
		labels.push_back(Point(coordinates[13], coordinates[14]));
		labels.push_back(Point(coordinates[15], coordinates[16]));
		labels.push_back(Point(coordinates[17], coordinates[18]));

		int minX = pic.cols;
		int maxX = 0;
		int minY = pic.rows;
		int maxY = 0;

		for (auto iter = labels.begin(); iter != labels.end(); iter++)
		{
			int x = (*iter).x;
			int y = (*iter).y;
			if (minX > x) minX = x;
			if (minY > y) minY = y;
			if (maxX < x) maxX = x;
			if (maxY < y) maxY = y;
		}
		int side = max(maxX - minX, maxY - minY);
		Point2f centerPoint(minX + (maxX - minX) / 2, minY + (maxY - minY) / 2);
		double angle = atan((coordinates[4] - coordinates[2]) / (coordinates[3] - coordinates[1])) * 180 / 3.14159265;
		int X = (int) minX - side / 2 + (maxX - minX) / 2;
		int Y = (int) minY - side / 2 + (maxY - minY) / 2;
		if (X < 0) X = 0;
		if (Y < 0) Y = 0;
		if ((X + side) > pic.cols) X = pic.cols - side;
		if ((Y + side) > pic.rows) Y = pic.rows - side;
//		cout << angle << " " << X << " " << Y << " " << side << endl;
		if ((X < 0) | (Y < 0))
			return "wrong";
		Mat rotatedPic = rotate(pic, angle, centerPoint);
		Rect rect(Point(X, Y), Point(X + side, Y + side));
		recfile = rotatedPic(rect);
		if ((recfile.cols < 400)&(recfile.cols > 100)&(recfile.rows < 400)&(recfile.rows > 100))
		{
			cvtColor(recfile, recfile, CV_BGR2GRAY);
			equalizeHist(recfile, recfile);
			imwrite(recName, recfile);
			cout << recName << endl;
		} else
			return "wrong";
		stringstream ss;
		ss << "1 " << "0 0 " << recfile.cols - 1 << " " << recfile.rows - 1;
		return ss.str();
	} else
	{
		return "wrong";
	}

}

Mat FileReader::rotate(Mat src, double angle, Point2f pt)
{
	int len = max(src.cols, src.rows);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	Mat dst;
	warpAffine(src, dst, r, Size(len, len));
	return dst;
}






/*
circle(pic, LeftEye, 10, Scalar(255,0,0), 3);
circle(pic, RightEye, 10, Scalar(255, 0, 0), 3);
circle(pic, Mouth, 10, Scalar(255, 0, 0), 3);
circle(pic, LeftEar1, 10, Scalar(255, 0, 0), 3);
circle(pic, LeftEar2, 10, Scalar(255, 0, 0), 3);
circle(pic, LeftEar3, 10, Scalar(255, 0, 0), 3);
circle(pic, RightEar1, 10, Scalar(255, 0, 0), 3);
circle(pic, RightEar2, 10, Scalar(255, 0, 0), 3);
circle(pic, RightEar3, 10, Scalar(255, 0, 0), 3);
*/

