#include <stdio.h>

int main()
{
  int yy;
	int isLeap = 1;
	
  scanf("%d", &yy);
// if , else if , else 구조 이용
  if (((yy%4==0)&&(yy%100!=0))||(yy%400==0))
		isLeap = 1;
	else
		isLeap = 0;
	
  if (isLeap)
		printf("yes");
  else
		printf("no");
	
  return 0; 	
}
