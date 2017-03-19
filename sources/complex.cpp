#include "complex.h"

Complex::Complex()
{
	_re = 0.0;
	_im = 0.0;
}


Complex::Complex(const Complex& c)
{
	_re = c._re;
	_im = c._im;
}


Complex::Complex(double re, double im)
{
	_re = re;
	_im = im;
}


Complex::~Complex()
{
}


double Complex::real() const
{
	return _re;
}


double Complex::imaginary() const
{
	return _im;
}


Complex Complex::operator-() const
{
	return Complex(-_re, -_im);
}


Complex Complex::operator*(int n) const
{
	Complex tmp(*this);
	tmp *= n;

	return tmp;
}


Complex Complex::operator/(int n) const
{
	Complex tmp(*this);
	tmp /= n;

	return tmp;
}


Complex& Complex::operator*=(int n)
{
	_re *= n;
	_im *= n;

	return *this;
}


Complex& Complex::operator/=(int n)
{
	if (n == 0)
		throw "Division by zero!\n";

	_re /= n;
	_im /= n;

	return *this;
}


Complex Complex::operator+(const Complex& c) const
{
	Complex tmp(*this);
	tmp += c;

	return tmp;
}


Complex Complex::operator-(const Complex& c) const
{
	Complex tmp(*this);
	tmp -= c;

	return tmp;
}


Complex Complex::operator*(const Complex& c) const
{
	Complex tmp(*this);
	tmp *= c;

	return tmp;
}


Complex Complex::operator/(const Complex& c) const
{
	Complex tmp(*this);
	tmp /= c;

	return tmp;
}


Complex& Complex::operator=(const Complex& c)
{
	if (this != &c)
	{
		_re = c._re;
		_im = c._im;
	}

	return *this;
}


Complex& Complex::operator+=(const Complex& c)
{
	_re += c._re;
	_im += c._im;

	return *this;
}


Complex& Complex::operator-=(const Complex& c)
{
	_re -= c._re;
	_im -= c._im;

	return *this;
}


Complex& Complex::operator*=(const Complex& c)
{
	double re, im;

	re = _re * c._re - _im * c._im;
	im = _re * c._im + _im * c._re;

	_re = re;
	_im = im;

	return *this;
}


Complex& Complex::operator/=(const Complex& c)
{
	if ((c._re == 0) && (c._im == 0))
		throw "Division by zero!\n";

	double re, im;

	re = (_re * c._re + _im * c._im) / (c._re * c._re + c._im * c._im);
	im = (_im * c._re - _re * c._im) / (c._re * c._re + c._im * c._im);

	_re = re;
	_im = im;

	return *this;
}


bool Complex::operator==(const Complex& c) const
{
	return (_re == c._re) && (_im == c._im);
}


bool Complex::operator!=(const Complex& c) const
{
	return (_re != c._re) || (_im != c._im);
}
