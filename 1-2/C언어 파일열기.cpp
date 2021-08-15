#include <stdio.h>
int main() {
	FILE *fp;
	FILE *fp2;
	
	char result[10];
	char result2[10];
	
	if((fp = fopen("data/out.txt", "w")) == NULL) {//out.txt라는걸 만들어서 w모드로 열기
		printf("error \n");
		return 0;
	}
	fputs("hi pikachu\n", fp);
	fclose(fp);
	
	if((fp2 = fopen("data/out.txt", "r")) == NULL) {//읽기모드로 열어서
		printf("error \n");
		return 0;
	}
	fscanf(fp2, "%s %s", &result, &result2);
	
	printf("%s %s", result,result2);
	fclose(fp2);
	
	return 0;
}
