#include <stdio.h>

int main()
{

	int a, b,temp,lcm;
	scanf("%d %d", &a, &b);

	int gcd, temp_a, temp_b;
	if(a>=b){
		temp_a = a;
		temp_b = b;
	}
	else{
		temp_a = b;
		temp_b = a;
	}
	//temp_a = a;
	//temp_b = b;
	
	while(temp_a % temp_b != 0) 
	{
		temp = temp_a % temp_b;
		temp_a = temp_b;
		temp_b = temp;
	}
	//temp_b가 최대공약수
	
	gcd = temp_b;
	lcm = (a*b) / gcd;
	printf("%d", lcm); //lcm변수는 최소공배수
	

	return 0;
}
