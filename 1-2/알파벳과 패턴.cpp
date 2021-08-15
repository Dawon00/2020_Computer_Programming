#include <stdio.h>
#include <ctype.h>
#include <string.h>
int countAlphabet(char str1[]){//알파벳개수세기
	int cnt = 0;
	for (int i = 0; i < strlen(str1); i++){
		//if ((str1[i]>='a'&& str1[i]<='z')||(str1[i] >='A'&& str1[i]<='Z')) // 한줄만 쓰면됨.
		if(isalpha(str1[i]))
			cnt++;
	}
	return cnt;
}
// 텍스트 문자열에서 패턴 문자열(substring)이 나오는 횟수 구하기 
// strlen 함수 사용 
int findPattern(char text[], char pattern[]){
	// 
	int cnt = 0;
	int j;
	for (int i = 0; i < strlen(text); i++){
		// text[i]에서 시작하는 pattern이 있는지 check
		if (text[i]==pattern[0])//만약에 첫글자가 같은 상황이면
		{
			int s=i+1; // 위치 고친 것
			for(j=1; j< strlen(pattern); j++)//두번째 부터 검사시작
			{
				//int s= i+1;//s에 i값 복사해놓고(3) << 여기가 문제였었음!
				if(pattern[j]==text[s])//만약에 글자가 같으면
					s++;
				else
					break;
			}
			
			if(j == strlen(pattern))//pattern 끝까지 같아지는 상황이오면
				cnt++;
		}
		//printf("j는 %d\n", j);
		//printf("pattern길이는 %d\n", strlen(pattern));
			
	} 	
	return cnt;
}

int main(){
	
	char text[50];
	char pattern[10];
	
	scanf("%s %s", text, pattern);
	
	printf("%d\n", countAlphabet(text));
	printf("%d\n", findPattern(text,pattern));
	
}
