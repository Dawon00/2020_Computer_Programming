#include <stdio.h>

int gcd(int a, int b)
{
	int temp;
  if (a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

int main()
{
	int a , b;

	scanf("%d %d", &a , &b);
	
	
	
	printf("%d\n", gcd(a,b));
	return 0;
}
