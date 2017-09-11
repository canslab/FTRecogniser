#include <iostream>
#include <opencv2\opencv.hpp>
#include "Jhutil.h"
#include <cstdlib>
#include <vector>
#include <fstream>
#include "source.h"
#include "Complex.h"
using namespace cv;
using namespace std;


int main(void)
{
	double real;
	double imag;

	Mat images = imread("brown2.png", 0);
	vector<uchar> vec;
	vector<double> magnitude;

	Mat test = cv::Mat(10, 10, CV_8UC1,Scalar(10));

	/*vec.assign(images.datastart, images.dataend);
	std::ofstream file("b2.txt");

	JhMath::Complex tt = Jhutil::myfunction(images, 0, 0, 32);*/
	//cout << tt.getRealPart();

	/*
	for (int n = 0; n < 32; ++n)
	{
		for (int m = 0; m < 32; ++m)
		{
			auto result = Jhutil::myfunction(images, m, n, 32);
			printf_s("%-3lf ", result.getMagnitude());

		}
		cout << endl;
	}
*/
	auto result = Jhutil::myfunction(images, 31, 31, 32);
	cout << result.getMagnitude();

	/*for (int n = 0; n < 32; ++n)
	{
		for (int m = 0; m < 32; ++m)
		{
			double real;
			double imag;
			double mag;

			Jhutil::get2D_DTFS_coeff(vec, n, m, 32, real, imag);
			
			mag = sqrt(real*real + imag*imag);

			file << "[" << (int)n << ", " << (int)m << "] = " << mag << endl;

			magnitude.push_back(mag);
		}
	}*/

	//imshow("result", images);	

	waitKey(0);
	return 0;
}