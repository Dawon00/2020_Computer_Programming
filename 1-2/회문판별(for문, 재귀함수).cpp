#include <iostream>//C++
#include <string>
using namespace std;

bool isPalindrome1(string str)//for문 이용
{
	for(int i=0; i<str.length();i++){
		if(str[i] != str[str.length()-i-1])
			return false;
	}
	return true;
}

bool isPalindrome2(string str)
{
	if (str.length() <= 1)//1글자 이하면 빠져나가기
		return true;
	//substr 사용
	//만족 안하면 
	if(str.substr(0,1) != str.substr(str.length()-1))
		return false;
	
	return isPalindrome2(str.substr(1,str.length()-2));

}

int main()
{
	string str;
	cin >> str;//str에 입력을 받겠다
	
	cout << isPalindrome1(str) << endl;//endl은 \n이랑 비슷

	cout << isPalindrome2(str) << endl;
	
	return 0;
}
