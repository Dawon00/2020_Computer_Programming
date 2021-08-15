#include <vector>
#include <iostream>
using namespace std; 

int main(){
	
	vector<int> v;
	
	cout << v.size()<<endl;//0

	v.push_back(10); // 10
	v.push_back(20); // 10 20
	v.push_back(30); // 10 20 30

	cout << v.size() << endl;//3
	
	for(int i=0; i < v.size(); i++)
		cout << v[i] <<endl; //10 20 30
	
	v.pop_back();
	
	cout << v.size() << endl;//2
	
	for(int i=0; i < v.size(); i++)
		cout << v[i] <<endl; //10 20

}


#include <vector>
#include <iostream>
using namespace std; 

int main(){
	
	vector<int> v;

	v.push_back(10); // 10
	v.push_back(20); // 10 20
	v.push_back(30); // 10 20 30
	v.push_back(40); // 10 20 30 40
	v.push_back(50); // 10 20 30 40 50
	
	vector<int>::iterator iter;
	iter = v.begin();
	cout << *iter << endl; //10
	cout << iter[2] << " " << *(iter+2) << endl;//30 30
	cout << "-----------------------------" << endl;
	iter = v.end();
	cout << *iter << endl;//0
	cout << "-----------------------------" << endl;
	
	v.erase(v.begin()+1);//2번째 원소지움
	
	for (iter=v.begin(); iter!=v.end(); ++iter)
		cout << *iter << endl;//10 30 40 50
	
}
