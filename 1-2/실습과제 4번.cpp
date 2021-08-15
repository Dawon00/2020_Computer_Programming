//날짜 입력하면 요일 출력하기

//구조체 이용할 것

#include <stdio.h>

typedef struct Date{
	int yy;
	int mm;
	int dd;
} DateType;

int main() {
	int count = 0;
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	
	char week[7][4];  // string week[7]  week[0] = "Sun".....
	
	strcpy(week[0], "Sun");
	strcpy(week[1], "Mon");
	strcpy(week[2], "Tue");
	strcpy(week[3], "Wed");
	strcpy(week[4], "Thr");
	strcpy(week[5], "Fri");
	strcpy(week[6], "Sat");
	
	//DateType base = {2019,1,1}; // baseweek : 화요일
	
	DateType input_Date;
	scanf("%d %d %d", &input_Date.yy, &input_Date.mm, &input_Date.dd);

	for(int x=1;x<input_Date.yy;x++)//x는 임시변수, 작년까지 전체 며칠인지 카운트
	{
		if((x%4==0)&&(x%100!=0)||(x%400==0))
			count += 366;
		else
			count += 365;
	}
  if((input_Date.yy%4==0)&&(input_Date.yy%100!=0)||(input_Date.yy%400==0))//올해는 윤년인가요?
	  month[2]=29;
	
	for(int y=1;y<input_Date.mm;y++)
		count += month[y];
	
	count += input_Date.dd;
	
	int rest = count % 7;
	printf("%s", week[rest]);
	
	return 0;



}
