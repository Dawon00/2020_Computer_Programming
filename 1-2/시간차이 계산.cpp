#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 100 

typedef struct _Time {
	char type[3]; // am or pm
	int hour;
	int minute;
	int second;
} Time;

int diff(Time t1, Time t2) // t2 - t1
{
	int diffBySeconds;
	int convToSeconds1, convToSeconds2;
	convToSeconds1 = 3600 * t1.hour + 60 * t1.minute + t1.second;
	//printf("1의 합은%d\n", convToSeconds1);
	convToSeconds2 = 3600 * t2.hour + 60 * t2.minute + t2.second;
	//printf("2의 합은%d\n", convToSeconds2);
	diffBySeconds = convToSeconds2 - convToSeconds1;
	//printf("차이는%d\n", diffBySeconds);

	if (diffBySeconds < 0)//차를 절댓값으로 변환
		diffBySeconds *= -1;

	//printf("절댓값한 차이는%d\n", diffBySeconds);
	//printf("타입은 %s %s\n", t1.type, t2.type);
	
	if (strcmp(t1.type, t2.type) != 0)//am pm이 다르면
	{
		diffBySeconds = 12 * 3600 - diffBySeconds;
	}
	
	int hour = diffBySeconds / 3600;
	//printf("%d\n", hour);
	diffBySeconds = diffBySeconds - (3600 * hour);
	//printf("%d\n", diffBySeconds);

	int minute = diffBySeconds / 60;
	diffBySeconds = diffBySeconds - 60 * minute;
	//printf("%d\n", diffBySeconds);

	int second = diffBySeconds;

	
	printf("%d %d %d", hour, minute, second);
	return 0;

}

int main()
{
	Time t1, t2;

	scanf("%s %d %d %d", &t1.type, &t1.hour, &t1.minute, &t1.second);

	scanf("%s %d %d %d", &t2.type, &t2.hour, &t2.minute, &t2.second);

	int workingTime = diff(t1, t2);


	//printf("%d %d %d\n", hour, minute, second);

	return 0;
}
