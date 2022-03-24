#include "TComplex.h"

TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double _im, double _re)
{
	this->re = _re;
	this->im = _im;
}

TComplex::TComplex(const TComplex& p)
{
	re = p.re;
	im = p.im;
}

double TComplex::GetIm()
{
	return im;
}

double TComplex::GetRe()
{
	return re;
}

void TComplex::SetIm(double _im)
{
	_im = im;
}

void TComplex::SetRe(double _re)
{
	_re = re;
}
TComplex TComplex::operator+(TComplex& p)
{
	TComplex res;
	res.re = re + p.re;
	res.im = im + p.im;
	return res;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex res;
	res.re = re - p.re;
	res.im = im - p.im;
	return res;
}

TComplex TComplex::operator*(TComplex& p)
{
	TComplex res;
	res.re = re * p.re - re * p.im;
	res.im = im * p.re + im * p.re;
	return res;
}

TComplex TComplex::operator/(TComplex& p)
{
	TComplex res;
	res.re = (re * p.re + im * p.im) / ((p.re * p.re) + (p.im * p.im));
	res.im = (p.re * im - re * p.im) / ((p.re * p.re) + (p.im * p.im));
	return res;
}

bool TComplex::operator==(TComplex& p)
{
	if (p.re == re && p.im == im)
		return true;
	else
		return false;
}

TComplex TComplex::operator=(const TComplex& p)
{
	this->re = p.re;
	this->im = p.im;
	return *this;
}

std::ostream& operator<<(std::ostream& p, TComplex& f)
{
	p << f.re << "+, *" << f.im;
	return p;
}

std::istream& operator>>(std::istream& p, TComplex& f)
{
	p >> f.re;
	p >> f.im;
	return p;
}
double TComplex::Module(double _im, double _re)
{
	return sqrt(pow(_re, 2) + pow(_im, 2));
}
