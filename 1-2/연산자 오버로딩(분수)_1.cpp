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
	
	
	Fraction operator+(const Fraction &f);
	Fraction operator+(int num);

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

Fraction Fraction::operator+(const Fraction &f){
	Fraction result;
	result.denom = denom * f.denom;
	result.numer = numer * f.denom + denom * f.numer;
	result.reduce();
		
	return result;
}

Fraction Fraction::operator+(int num){
	Fraction result;
	result.denom = denom;
	result.numer = numer + denom * num;
	result.reduce();
		
	return result;
}


int main()
{
	Fraction add_result;
	int n,d,k;
	cin >> n >> d;
	
	Fraction f1(n,d);
	Fraction f2;
	f2.readFrac();
	
	add_result = f1+f2;               // f1.operator+(f2)
	add_result.print();
	
	cin >> k;
	
	add_result = f1+k;
	add_result.print();
	return 0;
	
}
