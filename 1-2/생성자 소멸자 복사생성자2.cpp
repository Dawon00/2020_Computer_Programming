#include <iostream>
using namespace std;

class Point {
	int x,y;
public:
	Point() //
	{
		cout << "Class Point Default Constructor\n";
		x = 0; y = 0;
	}

	Point(int a, int b) //
	{
		cout << "Class Point Constructor with Parameters\n";
		x = a; y = b;
	}

	Point(Point& p)
	{
		cout << "Class Point Copy Constructor\n";		
		x = p.x;
		y = p.y;
	}

	~Point()
	{	
		cout << "Class Point Destructor\n";
	}

};

void f(Point p) // p의 복사생성자가 수행 
{
}

int main()
{
	
// 생성자, 소멸자 수행시기 확인 
	Point p;
	
	{
		Point p1;
	}
	
	{
		Point p1;
	}

	Point p1(20,30);
	f(p1);

	return 0;	
}
​
