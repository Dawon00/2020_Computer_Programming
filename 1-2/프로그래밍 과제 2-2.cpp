/*특정 날짜와 n을 입력하면 

특정 날짜 이후 n일이 지나면 몇년 몇월 몇일 요일을 출력하는 코드를 짜시오.*/
#include <stdio.h>
#include <string.h>
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
	int n;//몇일이 지났는지 저장하는 변수
	scanf("%d", &yy);//년도 입력받기
	scanf("%d", &mm);//달 입력받기
	scanf("%d", &dd);//일 입력받기
	scanf("%d", &n);// n입력받기


	for(int x=1;x<yy;x++)//x는 임시변수, 작년까지 전체 며칠인지 카운트
	{
		if((x%4==0)&&(x%100!=0)||(x%400==0))
			count += 366;
		else
			count += 365;
	}
	
	int check(yy)
	{//yy가 윤년이면 2월달의 일수를 29일로 바꿔주는 함수
  if((yy%4==0)&&(yy%100!=0)||(yy%400==0))
	  month[2]=29;
	else
		month[2]=28;
	}
	check(yy);

	
	for(int y=1; y<mm; y++)//올해의 저번달까지 며칠인지 카운트
		count += month[y];
	
	count += dd;//이번달에 며칠이나 있는지 카운트
	int week_n = n;
	/****************************************************/
	while (n>365)//n이 365일을 넘어가지않을때까지 반복하는 반복문
	{
		check(yy);//윤년 체크
		if (month[2]==29)//윤년이라면 2월을 29일로 친다
		{
			n -= 366;//n에서 366일을 빼주기
			yy++;//다음 년도로 이동
		}
		else
		{
			n -= 365;
			yy++;
		}
	}
	//n이 365일보다 작거나 같아져서 while문을 빠져나왔을때 
		while( n > month[mm] )//n이 현재 월보다 일수가 더 많다면
		{
			n = n-month[mm];//n에서 현재 월의 일수를 빼주고
			mm++;//다음달로 넘어감
			if(mm==13)
			{
				mm=1;
				yy++;
				check(yy);
				if(month[2]==29 && mm>=3)
					dd--;
			}
		} 
		dd = dd+ n;//남은 n을 일수에 넣어줌
	
	while (dd>month[mm])
	{
		dd = dd-month[mm];
		mm++;
		if(mm==13)
		{
		mm=1;
		yy ++;
		}
	}
	
	if(mm==13)
	{
		mm=1;
		yy++;
	}
	
	printf("%d %d %d\n", yy, mm, dd);
	int rest = (count+week_n) % 7;
	printf("%s", week[rest]);
	
	return 0;
}
