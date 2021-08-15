#include <stdio.h> // greatest common divisor 
int main()
{
	int a,b;
	int temp;
	scanf("%d %d", &a, &b);

	while (a % b != 0) {
		temp=a%b;
		a =b;
		b =temp;
	}

	printf("%d", b);
			
	return 0;
}
