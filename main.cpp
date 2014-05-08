#include "FileReader.h"
#include "FolderReader.h"
#include "Capture.h"
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

const string sourcepath = "C:\\Temp\\cats\\CAT_06\\";
const int fileNumber = 70000;
const string destinationpath = "C:\\Temp\\cats\\haartraining\\";
const string filesList = "1.txt";
const int limitBad = 200;



int main(int argc, char *argv[])
{
	string GoodPath = destinationpath + "Good\\";
	string BadPath = destinationpath + "Bad\\";
	string Good_dat = destinationpath + "Good.dat";
	string Bad_dat = destinationpath + "Bad.dat";

//	FolderReader f_reader(sourcepath, filesList, Good_dat, GoodPath, fileNumber);

	Capture capture(0);
	capture.grabFrame(limitBad, BadPath);




	return 0;
}

