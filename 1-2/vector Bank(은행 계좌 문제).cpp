#include <iostream>
#include <vector>
using namespace std;

class Account {
	int accNo;//계좌번호
	int id; //주민등록번호
	int balance; //잔액
public:
	//생성자
	Account(int accNo, int id, int amount)
	{
		this->accNo = accNo;
		this->id = id;
		balance = amount;
	}

	int getAccNo() const
		//멤버변수를 바꾸지 않겠다는 의미
	{
		return accNo;
	}
	int getBalance() const
	{
		return balance;
	}
	int getId() const
	{
		return id;
	}
	void setBalance(int amount)//입금하기
	{
		balance = amount;
	}

};

class Bank {
private:
	vector<Account> b;
	int availableAccNo;//계좌번호
public:
	Bank();
	void create(int id, int amount);//id 돈
	void deposit(int accNo, int amount);
	void inquiry(int accNo) const;//잔액, 계좌없으면 에러1
	void transfer(int fromAccNo, int toAccNo, int amount);//이체, 돈이 부족하면 에러3, 계좌가 없으면 에러1
	int findIndex(int accNo) const;
	void printAccs(int id) const; // sort by accNo
								  //id가 가진 계좌 다 보여줌
								  //계좌가 없으면 에러2
};
//생성자
Bank::Bank()
{
	availableAccNo = 1111;
}


void Bank::create(int id, int amount) {
	//벡터에 Account 추가하기
	b.push_back(Account(availableAccNo, id, amount));
	//이용가능한 계좌의 수를 하나 증가시킴
	availableAccNo++;
}

int Bank::findIndex(int accNo) const {
	for (int i = 0; i < b.size(); i++) {
		if (accNo == b[i].getAccNo())//같은게 있다(계좌가 존재)
			return i;
	}
	//계좌가 존재하지 않으면 -1 리턴
	return -1;
}

//입금하기
void Bank::deposit(int accNo, int amount) {
	//존재하는 계좌인지 확인한다
	int result;
	result = findIndex(accNo);
	//계좌가 존재한다면
	if (result != -1) {
		//newBalance라는 변수에 amount만큼 더해준다
		int newBalance = b[result].getBalance() + amount;
		//newBalance를 계좌의 잔액으로 업데이트한다
		b[result].setBalance(newBalance);
	}
	//확인했는데 존재하지 않는 계좌라면
	else if (result == -1) {//계좌가 없다면
		cout << "error 1" << endl;
	}
}
//잔액 조회하기
void Bank::inquiry(int accNo)const {
	//계좌가 존재하는지 확인
	int result;
	result = findIndex(accNo);
	//만약 계좌가 존재하면
	if (result != -1)
		//그 계좌의 잔액을 출력합니다
		cout << b[result].getBalance() << endl;
	//계좌가 존재하지 않으면
	else
		cout << "error 1" << endl;
}

//계좌가 둘다 존재하는지 확인
//fromAcc의 getBalance해서 잔액 부족하면 에러
void Bank::transfer(int fromAccNo, int toAccNo, int amount) {
	int result1, result2;
	result1 = findIndex(fromAccNo);
	result2 = findIndex(toAccNo);
	
	//둘다 존재하는 계좌라면
	if (result1 != -1 && result2 != -1) {
		//fromAccNo의 잔액이 부족하면
		if (b[result1].getBalance() < amount) {
			cout << "error 3" << endl;
		}
		//돈을 보내기에 잔액이 충분하다면
		else {
			//fromAccNo에서는 amount만큼 빼준다
			int newBalance1 = b[result1].getBalance() - amount;
			//newBalance1를 계좌의 잔액으로 업데이트한다
			b[result1].setBalance(newBalance1);
			//toAccNo에서는 amount만큼 더해준다
			int newBalance2 = b[result2].getBalance() + amount;
			//newBalance2를 계좌의 잔액으로 업데이트한다
			b[result2].setBalance(newBalance2);
		}
	}
	//계좌가 하나라도 존재하지 않는다면
	else
		cout << "error 1" << endl;

}


//inquiry_id로 작동한다. id로 만들어진 모든 계좌를 조회. 계좌 없으면 error2
void Bank::printAccs(int id)const{
	int count=0;//존재하는 계좌의 개수
	for (int i = 0; i< b.size(); i++) {
		//전체 id를 검색했을 때 이 id로 만들어진 계좌가 있다면
		if (b[i].getId() == id) {
			//계좌번호를 출력한다
			cout << b[i].getAccNo() << " " << b[i].getBalance() << endl;
			count++;
		}
	}
	//존재하는 계좌의 개수가 0개라면
	if (count == 0) {
		cout << "error 2" << endl;
	}
}



int main()
{
	Bank b;//클래스 Bank
	string command;//명령어
	int id, amount;
	int accNo;
	while (1) {
		cin >> command;
		if (command == "new") {// 신규
			cin >> id >> amount;
			b.create(id, amount);
		}
		else if (command == "deposit") {
			cin >> accNo >> amount;
			b.deposit(accNo, amount);
		}
		else if (command == "inquiry_acc") {
			cin >> accNo;
			b.inquiry(accNo);
		}
		else if (command == "inquiry_id") {//printAccs
			cin >> id;
			b.printAccs(id);
		}
		else if (command == "transfer") {
			int fromAccNo, toAccNo;
			cin >> fromAccNo >> toAccNo >> amount;
			b.transfer(fromAccNo, toAccNo, amount);
		}
		else if (command == "quit")
			break;
		// withdraw, transfer, id로 accountNo 조회 
	}
	return 0;
}
