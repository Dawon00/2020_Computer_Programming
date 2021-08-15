#include <stdio.h>
double power1(double x, int n)
{
	if(n==0)
		return 1;
	else
		return (x * power1(x, n-1));
}

double power2(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n > 0){
		if (n % 2 == 0){ // n is 짝수
			int temp = power2(x, n/2);
			return temp*temp;
		// return power2(x,n/2)*power2(x,n/2) : inefficent
		}
		else // n is 홀수
			return x*power2(x, n-1);
	}
}

int main()
{
	int n;

	double x;
	
	scanf("%lf %d", &x, &n);
	printf("%.2lf  %.2lf\n", power1(x,n), power2(x,n));		

	return 0;
}
