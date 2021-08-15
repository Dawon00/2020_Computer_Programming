#include <stdio.h>
#include <string.h>
//문자열 s가 문자열 t의 subsequence인가?
 
int isSubsequence(char s[], char t[]) 
{//첫번째부터 하나씩 비교. 똑같으면 다음 인덱스로.
 //둘이 다르면 위에있는 것만 다음 인덱스로.
	//밑에있는 게 다 지워지면 subsequence
	int j=0;
	for(int i=0; i<strlen(s); i++)
	{
		if(s[i]==t[j])//비교했을때 같으면
			j++;
	}
	//printf("j는 %d", j);
	//printf("t의 길이는 %d", strlen(t));
	if( j == strlen(t) )
		return 1;
	else
		return 0;
}

int main(){
	char s[20];
	char t[20];
	
	scanf("%s %s",s,t);

	if (isSubsequence(s,t) == 1)
		printf("yes\n");
	else
		printf("no\n");
}
