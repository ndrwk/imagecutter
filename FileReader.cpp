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
	if (coordinates.size() == 19)
	{
		vector<Point> labels;

		if ((coordinates[6] > coordinates[4])&(coordinates[6] > coordinates[2]))
		{

			labels.push_back(Point(coordinates[1], coordinates[2]));
			labels.push_back(Point(coordinates[3], coordinates[4]));
			labels.push_back(Point(coordinates[5], coordinates[6]));
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
			minY -= 20;
			maxX += 20;
			maxY += 10;
			if (minX < 0) minX = 0;
			if (minY < 0) minY = 0;
			if (maxX > pic.cols) maxX = pic.cols;
			if (maxY > pic.rows) maxY = pic.rows;
			Rect rect(Point(minX, minY), Point(maxX, maxY));
			recfile = pic(rect);
			if ((recfile.cols < 130)&(recfile.cols > 80)&(recfile.rows < 130)&(recfile.rows > 80))
			{
				cvtColor(recfile, recfile, CV_BGR2GRAY);
				imwrite(recName, recfile);
				cout << recName << endl;
			}
			else return "wrong";
		}
		else
		{
			cout << "wrong" << endl;
			return "wrong";
		}
		stringstream ss;
		ss << "1 " << "0 0 " << recfile.cols - 1 << " " << recfile.rows - 1;
		return ss.str();
	}
	else
	{
		return "wrong";
	}

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
/*
labels.push_back(Point(coordinates[7], coordinates[8]));
labels.push_back(Point(coordinates[9], coordinates[10]));
labels.push_back(Point(coordinates[11], coordinates[12]));
labels.push_back(Point(coordinates[13], coordinates[14]));
labels.push_back(Point(coordinates[15], coordinates[16]));
labels.push_back(Point(coordinates[17], coordinates[18]));
*/

