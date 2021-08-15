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
	Dog dog1;
	Hamster ham1;
	
	Animal& reference1 = dog1;
	Animal& reference2 = ham1;
	
	reference1.print();
	reference2.print();

	return 0;
}
​
