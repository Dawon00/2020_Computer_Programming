#include <stdio.h>

int main()
{
	int i,j,n;
	int count=0;
	
	scanf("%d", &n);//n이 5라고 한다면
	
	for(j=1;j<=n;j++)//j는 1부터 5까지 증가
	{
		for (i=2;i<j;i++) 
	  {
			if (j % i == 0)//나누어 떨어지면 소수아님
			  break;
	  }
	  if(j==i)
			count+=1;
		  
	}
	// !
	
	printf("%d",count);

	return 0;
}
