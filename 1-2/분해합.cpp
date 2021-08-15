#include <stdio.h>
int main() {
	int n;
	int result_sum = 0;
	scanf("%d",&n);
	int m;
	int s;
	
	result_sum += n;
	m=n;
	while((m%10) != 0)
	{
		
		s= m % 10;
		result_sum += s;
		m=m/10;
	}

	
	
	// while이나 for문으로 작성

	printf("%d",result_sum);
	
	return 0;
}
