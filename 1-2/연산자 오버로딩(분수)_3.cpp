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
	Fraction();
	Fraction(int a, int b); // 
	void readFrac();
	void reduce();
	void print();
	
	void operator++();   //operator++(int)   1 증가
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

void Fraction::operator++(){
	this->numer = this->numer + denom;
	//분모를 분자에 한번 더해줌
	reduce();
}

int main()
{
	int n,d;
	cin >> n >> d;
	
	Fraction f1(n,d);
	f1.print();
	++f1;
	f1.print();
	return 0;
	
}
