#include "TestCascade.h"
#include "PicLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



TestCascade::TestCascade(string path, string cascadeName)
{
	if (!cascade.load(cascadeName))
	{
		cout << "error loading" << endl;
		waitKey(3000);
	}
	ifstream listFileName(path + "1.txt");
	string textLine;
	while (!listFileName.eof())
	{
		getline(listFileName, textLine);
		if (textLine.length() == 0) break;
		PicLoader ploader(path + textLine);
		cout << path + textLine << endl;
		detectAndDisplay(ploader.getMat800600());
		waitKey(500);
	}
	listFileName.close();
}


TestCascade::~TestCascade()
{
}

void TestCascade::detectAndDisplay(Mat pic)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(pic, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0, Size(30, 30), Size(400,400));
	for (size_t i = 0; i < faces.size(); i++)
	{
		rectangle(pic, faces[i], Scalar(255, 0, 0));
	}
	imshow(window_name, pic);
}

