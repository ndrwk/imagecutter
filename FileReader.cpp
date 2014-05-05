#include "FileReader.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
using namespace cv;


FileReader::FileReader(string filename, string path, int fileNumber)
{
	stringstream ss;
	ss << fileNumber;
	recFileName = path+"cut\\"+ss.str()+".jpg";
	name = filename;
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

void FileReader::cutFaces(Mat pic)
{
	vector<Point> labels;
	if (coordinates.size() == 19)
	{
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

		for (vector<Point>::iterator iter = labels.begin(); iter != labels.end(); iter++)
		{
			int x = (*iter).x;
			int y = (*iter).y;
			if (minX > x) minX = x;
			if (minY > y) minY = y;
			if (maxX < x) maxX = x;
			if (maxY < y) maxY = y;
		}
		minX -= 20;
		minY -= 10;
		maxX += 20;
		maxY += 30;
		if (minX < 0) minX = 0;
		if (minY < 0) minY = 0;
		if (maxX > pic.cols) maxX = pic.cols;
		if (maxY > pic.rows) maxY = pic.rows;
		Rect rect(Point(minX, minY), Point(maxX, maxY));
		Mat recfile = pic(rect);
		imwrite(recFileName, recfile);


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
	}
	else
	{
		cout << "wrong" << endl;
	}
}
