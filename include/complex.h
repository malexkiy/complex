#pragma once
#include <iostream>


class Complex
{
private:
	double _re;
	double _im;
public:
	Complex();
	Complex(const Complex&);
	Complex(double, double);
	~Complex();

	double real() const;
	double imaginary() const;

	Complex operator-() const;

	Complex operator*(int) const;
	Complex operator/(int) const;
	Complex& operator*=(int);
	Complex& operator/=(int);

	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;

	template<class CharT, class Traits = std::char_traits<CharT>>
	friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Complex& c)
	{
		os << "(" << c._re << ", " << c._im << ")";
		os.flush();

		return os;
	}

	template<class CharT, class Traits = std::char_traits<CharT>>
	friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Complex& c)
	{
		is >> c._re >> c._im;

		return is;
	}
};

