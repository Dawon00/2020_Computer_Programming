#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;

}

class Fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction */
	int denom; /* denominator of fraction */
public:
	friend istream& operator>>(istream& IN, Fraction& f);


	Fraction();
	Fraction(int a, int b); // 
	void readFrac();
	void reduce();
	void print();

	Fraction operator-(const Fraction& f);

	bool operator==(const Fraction& f);

};

Fraction::Fraction()
{
	numer = 0;
	denom = 1;
}
Fraction::Fraction(int a, int b)
{
	numer = a;
	denom = b;
	reduce();
}

void Fraction::readFrac()
{
	cin >> numer >> denom;
	reduce();
}

void Fraction::reduce()
{
	//abs 사용
	int g = gcd(abs(numer), abs(denom));
	numer /= g;
	denom /= g;
	if (denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

istream& operator >>(istream& IN, Fraction& f) {
	//IN이 cin을 받는다
	IN >> f.numer >> f.denom;
	f.reduce();

	return IN;
	//istream의 객체 IN
	//iostream의 객체 cin
}


Fraction Fraction::operator-(const Fraction& f) {
	Fraction result;
	result.denom = denom * f.denom;
	result.numer = numer * f.denom - denom * f.numer;
	result.reduce();

	return result;
}


bool Fraction::operator==(const Fraction& f) {
	Fraction result;
	result = *this - f;

	if (result.numer == 0)//분자가 0이라면
		return 1;
	else
		return 0;
}


int main()
{
	Fraction f1;
	Fraction f2;

	cin >> f1 >> f2;

	if (f1 == f2)
		cout << "same!!" << endl;
	else
		cout << "no" << endl;

	return 0;
}
