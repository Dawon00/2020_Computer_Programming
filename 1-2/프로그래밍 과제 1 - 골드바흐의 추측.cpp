#include <stdio.h>
int check(int n)
	{
		for (int i=2; i<n; i++)//2부터 n-1까지 i를 1씩 증가시키는 for 문
		{
			if(n%i==0)//만약 n이 i로 나누어 떨어진다면
			{
				return 0;//소수가 아니므로 0을 반환하고
				break;//break문으로 빠져나온다
			}
		}
		return 1;//나누어 떨어지는 게 없다면 소수이므로 1을 반환한다
	}


int main()
{
    int n;//입력받을 짝수 n
	  int a;//첫번째 소수
	  int b;//두번째 소수

   
    scanf("%d", &n);//n을 입력받는다
    int i=n/2;//i를 n/2라고 지정한다
	while(1)
	{
    if(check(i)==1&&check(n-i)==1)//i와 n-i가 둘다 소수라면
		{
			a=i;//i의 값을 a에 대입한다
			b=n-i;//n-i의 값을 b에 대입한다
			break;//break로 빠져나온다
		}
		else
			i--;//i의 값을 1 감소시킨다. 그리고 반목문의 처음으로 돌아간다.
	}
	printf("%d %d", a,b);//a와 b의 값을 출력한다
    return 0;//프로그램 종료
}
