#include <iostream>

using namespace std;

class Calculator {
private:
	int value;//이 vaule에 접근하려면 멤버 함수를 이용해야한다
public://생성자 클래스 이름이랑 똑같이 만들기
	Calculator() {
		value = 0;//value가 0으로 초기화
	}
	int add(int num) {
		value += num;
		return value;
	};
	int sub(int num) {
		value -= num;
		return value;
	}
	int currentValue() {
		//현재 value값 반환
		cout << value << endl;
		return value;
	}
};

	int main()
	{
		Calculator c;

		string command;

		c = Calculator();

		while (1) {
			cin >> command;//입력

			if (command == "add") {
				int num;
				cin >> num;
				c.add(num);
			}
			else if (command == "sub") {
				int num;
				cin >> num;
				c.sub(num);

			}
			else if (command == "result") {
				c.currentValue();
				
			}
			else if (command == "quit")
			{
				cout << "종료합니다." << endl;
				break;
			}
		}
		return 0;
	}

​
