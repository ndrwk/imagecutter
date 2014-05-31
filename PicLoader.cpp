#include "PicLoader.h"
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;


PicLoader::PicLoader(string filename)
{
	pic = imread(filename);
}


PicLoader::~PicLoader()
{
}

Mat PicLoader::getMat()
{
	return pic;
}

Mat PicLoader::getMat800600()
{
	Mat mat;
	if (mat.cols > 800)
	{
		resize(pic, mat, Size(800, 600));
		return mat;
	}
	else
		return pic;
}

Mat PicLoader::rotate(double angle)
{
	int len = max(pic.cols, pic.rows);
	Point2f pt(len / 2., len / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	Mat dst;
	warpAffine(pic, dst, r, Size(len, len));
	return dst;
}
