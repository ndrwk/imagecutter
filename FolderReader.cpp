#include "FolderReader.h"
#include "FileReader.h"
#include "PicLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


FolderReader::FolderReader(string path, string filemame, string descfilename, string destinationpath, int fileNumber)
{
	ifstream picFile(path + filemame);
	ofstream descFile;
	descFile.open(descfilename, ios::app);
	string textLine;
	while (!picFile.eof())
	{
		stringstream ss;
		ss << fileNumber;
		string recFileName = ss.str();
		getline(picFile, textLine);
		if (textLine.length() == 0) break;
		PicLoader p_loader(path + textLine);
		getline(picFile, textLine);
		FileReader reader(path + textLine, path, recFileName, destinationpath);
		string descLine = reader.cutFaces(p_loader.getMat());
		string desc = "Good\\"+recFileName+".bmp "+descLine+"\n";
		descFile << desc;
		fileNumber++;
	}
	picFile.close();
	descFile.close();


}


FolderReader::~FolderReader()
{
}
