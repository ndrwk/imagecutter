#include "FolderReader.h"
#include "FileReader.h"
#include "PicLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


FolderReader::FolderReader(string path, string filemame)
{
	int recFileName = 70000;
	ifstream file(path + filemame);
	string textLine;
	while (!file.eof())
	{
		getline(file, textLine);
		if (textLine.length() == 0) break;
		PicLoader p_loader(path + textLine);
		getline(file, textLine);
		FileReader reader(path + textLine, path, recFileName);
		reader.cutFaces(p_loader.getMat());
		recFileName++;
	}
	file.close();


}


FolderReader::~FolderReader()
{
}
