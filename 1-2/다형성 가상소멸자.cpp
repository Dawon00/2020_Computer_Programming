#include <iostream>
#include <cstring>
using namespace std;

class Animal{
public:
	Animal() { cout <<"Animal 생성자" << endl; }
	virtual ~Animal() { cout <<"Animal 소멸자" << endl; }
	virtual void speak() { cout <<"Animal speak()" << endl; }
};

class Dog : public Animal{
 char* name;
public:
	Dog(char* h){ // 문자열 받음
		cout <<"Dog 생성자" << endl;
		name = new char[strlen(h)+1];
		strcpy(name, h);
	}
	~Dog(){
		cout <<"Dog 소멸자" << endl;
		delete[] name;
	}
	void speak() { cout <<"멍멍" << endl; }
};

class Cat : public Animal{
	char* name;
public:
	Cat(char* h){
		cout <<"Cat 생성자" << endl;
		name = new char[strlen(h)+1];
		strcpy(name, h);
	}
	~Cat(){
		cout <<"Cat 소멸자" << endl;
		delete[] name;
	}
	void speak() { cout <<"야옹" << endl; }
};
int main()
{
	Animal *a1 = new Dog("choco");
	a1->speak();
	delete a1;
	Animal *a2 = new Cat("tiger");
	a2->speak();
	delete a2;
	return 0;
}
