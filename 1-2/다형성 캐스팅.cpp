#include <iostream>

using namespace std;

class Animal{
public:
	void print()
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

class Pomeranian : public Dog
{
public:
	void print()
	{
		cout << "I'm pome" << endl;
	}
};

int main()
{
	Animal* pointer1 = new Animal();
	Dog* pointer2 = new Dog();
	Pomeranian* pointer3 = new Pomeranian();

	pointer1->print();   //(*pointer1).print();
	pointer2->print();
	pointer3->print();
	
	cout << "--------------------" << endl;
	
	Animal* pointer4 = new Dog(); // 상향식
	//Dog* pointer5 = new Animal(); // 하향식

	pointer4->print();
	//pointer5->print();
	
	cout << "--------------------" << endl;
	
	Animal* pointer6 = new Pomeranian();
	//Pomeranian* pointer7 = new Animal();
	
	pointer6->print();
	//pointer7->print();

	return 0;
}
