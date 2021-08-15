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
	
	Fraction& operator++();   //operator++(int)
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

Fraction& Fraction::operator++(){
	//참조자& 써주는 이유는 복사할게 아니라 자기 자신을 바꿔줘야해서
	numer = numer + denom;
	reduce();
	
	return *this;
}

int main()
{
	int n,d;
	cin >> n >> d;
	
	Fraction f1(n,d);
	f1.print();
	++++f1;//++f1의 리턴값이 있어야함.
	f1.print();
	return 0;
	
}
