#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() {
		setA(5); 						// ①private으로 상속받아서 가능
		showA(); 					// ②같은 이유로 가능
		cout << b;
	}
};
class GrandDerived : private Derived {
	int c;
protected:
	void setAB(int x) {
		//setA(x); 						// ③불가능, 직접접근만 가능
		//showA(); 					// ④ 불가능
		setB(x); 						// ⑤가능
	}
};

int main() {
	GrandDerived x;
	
	x;
}
