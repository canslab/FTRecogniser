#include "Complex.h"
#include <math.h>

using namespace JhMath;

double JhMath::Complex::getMagnitude() const
{
	return sqrt(mRealPart * mRealPart + mImagPart * mImagPart);
}

double JhMath::Complex::getPhase() const
{

	return 0.0;
}

Complex JhMath::Complex::divideBy(int N)
{
	return Complex((this->mRealPart / N), (this->mImagPart / N));
}

Complex JhMath::Complex::operator+(const Complex & otherComplex)
{
	return Complex(this->mRealPart + otherComplex.mRealPart, this->mImagPart + otherComplex.mImagPart);
}

Complex JhMath::Complex::operator-(const Complex & otherComplex)
{
	return Complex(this->mRealPart - otherComplex.mRealPart, this->mImagPart - otherComplex.mImagPart);
}

Complex JhMath::Complex::operator*(const Complex & otherComplex)
{
	// (a + bi) * (c + di)
	// => ac + adi + bci - bd
	// => (ac - bd) + (ad+bc)i
	double a = this->mRealPart;
	double b = this->mImagPart;
	double c = otherComplex.getRealPart();
	double d = otherComplex.getImagPart();

	return Complex(a * c - b * d, a * d + b * c);
}

Complex Complex::operator=(const Complex &otherComplex)
{
	this->mRealPart = otherComplex.mRealPart;
	this->mImagPart = otherComplex.mImagPart;
	return *this;
}


JhMath::Complex::Complex(double realPart, double imagPart)
{
	this->mRealPart = realPart;
	this->mImagPart = imagPart;
}

JhMath::Complex::Complex(const Complex & srcComplex)
{
	this->mRealPart = srcComplex.getRealPart();
	this->mImagPart = srcComplex.getImagPart();
}

JhMath::Complex::~Complex()
{
}
