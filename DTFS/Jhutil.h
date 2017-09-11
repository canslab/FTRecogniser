#pragma once

#include <opencv2\opencv.hpp>
#include "Complex.h"
#include <vector>

using namespace JhMath;
using namespace std;
typedef unsigned char uchar;

class Jhutil
{
public:
	// it returns -1 if an error has occured.
	static int Jhutil::getDTFS_coeff(vector<uchar> &src, int K, int nPeriod, double &dstReal, double &dstImag);

	// n is row index, m is col index
	static int get2D_DTFS_coeff(vector<uchar> &src, int n, int m, int N, double &dstReal, double &dstImag);

	//static void get2D_DTFS_test(double)
	static JhMath::Complex myfunction(cv::Mat &src, int m, int n, int N);
};

