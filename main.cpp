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

const string path = "C:\\Temp\\cats\\CAT_05\\";
const string filename = "1.txt";



int main(int argc, char *argv[])
{
	FolderReader f_reader(path, filename);



	return 0;
}

