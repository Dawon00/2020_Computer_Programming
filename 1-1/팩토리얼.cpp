#include <iostream>
using namespace std;
int main(void) {
	long fact = 1;//변수fact의 초기값을 1로 선언
	int n;//변수 n을 선언

	cout << "정수를 입력하세요:";//정수를 입력받기위한 메세지
	cin >> n;//정수를 입력받아 n에 저장한다.

	for (int i = 1; i <= n; i++) //i를 1부터 n까지 하나씩 증가시킨다.
		fact = fact * i; // fact와 i의 곱을 fact라고 지정한다
	
	cout << n << "!은" << fact << "입니다.\n";//결과를 출력한다.
	return 0;

}
