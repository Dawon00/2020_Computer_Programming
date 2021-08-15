#include <iostream>
#include <string>
using namespace std;

class animal{

public:
	animal(int x){ cout << "생성자 animal" << endl; }
	~animal(){ cout << "소멸자 animal" << endl; }
};

class hamster : public animal{

public:
	hamster(int x) : animal(x){ cout << "생성자 hamster" << endl; }
	~hamster(){ cout << "소멸자 hamster" << endl; }
};


int main() {
	
	hamster hamster1(1); 

}
