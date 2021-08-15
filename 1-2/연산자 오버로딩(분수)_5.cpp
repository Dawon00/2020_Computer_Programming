#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b) {
   while (b != 0) {
      int temp = b;
      b = a%b;
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
	int g = gcd(abs(numer),abs(denom));
	numer /= g;
	denom /= g;
	if(denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}


void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

istream& operator >>(istream& IN, Fraction& f){
	//IN이 cin을 받는다
	IN >> f.numer >> f.denom;
	f.reduce();
	
	return IN;
	//istream의 객체 IN
	//iostream의 객체 cin
}

int main()
{
	//원래는 분수만들때 분자분모 따로 받았는데 이젠
	Fraction f1;
	cin >> f1; // 분수 자체를 받는다.
	
	f1.print();

	
	return 0;
	
}
