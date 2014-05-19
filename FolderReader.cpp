#include "FolderReader.h"
#include "FileReader.h"
#include "PicLoader.h"
#include "Dots.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


FolderReader::FolderReader(string path, string filesList, string descfilename, string destinationpath, int fileNumber)
{
	ifstream listFileName(path + filesList);
	ofstream descFile;
	descFile.open(descfilename, ios::app);
	string textLine;
	while (!listFileName.eof())
	{
		stringstream ss;
		ss << fileNumber;
		string recFileName = ss.str();
		getline(listFileName, textLine);
		if (textLine.length() == 0) break;
		PicLoader p_loader(path + textLine);
		getline(listFileName, textLine);
		FileReader reader(path + textLine, path, recFileName, destinationpath);
		string descLine = reader.cutFaces(p_loader.getMat());
		if (descLine != "wrong")
		{
			string desc = "Good\\" + recFileName + ".bmp " + descLine + "\n";
			descFile << desc;
			fileNumber++;
		}
	}
	listFileName.close();
	descFile.close();
}


FolderReader::FolderReader(string path, string filesList, string dest)
{
	ifstream listFileName(path + filesList);
	string textLine;
	while (!listFileName.eof())
	{
		getline(listFileName, textLine);
		if (textLine.length() == 0) break;
		PicLoader ploader(path + textLine);
		Dots pointer(ploader.getMat());
		string points = pointer.getPoints(dest + textLine);
		cout << path + textLine << endl;
		ofstream pointsFile;
		pointsFile.open(dest + textLine + ".cat", ios::app);
		pointsFile << points;
		pointsFile.close();
	}
	listFileName.close();
}

FolderReader::~FolderReader()
{
}
