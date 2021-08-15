#include <iostream>

using namespace std;

class Animal{ // 객체화 못함
public:
	virtual void print() = 0; //순수가상함수
	
};

class Dog : public Animal
{
public:
	void print()
	{
		cout << "woof woof" << endl;
	}
};

class Hamster : public Animal
{
public:
	void print()
	{
		cout << "ki ki" << endl;
	}
};

int main()
{
	//Animal a;
	Animal* pointer = new Dog();
	Animal* pointer2 = new Hamster();
	
	pointer->print();
	pointer2->print();

	return 0;
}
​
