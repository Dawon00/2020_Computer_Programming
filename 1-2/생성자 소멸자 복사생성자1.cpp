#include <iostream>
using namespace std;

class Point {
	int x,y;
public:
	Point() // 생성자를 만들었으므로 이런 생성자가 필요하면 만들어 줘야한다.
	{
		cout << "Class Point Default Constructor\n";
		x = 0; y = 0;
	}

	Point(int a, int b)
	{
		cout << "Class Point Constructor with Parameters\n";
		x = a; y = b;
	}

	Point(Point& p) // 디폴트로 들어갈 수도 있음
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

int main()
{
	Point p1(20,30);

	Point p(p1);
	
	return 0;	
}
​
