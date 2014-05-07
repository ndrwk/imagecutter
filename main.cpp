#include "FileReader.h"
#include "FolderReader.h"
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
const string destinationpath = "C:\\Temp\\cats\\haartraining\\Good\\";
const string descfilename = "C:\\Temp\\cats\\haartraining\\Good.dat";
const string filesList = "1.txt";



int main(int argc, char *argv[])
{
	FolderReader f_reader(sourcepath, filesList, descfilename, destinationpath, fileNumber);



	return 0;
}

