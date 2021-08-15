#include <stdio.h>
int main() {
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	
	char week[7][4];  // string week[7]  week[0] = "Sun".....
	
	strcpy(week[0], "Sun");
	strcpy(week[1], "Mon");
	strcpy(week[2], "Tue");
	strcpy(week[3], "Wed");
	strcpy(week[4], "Thr");
	strcpy(week[5], "Fri");
	strcpy(week[6], "Sat");
	
	
	int yy, mm, dd;
	int count=0;
	
	scanf("%d", &yy);//년도 입력받기
	for(int x=1;x<yy;x++)//x는 임시변수, 작년까지 전체 며칠인지 카운트
	{
		if((x%4==0)&&(x%100!=0)||(x%400==0))
			count += 366;
		else
			count += 365;
	}
  if((yy%4==0)&&(yy%100!=0)||(yy%400==0))//올해는 윤년인가요?
	  month[2]=29;
	

	scanf("%d", &mm);//달 입력받기, 올해의 저번달까지 며칠인지 카운트
	for(int y=1;y<mm;y++)
		count += month[y];
	
	scanf("%d", &dd);//일 입력받기, 이번달에 며칠이나 있는지
	count += dd;
	
	int rest = count % 7;
	printf("%s", week[rest]);
	
	return 0;
}
