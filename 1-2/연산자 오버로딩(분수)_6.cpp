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
	//외부 함수가 private 변수에 접근 가능하도록함(friend 이용)
	friend istream& operator>>(istream& IN, Fraction& f);

	Fraction();
	Fraction(int a, int b); // 
	void readFrac();
	void reduce();
	void print();

	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);

	Fraction& operator--();//1빼기
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
/*
Fraction Fraction::add(Fraction f)
{
	Fraction result;

	f1.numer = f1.numer * f2.denom;
	f2.numer = f2.numer * f1.denom;
	result.numer = f1.numer + f2.numer;
	result.denom = f2.denom * f1.denom;


	result.reduce();

	return result;

}
*/
void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

Fraction Fraction::operator+(const Fraction& f) {
	Fraction result;
	result.denom = denom * f.denom;
	result.numer = numer * f.denom + denom * f.numer;
	result.reduce();

	return result;
}

Fraction Fraction::operator-(const Fraction& f) {
	Fraction result;
	result.denom = denom * f.denom;
	result.numer = numer * f.denom - denom * f.numer;
	result.reduce();

	return result;
}

//&참조자를 썼음. 연속적으로 쓰여야 해서 완전한 자신
Fraction& Fraction::operator--() {
	numer = numer - denom;
	reduce();

	return *this;//객체 자체를 리턴해줍니다
}


istream& operator >>(istream& IN, Fraction& f) {
	//IN이 cin을 받는다
	IN >> f.numer >> f.denom;
	f.reduce();

	return IN;
	//istream의 객체 IN
	//iostream의 객체 cin
}



int main()
{
	Fraction f1;
	Fraction f2;

	Fraction f3; //add
	Fraction f4; //sub
	Fraction f5; //--

	cin >> f1 >> f2;

	f3 = f1 + f2;
	f4 = f1 - f2;

	f3.print();
	f4.print();
	----f2;
	f2.print();

	return 0;
}
