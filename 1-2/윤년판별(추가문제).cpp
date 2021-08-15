#include <stdio.h>
int main()
{
  int y1 , y2;
  int count=0;
	int x;
	
	
  scanf("%d %d", &y1 , &y2);
	
	//코드를 추가하세요.
	for(x=y1 ; x <= y2 ; x++)
	{
		if (((x%4==0)&&(x%100!=0))||(x%400==0))
			count++;
	}
	printf("%d",count);
	
  return 0; 	
}
