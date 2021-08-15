#include <stdio.h>



int sum;
int main()
{
	int n;
	scanf("%d", &n);
	
	int digit(int n)
	{
		if (n==0)
			return 0;
		else if (n<0)
		{
			n = n*(-1);
			return digit(n);
		}
		else
			return n%10+digit(n/10);
	}
	
	printf("%d\n", digit(n));

	return 0;
}
