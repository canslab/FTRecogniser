#include "Jhutil.h"
#include <math.h>
#define PI 3.141592



int Jhutil::getDTFS_coeff(vector<uchar> &src, int k, int nPeriod, double &dstReal, double &dstImag)
{
	double sumOfReal = 0.0;
	double sumOfImag = 0.0;

	// n is the index of sigma
	for (int n = 0; n < nPeriod; ++n)
	{
		double theta = -1 * (2 * PI / nPeriod * k * n);
		
		sumOfReal += (src[n] * cos(theta));
		sumOfImag += (src[n] * sin(theta));
	}

	dstReal = (sumOfReal) / nPeriod;
	dstImag = (sumOfImag) / nPeriod;
	
	return 0;
}

int Jhutil::get2D_DTFS_coeff(vector<uchar>& src, int n, int m, int N, double & dstReal, double & dstImag)
{
	double sumOfReal = 0.0;
	double sumOfImag = 0.0;

	for (int i = 0; i < N; ++i)	// i is row number
	{
		double theta = -1 * (2 * PI / N * i * n);
		double tempReal = 0;
		double tempImag = 0;

		vector<uchar> intensity;

		// 행에 있는 데이터들을 intensity라는 벡터 자료구조에 넣음.
		for (int index = 0; index < N; ++index)
		{
			intensity.push_back(src[N * i + index]);
		}

		Jhutil::getDTFS_coeff(intensity, m, N, tempReal, tempImag);

		sumOfReal += (tempReal * cos(theta) - tempImag * sin(theta));
		sumOfImag += (tempImag * cos(theta) + tempImag * sin(theta));
	}

	dstReal = sumOfReal / N;
	dstImag = sumOfImag / N;

	return 0;
}

JhMath::Complex Jhutil::myfunction(cv::Mat & src, int m, int n, int N)
{
	int subImageWidth = N;
	int subImageHeight = N;
	Complex result(0, 0);


	for (int y = 0; y < N; ++y)	// row direction
	{					
		double thetaY = (-2 * PI * n * y / N);
		Complex sinusoidY(cos(thetaY), sin(thetaY));

		for (int x = 0; x < N; ++x)	// column direction
		{
			double thetaX = (-2 * PI * m * x / N);
			Complex sinusoidX(cos(thetaX), sin(thetaX));
			Complex intensity(src.at<uchar>(y, x), 0);


			Complex temp = (intensity * sinusoidX);
			result = result + (temp * sinusoidY);
		}
	}
	result = result.divideBy(N * N);
	
	return result;
}