#include <iostream>

using namespace std;

class Animal{
public:
	virtual void print()
	{
		cout << "base Animal" << endl;
	}
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
	Animal* pointer = new Dog();
	Animal* pointer2 = new Hamster();
	
	pointer->print();
	pointer2->print();

	return 0;
}
​
