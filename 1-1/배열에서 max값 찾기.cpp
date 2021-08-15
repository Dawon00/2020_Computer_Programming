#include <iostream>
using namespace std;
int main()
{
	int list[10];//크기가 10인 리스트
	int max;//max변수 선언
	
	int i;// i변수선언
	for (i = 0; i < 10; i++) // 난수 10개 생성
	{
		list[i] = (rand() % 100) + 1; // 1~100사이의 난수를 list의 데이터로 지정
		printf("%d ", list[i]); // 난수출력
	}


	cout << endl;
	max = list[0];//max에 list[0]을 대입

	for (i = 0; i < 10; i++)//리스트에서 1번째~10번째 데이터까지
	{
		if (list[i] > max)//max에 저장된 값보다 i번째 값이 더 큰지 확인
			max = list[i];//더 크다면 그 값을 max라고 지정
	}


	cout << "최대값=" << max << endl;//최대값출력
	return 0;
}
