#include <iostream>
#include <vector>
using namespace std;

void sum(vector<int> v, int n) {//첫번째 sum 함수
// (1)	
	int s = 0;
	for (int i = 0; i < n; i++)
		s += v[i];

	cout << "method 1: " << s << endl;

}

void sum2(vector<int> v, int n) {
	// (2)iterator
	int s = 0;
	vector <int> ::iterator iter;

	for (iter = v.begin(); iter != v.end(); ++iter) {
		s += *iter;
	}
	cout << "method 2: " << s << endl;
}

int main()
{
	vector<int> score;
	int n;
	int mark;

	cin >> n; //개수 입력받기

	for (int i = 0; i < n; i++) {
		cin >> mark;
		score.push_back(mark);//score에 n개의 점수를 입력받음
	}

	sum(score, n);
	sum2(score, n);
}
#include <iostream>
#include <vector>
using namespace std;

void sum(vector<int> v, int n){
// (1)
	int s=0;
	//vector<int>::iterator iter;
   for (auto iter=v.begin(); iter!=v.end(); ++iter)
      s += *iter;
   
   cout << "method 3: " << s << endl;
}

void sum2(vector<int> v, int n){
// (2)
	 int s = 0;
   for(int x:v)
      s += x;
      
   cout << "method 4: " << s << endl;
}

int main()
{
	vector<int> score;
	int n;
	int mark; 
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> mark;
		score.push_back(mark);
	}
	
	sum(score, n);
	sum2(score, n);
}
​
