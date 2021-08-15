#include <stdio.h>
int gcm(int x, int y)
{
	int result = 1;//결과값 변수 1로 초기화
	for (int i = 1; i <= x; i++) //i가 1부터 첫번째 수까지 1씩 증가 
	{                            //ㅌ
		if (!(x % i) && !(y % i)) // x와 y가 i로 나누어 떨어질 때
			result = i; //i값을 반환함
	}
	return result; //결과값을 반환함
}

unsigned long long lcm(long x, long y) // 두 수의 최소공배수 구하는 함수
{
	return x * y / gcm(x, y); // 두수를 곱하고 최대공약수로 나눈값을 반환
}


int main()
{

	long num1;
	long num2;
	long num;

	scanf("%ld", &num1);
	scanf("%ld", &num2);
	unsigned long long lcm_save;
	lcm_save = lcm(num1, num2);

	while (1)
	{
		scanf("%ld", &num);
		if (num > 0)
		{
			lcm_save = lcm(lcm_save, num);

		}
		else if (num = -1)
		{
			printf("%lld\n", lcm_save);
			break;
		}

	}


	return 0;
}
