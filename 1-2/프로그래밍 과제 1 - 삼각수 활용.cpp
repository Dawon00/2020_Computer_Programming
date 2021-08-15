#include <stdio.h>

int main() 
{
	int Tri[1000];
	for(int j=1; j<=44; j++)//n=k*(k+1)/2 <=1000에서 k의 최대는 44
		Tri[j-1]=(j*(j+1))/2;//삼각수의 값들을 Tri리스트형에 모두 저장
	
	
	
	int n;
	scanf("%d", &n);//숫자입력
	
	
	
	for(int num1 = 0; num1<=43; num1++)//첫번째 수 반복문
		for(int num2 = 0; num2<=43; num2++)//두번째 수 반복문
			for(int num3 = 0; num3<=43; num3++)//세번째 수 반복문
			{
				if (Tri[num1]+Tri[num2]+Tri[num3]==n)//만약 세 수를 모두 더했을 때 n이라면
				{
					printf("%d %d %d\n", Tri[num1], Tri[num2], Tri[num3]);//삼각수 3개를 모두 출력한다
					goto END;//END로 가기
				}
			}
printf("-1");//위의 if문을 만족하지 못했다면 -1을 출력
	END://프로그램 종료
	
	return 0;
}
