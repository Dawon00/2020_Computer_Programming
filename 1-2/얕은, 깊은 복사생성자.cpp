#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(char* s, int number)
	{
		name = new char[strlen(s)+1];
		strcpy(name, s);
		id = number;
	}	

	Person(Person& p) // 복사생성자 
	{
		name = p.name;
		id = p.id;
	}	

	void changeName(char* s)
	{
		delete [] name;
		name = new char[strlen(s)+1];
		strcpy(name,s);
	}
	
	char* getName()
	{
		return name;
	}
	
	~Person()
	{
		delete[] name; // 동적 메모리 해제
	}
};

int main()
{
	
	Person p1("Park", 20201010);
	Person p2(p1);
	p2.changeName("Han");
	cout << p1.getName() << endl;
	cout << p2.getName() << endl;

	return 0;
}


//깊은 복사 생성자

#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(char* s, int number)
	{
		name = new char[strlen(s)+1];
		strcpy(name, s);
		id = number;
	}	

	Person(Person& p) // 복사생성자 
	{
		name = new char[strlen(s)+1];
		strcpy(name, s);
		id = p.id;
	}	

	void changeName(char* s)
	{
		delete [] name;
		name = new char[strlen(s)+1];
		strcpy(name,s);
	}
	
	char* getName()
	{
		return name;
	}
	
	~Person()
	{
		delete[] name; // 동적 메모리 해 
	}
};

int main()
{
	
	Person p1("Park", 20201010);
	Person p2(p1);
	
	p2.changeName("Han");
	cout << p1.getName() << endl;
	cout << p2.getName() << endl;

	return 0;
}
​
