#include <stdio.h>

int main() {

int n;//자연수의 개수

scanf("%d", &n);//자연수를 입력받는다

int numbers[10000];//숫자들을 저장할 배열

for (int i=0; i<n; i++)//for 문을 이용하여 배열에 숫자들을 입력받음

scanf("%d", &numbers[i]);


int count;//빈도수를 임시로 저장할 변수

int max =1;//최고 빈도수를 저장할 변수

int max_number;//최고 빈도수를 가지는 숫자를 저장할 변수


for(int i=0; i< n; i++)//배열의 요소들을 확인하기 위한 반복문

{

count =1;//count를 1로 초기화 해준다

for(int s=i+1;s<n;s++)//값을 두개씩 비교하기 위한 반복문

{

if(numbers[i]==numbers[s])//중복값을 찾으면

count ++;//빈도수를 1 증가시킨다

}

if(count > max)//만약 빈도수가 현재까지의 최고 빈도수보다 크다면

{

max_number = numbers[i];//최고빈도수를 가진 숫자를 갱신

max = count;//최고빈도수도 새로운 값으로 갱신

}

if(count == max && numbers[i]>max_number)//만약 최고빈도수가 같은데 더 큰 숫자라면

max_number = numbers[i];//최고 빈도수를 가진 숫자를 갱신

}


printf("%d %d", max_number, max);// 최고빈도수를 가진 숫자와 최고빈도수를 출력

return 0;

}
