//분수를 기약분수로 만드는 reduce를 만드세요

//gcd 함수를 재귀로 만드세요

//두 분수를 더하는 add함수를 만드세요(기약분수를 반환)


#include <stdio.h>
#include <stdlib.h>

typedef struct fraction { /* a fraction, numer/denom */
   int numer; /* numerator of fraction */
   int denom; /* denominator of fraction */
} Fraction;//구조체의 별칭

int gcd(int a, int b);//최대 공약수 반환하는 함수

Fraction makeFraction(int a, int b);//분수로 만드는 함수

Fraction add(Fraction x, Fraction y);//두 분수를 더하는 함수

void printFraction(Fraction x);//분수 출력

Fraction readfrac();//분수를 입력받음

/*******************************************/

int main() {
	
	Fraction p1 = readfrac();                   //첫번째 분수 입력 , 출력
	
	Fraction p2 = readfrac();                   //두번째 분수 입력 , 출력
	
	Fraction p3 = add(p1,p2); // 두 함수를 더해서 p3에다가
	printFraction(p1); //첫번째 분수의 기약분수 출력
	printf("\n");
	printFraction(p2);//두번째 분수의 기약분수 출력
	printf("\n");
	printFraction(p3);              //두 분수를 더해서 출력
	
}

/***************************************/

/* greatest common divisor */
int gcd(int a, int b) {
	int temp;
	if(a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

/* reduce z to lowest terms */
Fraction reduce(Fraction x) {//약분해주는 함수
  Fraction z;
	int com;
	
	com=gcd(x.numer, x.denom);
	
	z.numer = x.numer / com;//약분해준다
	z.denom = x.denom / com;
	//printf("약분한것%d/%d\n",z.numer, z.denom);
	
  return z;
}

/* create fraction a/b, in lowest terms */
Fraction makeFraction(int a, int b) {
   Fraction z;
   if (b == 0) { //분모가 0이면 안돼
      printf("WARNING! Zero denom!\n");
      b = 1;
   }
   
   z.numer = a;
   z.denom = b;
	 
   z = reduce(z);//기약분수로 만들어줌
	//printf("a는 %d b는 %d\n",z.numer,z.denom);
   return z;
}


/* add fractions x and y, answer in l. terms */
Fraction add(Fraction x, Fraction y) {//분수를 더해주는 함수
	Fraction z;
	
	z.numer = y.denom * x.numer + x.denom * y.numer;
	
	z.denom = x.denom * y.denom;
	
	z = reduce(z);
	return z;
	
}


/* write the fraction, not necessarily in l.t. */
void printFraction(Fraction x) {
	 if (x.denom < 0)
	 {
		 x.numer *= -1;
		 x.denom *= -1;
	 }
	if(x.numer % x.denom == 0)//만약에 분자가 배수라면
	{
		x.numer = x.numer / x.denom;//한번더 약분해주기
		x.denom = 1;
	}
	if(x.denom==1)
		printf("%d", x.numer);
	else
   printf("%d/%d", x.numer, x.denom);
}

/* read two ints, create fraction, reduce */
Fraction readfrac() {
   int a, b;
   scanf("%i %i", &a, &b);
   return makeFraction(a, b);
}
