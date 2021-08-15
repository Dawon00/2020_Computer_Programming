#include <iostream>
#include <vector>
using namespace std;

class Account {
	int account_number;  //계좌번호
	int id; //아이디
	int balance;  //잔액
public:
	//생성자
	Account(int _account_number, int _id, int _balance)
	{
		account_number = _account_number;
		id = _id;
		balance = _balance;
	}
	
	int getAccNo()
	{
		return account_number;
	} 
	int getBalance()
	{
		return balance;
	} 
	void setBalance(int num)//입금하기
	{
		balance += num;
	}

};

int findIndex(vector<Account>v, int n)
	//계좌번호와 벡터 넘겨줌 -> 몇번째 인덱스에 존재? 존재 안하면 -1리턴
{
	for(int i=0; i< v.size();i++){
		if(n==v[i].getAccNo())
			return i;
	}
	return -1;
}

int main()
{
	vector<Account> b;
	string command;
	int start = 1111;
	int id;
	int n;

	while(1){
		cin >> command;
		
		if (command == "new"){// new id 돈
			cin >> id;
			cin >> n;//돈 얼마 입금할건지
			
			b.push_back(Account(start,id,n));
			
			start += 1;//다음 계좌로 넘어가기
		}
		else if (command == "deposit"){//deposit 계좌번호 돈 입금
			int result;
			cin >> id >> n;
			result = findIndex(b,id);//계좌 존재하는지 확인
			
			if (result != -1){//존재하면
				b[result].setBalance(n);//입금하기
			}
		}		
		else if (command == "inquiry"){//inquiry 계좌번호
			int result, bal;
			cin >> id;
			result = findIndex(b,id);
			
			if(result != -1){//존재하면
				bal = b[result].getBalance();
				cout << "balance: " << bal << endl;
			}
		}		
		else if (command == "quit")//종료
			break;
	}
	return 0;
}
