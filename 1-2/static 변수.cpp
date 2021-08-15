#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	static int count;//변수를 공유한다
	Car(){//Car 만들때마다 count가 1씩 증가됨
		count+=1;
	}

};
int Car::count = 0;//처음엔 카운트가 0

int main()
{
	Car myCar;	
	cout << myCar.count << endl;	
	Car yourCar;		
	cout << yourCar.count << endl;	
	cout << myCar.count << endl;
	cout << Car::count << endl;	

	return 0;
}
​
