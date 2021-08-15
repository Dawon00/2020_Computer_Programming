#include <stdio.h>

int main()
{
	int count;  //변수 count 선언
	int sum;  //변수 sum 선언
	char arr[10] = { }; //크기가 10인 배열 arr


	while (1) {
		count = 0; //변수 count를 0으로 초기화
		sum = 0;  //변수 sum을 0으로 초기화
		int j; //변수 j선언

		
		scanf_s("%s", &arr, sizeof(arr)+1);//arr값을 입력받는다
		for (j = 0; j < sizeof(arr)+1; j++)//for문을 이용해 j를 하나씩 증가시킨다
		{
			if (arr[j] == 'o') //arr요소의 값이 o이라면
			{
				count++;//1을 더한다
				sum += count;//총 점수계산
				
			}
			else
			 
				count = 0;//count을 0으로 초기화
			
			}
			printf("%d\n", sum);//총 점수를 출력한다.
	}
	return 0;
}
