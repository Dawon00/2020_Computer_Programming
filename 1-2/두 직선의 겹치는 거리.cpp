#include <stdio.h>
struct Interval {    //입력받은 직선을 저장하는 구조체
	int start;
	int end;
};

struct Interval overlap(struct Interval intval1, struct Interval intval2) // 겹치는 구역 구하는 함수
{
	struct Interval result;    // 겹치는 구역을 저장할 구조체
	                           // 2 5 3 10 을 예로 들면
	if(intval1.start > intval2.start)//2가 3보다 먼저 오도록 바꿔주기
	{
		struct Interval temp;
		
		temp.end = intval1.start;
		intval1.start = intval2.start;
		intval2.start = temp.end;
		
		temp.end = intval1.end; //뒤따르는 또다른 점도 뒤바꿔주기
		intval1.end = intval2.end;
		intval2.end = temp.end;
	}
	if(intval1.start > intval1.end)//2가 5보다 먼저 오도록 바꿔주기
	{
		struct Interval temp;
		
		temp.end = intval1.start;
		//temp = intval1;
		intval1.start = intval1.end;
		intval1.end = temp.end;
	}
	if(intval2.start > intval2.end)//3이 10보다 먼저 오도록 바꿔주기
	{
		struct Interval temp;
		temp.end = intval2.start;
		intval2.start = intval2.end;
		intval2.end = temp.end;
	}
	if (intval1.start == intval2.start && intval2.end < intval1.end)//첫번째 케이스
	{
		result.start = intval2.end - intval2.start;
		printf("%d\n", result.start);
	}
	else if(intval1.start == intval2.start && intval1.end == intval2.end)//두번째 케이스
	{
		result.start = intval2.end - intval2.start;
		printf("%d\n", result.start);
	}
	else if(intval1.start == intval2.start && intval1.end < intval2.end)//세번째 케이스
	{
		result.start = intval1.end - intval1.start;
		printf("%d\n", result.start);
	}
	else if(intval1.start < intval2.start && intval2.end < intval1.end)//네번째 케이스
	{
		result.start = intval2.end - intval2.start;
		printf("%d\n", result.start);
	}
	else if(intval1.start < intval2.start && intval1.end == intval2.end)//다섯번째 케이스
	{
		result.start = intval2.end - intval2.start;
		printf("%d\n", result.start);
	}
	else if(intval1.start < intval2.start && intval2.start < intval1.end && intval1.end < intval2.end)
	{//여섯번째 케이스
		result.start = intval1.end - intval2.start;
		printf("%d\n", result.start);
	}
	else//위를 만족하지 않는다면 두 직선은 겹치지 않으므로 겹치는 길이는 0
	{
		result.start= 0;
		printf("0");
	}
}

int main()
{
	struct Interval intval1,intval2;
	
	scanf("%d%d", &intval1.start, &intval1.end); // 첫번째 직선의 시작점,끝점 입력받기
	scanf("%d%d", &intval2.start, &intval2.end); // 두번째 직선의 시작점,끝점 입력받기
	   
	struct Interval result = overlap(intval1, intval2);
	
	
	return 0;	
}
