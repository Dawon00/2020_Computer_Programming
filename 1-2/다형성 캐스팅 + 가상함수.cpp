#include <iostream>

using namespace std;

class Animal{
public:
	virtual void print()
	{
		cout << "base Animal" << endl;
	}
};

class Dog : public Animal{
public:
	void print()
	{
		cout << "woof woof" << endl;
	}
};

class Pomeranian : public Dog{
public:
	void print()
	{
		cout << "I'm pome" << endl;
	}
};

int main()
{
	Pomeranian* pointer3 = new Pomeranian();
	pointer3->print();
	cout << "--------------------" << endl;
	
	Animal* pointer6 = new Pomeranian();//Animal 객체 임에도 불구하고 상속받는 개체가 실행이 됨 virtual 처리가 되었기 때문에(가상함수)
	pointer6->print();

	return 0;
}
