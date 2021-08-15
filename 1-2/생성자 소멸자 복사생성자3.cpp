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

Point g(Point p)
{
    return p;	
} 

int main()
{
	
	Point p1(20,30);
	
	Point p;
	
	p = g(p1);
	
	return 0;	
}
