#include <stdio.h>

int sum(int score[], int n)
{
	int s = 0;
	
	for (int i = 0; i < n; i++)
		s += score[i]; // s += *(score+i)
	
	return s;
}

void raiseScore(int score[], int n, int d)
{
	for (int i = 0; i < n; i++)
		score[i] += d;
	
}

int main()
{
	int score[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	
	printf("%d\n", sum(score,10) );
	raiseScore(score,10,10);
	printf("%d\n", sum(score,10) );
	
	printf("%p %p %p\n", score, score+1, score+2);
	printf("%x %x %x\n", score, score+1, score+2);
	
	printf("%d\n",sizeof(int *));
	
	return 0;
}
​
