#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct point { // 점의 구조체 자료형 Point 정의
	int x; // x좌표
	int y; // y좌표
	int z; // ccw값을 저장하기 위한 변수
}Point;

//S부호를 구하는 함수
int ccw(Point p1, Point p2, Point p3) {
	int S = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	if (S > 0)//세개의 점이 반시계 방향일때
		return 1;
	else if (S == 0) // 세개의 점이 일직선 일때
		return 0;
	else // S < 0일때(세개의 점이 시계방향일때)
		return -1;
}
//메인함수
int main(void)
{
	//필요한 변수 선언
	int n, i;
	//n입력받기
	scanf("%d", &n); // 다각형의 꼭지점 개수를 입력받는다
	Point* list;
	//구조체 n개 만큼의 메모리 동적으로 할당받음
	list = (Point*)malloc(sizeof(Point) * n);

	for (i = 0; i < n; i++) {
		//n개의 배열에 각각 x와 y좌표 입력받기
		scanf("%d", &list[i].x);//x좌표 입력받기
		scanf("%d", &list[i].y);//y좌표 입력받기
	}


	int count = 0; // 오목점의 개수를 카운트 해줄 변수
	//result 메모리는 동적으로 할당 받는다
	Point* result;
	result = (Point*)malloc(sizeof(Point) * n);
	//각 점마다 ccw값을 result에 저장해 두기
	//첫번째 점(시작점) ccw 값 저장하기
	result[0].z = ccw(list[n - 1], list[0], list[1]);
	//마지막 점 ccw 값 저장하기
	result[n - 1].z = ccw(list[n - 2], list[n - 1], list[0]);
	//나머지 점 ccw 값 저장하기
	for (int i = 1; i < n - 1; i++) {
		result[i].z = ccw(list[i - 1], list[i], list[i + 1]);
	}

	//3개의 점씩 비교해서 1 >>-1>>1 이나 -1>>1>>-1로 변하면 오목점이므로 
	//count를 1 증가시켜준다.
	//일단 첫번째 점과 마지막 점을 제외한 점들을 오목점인지 검사한다.
	for (i = 0; i < n - 2; i++) {
		if (result[i].z == 1)
			if (result[i + 1].z == -1)
				if (result[i + 2].z == 1)
					count++;
				else if (result[i].z == -1)
					if (result[i + 1].z == 1)
						if (result[i + 2].z == -1)
							count++;
	}
	//마지막 점이 오목점인지 검사하기
	if (result[n - 2].z == 1)
		if (result[n - 1].z == -1)
			if (result[0].z == 1)
				count++;
			else if (result[n - 2].z == -1)
				if (result[n - 1].z == 1)
					if (result[0].z == -1)
						count++;
	//첫번째 점이 오목점인지 검사하기
	if (result[n - 1].z == 1)
		if (result[0].z == -1)
			if (result[1].z == 1)
				count++;
			else if (result[n - 1].z == -1)
				if (result[0].z == 1)
					if (result[1].z == -1)
						count++;
	// 최종 오목점의 개수를 출력해 준다.
	printf("%d", count);
	//동적으로 할당한 메모리를 해제한다.
		free(list);
		free(result);
	return 0;
}
