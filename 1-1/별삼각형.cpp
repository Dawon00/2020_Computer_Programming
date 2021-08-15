#include <stdio.h>
int main() {

	int n;//줄의 개수
	scanf_s("%d", &n); //몇 줄인지 입력

	int i, j, k;     //필요한 변수 선언
	for (i = 1; i <= n; i++)    //n(입력받은 값)줄을 반복할 것임.
	{
		for (j = n ; j > i; j--)     //빈칸을 만드는 반복문(빈칸을 하나씩 줄여감)
		{
			printf(" ");     //빈칸 출력
		}
		for (k = 1; k <= i; k++)     //별을 찍는 반복문(별을 하나씩 늘림)
		{
				printf("*");     //별 출력
		}
			printf("\n");     //줄을 바꾼다	
	}
	return 0;
}
​
