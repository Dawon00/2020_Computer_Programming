#include <iostream>
#include <string>
using namespace std;

class Car {	
public:
	int getHP()	
	{		
		return 100;	// 100마력반환
	}
};

class SportsCar : public Car {	
public:
	int getHP()	    //멤버 함수의 이름, 반환형, 매개 변수의 개수와 데이터 타입이 일치
	{
		return 300;	// 300마력반환
	}
};

int main()
{
	SportsCar sc;
	cout << "마력: " << sc.getHP() << endl;//재정의(오버라이딩)된게 나온다
	cout << "마력: " << sc.Car::getHP() << endl;
	return 0;
}
