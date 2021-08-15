#include <stdio.h>

int main() {

int answers[100]; // 정답 배열

int points[100]; // 점수 배열

int st_answers[100];// 학생 답 배열

int Q;//문제 수

int S;//학생 수

scanf("%d", &Q);//문제 수를 입력받음

for (int i=0; i<Q; i++)//for문을 이용해 정답을 입력받음

{

scanf("%d", &answers[i]);//정답 입력

}


for (int i=0; i<Q; i++)//for문을 이용해 배점을 입력받음

{

scanf("%d", &points[i]);//배점 입력

}


scanf("%d", &S);//학생 수를 입력받음

int max=0;//최고 점수 변수 선언

int count=0;// 점수 계산 변수 선언


for (int s=0; s<S; s++){//학생 수 만큼 for문 반복

for (int i=0; i<Q; i++){//한 학생의 답을 문제 개수 만큼 입력받음

scanf("%d", &st_answers[i]);//학생의 답 입력받기

}

for (int j=0; j<Q; j++)//문제 수만큼 한 학생의 답안 채점하기

{

if (answers[j]==st_answers[j])//정답과 학생의 답안이 같으면

count+=points[j]; //배점만큼 점수계산 변수에 더한다

}


if (count >= max)//만약 점수계산이 현재까지의 최고점수보다 크거나 같다면

max = count;//그 점수를 최고점수로 갱신

count = 0;//점수계산 변수는 0으로 초기화해줌

int st_answers[100]= {0,};//학생 답안 배열 요소들도 모두 초기화해줌


}


printf("%d", max);//채점을 모두 마치고 현재까지의 최고점수를 출력

return 0;

}

﻿
