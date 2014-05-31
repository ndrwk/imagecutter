#include "FileReader.h"
#include "FolderReader.h"
#include "Capture.h"
#include "TestCascade.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;

const string sourcepath = R"(C:\Temp\cats\CAT_05\)";
//const string sourcepath = "C:\\Temp\\cats\\our\\";
const int fileNumber = 80000;
const string destinationpath = "C:\\Temp\\cats\\haartraining\\";
//const string destinationpath = "C:\\Temp\\cats\\our\\1\\";
const string filesList = "1.txt";
const string testFolder = R"(C:\Temp\cats\cat_04\)";
const string cascade = R"(C:\opencv\sources\data\haarcascades\catsheads.xml)";
const string videofile = R"(C:\Temp\cats\cats3.avi)";
const int limitBad = 100000;
const int cameraNumber = 1;
const int videoLenght = 120;



int main(int argc, char *argv[])
{
	string GoodPath = destinationpath + R"(Good\)";
	string BadPath = destinationpath + R"(Bad1\)";
	string Good_dat = destinationpath + "Good.dat";
	string Bad_dat = destinationpath + "Bad.dat";

//	FolderReader f_reader(sourcepath, filesList, Good_dat, GoodPath, fileNumber);

	Capture capture(videofile);
//	Capture capture(cameraNumber);
//	capture.grabVideo(videoLenght, videofile);
	capture.grabFrame(limitBad, BadPath);
//	
//	FolderReader freader(sourcepath, filesList, destinationpath);

//	TestCascade test(testFolder, cascade);


	return 0;
}

