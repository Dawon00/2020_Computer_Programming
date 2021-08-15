#include <stdio.h>

int func(int n)
{
	int m,s;
	int result_sum;
	int gtr = -1; // 생성자 저장용 (만약 생성자가 없는 숫자면 -1이 디폴트)
	
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

}

int main()
{
	int n;
  
	
  scanf("%d", &n);
  func(n);
	
	return 0; 	
}
