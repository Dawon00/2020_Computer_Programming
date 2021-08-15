#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char name[200][9];      //최대 8글자이하의 알파벳
	int score[200] = {0};   //일단 전부 0으로 초기화
	int n;
	float sum=0;
	float average =0;
	float x=0;//분산
	
	scanf("%d",&n);
	
	for (int i=0;i<n;i++){
		scanf("%s %d", &name[i] , &score[i]);
	}
	
	for (int j=0;j<n;j++){
		sum += score[j];
	}

	average = (float)sum/n;
	
	for (int s=0;s<n;s++){
		x += (score[s] - average)*(score[s] - average);
	}
	x = x/n;
	
	float standard_deviation = sqrt(x);
	
	printf("표준편차 = %.2f\n", standard_deviation);
	/********************************************여기까지 표준편차 구하기*/
	int max=score[0],a;
	for(int i=1;i<n;i++){
		if (max < score[i])
		{
			max = score[i];
			a=i;//임시저장할 변수
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		if (score[i]==max)
			printf("%s %d\n",name[i],max);
	}
	
	return 0;
}
