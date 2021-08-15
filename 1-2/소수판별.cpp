#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int isPrime = 1; // bool isPrime = true;
	
	for (int i=2;i<n;i++) 
	{
		if (n % i == 0)//나누어 떨어지면 소수아님
			isPrime = 0;
		
	}

			//isPrime == 1; //안나누어떨어지면 소수임
	
	if (isPrime) // 1(0이 아닌 수): 참 0: 거짓 
		printf("Prime Number"); //1이면 소수
	else
		printf("Not Prime Number"); //0이면 소수아님
	return 0;
}
