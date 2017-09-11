#pragma once

namespace JhMath 
{
	class Complex
	{
	public:
		double getMagnitude() const;
		// not implemented yet.
		double getPhase() const;


	public:
		// getter
		double getRealPart() const
		{
			return mRealPart;
		}
		double getImagPart() const
		{
			return mImagPart;
		}
	public:
		Complex divideBy(int N);

	public:
		// operator overloading
		Complex operator+(const Complex &otherComplex);
		Complex operator-(const Complex &otherComplex);
		Complex operator*(const Complex &otherComplex);
		Complex operator=(const Complex &otherComplex);

	public:
		Complex(double realPart, double imagPart);
		Complex(const Complex& srcComplex);
			~Complex();

	private:
			double mRealPart;
			double mImagPart;

	};
}
