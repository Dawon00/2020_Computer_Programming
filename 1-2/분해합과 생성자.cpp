#include <stdio.h>
int main()
{
	int n,m,s;
  int gtr = -1; // 생성자 저장용 (만약 생성자가 없는 숫자면 -1이 디폴트)
	int result_sum;
	
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) 
	{
		result_sum = 0;
		result_sum += i;
		m=i;
		while((m%10) != 0)
		{
		s= m % 10;
		result_sum += s;
		m=m/10;
		}
		
		if (result_sum == n) 
		{
			gtr = i;
			break;
		}
	}

	printf("%d\n", gtr);
  return 0; 	
}
