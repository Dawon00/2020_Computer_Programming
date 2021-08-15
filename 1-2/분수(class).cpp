#include <cstring>
#include <cstdlib>//abs 사용
#include <iostream>
using namespace std;

/* greatest common divisor */
int gcd(int a, int b) { //최대공약수 구하는 함수
	
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);

}

class Fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction 분자*/
	int denom; /* denominator of fraction 분모*/
public:
	Fraction(); // 매개변수 없는 생성자(분자는 0 분모는 1로 초기화)
	Fraction(int a, int b); // 생성자(매개변수로 분자 분모 초기화)
	void readFrac();	//cin으로 읽어서 분자, 분모로 저장
	void reduce(); //기약분수로 만들기
	void print();

	Fraction add(Fraction f1, Fraction f2);
};

Fraction::Fraction()//생성자
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
	//분모가 -면 분자 -로 바꿔주고 
	//분자 분모가 둘다 -면 둘다 +로 바꿔줌
	if (denom < 0 && numer > 0) {
		denom *= -1;
		numer *= -1;
	}
	else if (denom < 0 && numer < 0) {
		denom *= -1;
		numer *= -1;
	}
	//abs 사용
	int com;
	com = gcd(abs(numer), abs(denom));
	numer = numer / com;
	denom = denom / com;
}

Fraction Fraction::add(Fraction f1, Fraction f2)
{
	Fraction f3;
	
	f1.numer = f1.numer * f2.denom;
	f2.numer = f2.numer * f1.denom;
	f3.numer = f1.numer + f2.numer;
	f3.denom = f2.denom * f1.denom;


	f3.reduce();
	
	return f3;
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

int main()
{
	int n, d;
	cin >> n >> d;

	Fraction f1(n, d);
	Fraction f2;
	Fraction f3;

	f2.readFrac();

	f1.print();
	f2.print();
	f3.print();

	f3 = f2.add(f1, f2);
	f3.print();

	return 0;
}
​
