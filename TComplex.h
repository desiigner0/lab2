#pragma once
#include <iostream>
class TComplex
{
public:
	TComplex();
	TComplex(double _im, double _re);
	TComplex(const TComplex& p);
	double GetIm();
	double GetRe();
	void SetIm(double _im);
	void SetRe(double _re);
	TComplex operator+(TComplex& p);
	TComplex operator-(TComplex& p);
	TComplex operator*(TComplex& p);
	TComplex operator/(TComplex& p);
	bool operator==(TComplex& p);
	TComplex operator=(const TComplex& p);
	friend std::ostream& operator<<(std::ostream& p, TComplex& f);
	friend std::istream& operator>>(std::istream& p, TComplex& f);
private:
	double im;
	double re;
};