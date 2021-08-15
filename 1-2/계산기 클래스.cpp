#include <iostream>
using namespace std;

class Calculator {//계산기 클래스
	int a=0; //입력할 값
	int x=0; //현재 값 변수
	int memory=0; //메모리값 변수
public:
	//현재 값을 x로 설정
	void setValue() {
		cin >> a; //a를 입력받고 x에 대입한다
		x = a;
	}
	//현재 값을 반환함
	int getValue(){
		return x;//x를 반환한다
	}
	//현재 값에 a를 더한 값이 현재값이 되고 이 값을 반환
	int add() {
		cin >> a;//a를 입력받고 x와 더한 후 이 값을 x에 대입한다
		x = x + a;
		return x;//x를 반환한다
	}
	//현재 값에서 a를 뺀 값이 현재값이 되고 이 값을 반환
	int sub() {
		cin >> a;//a를 입력받고 x에서 이 값을 뺀후 이 결과값을 x에 대입한다
		x = x - a;
		return x; //x를 반환한다
	}
	//현재 값에 a를 곱한 값이 현재값이 되고 이 값을 반환
	int multiply() {
		cin >> a;//a를 입력받고 x와 곱한후 이 값을 x에 대입한다
		x = x * a;
		return x;//x를 반환한다
	}
	//현재 값을 a로 나눈 몫이 현재값이 되고 이 값을 반환
	int divide() {
		cin >> a;//a를 입력받고 x를 a로 나눈 뒤 이 값을 x에 대입한다
		x = x / a;
		return x;//x를 반환한다
	}
	//현재 값을 a로 나눈 나머지가 현재 값이 된다.
	int mod() {
		cin >> a;//a를 입력받고 x를 a로 나눈 나머지를 x에 대입한다
		x = x % a;
		return x;//x를 반환한다
	}
	//현재 값의 부호를 바꾼다.
	void changeSign() {
		x = x * (-1);//x에 -1를 곱하여 부호를 바꿔준다
	}
	//현재 값을 0으로 함.
	void clear() {
		x = 0;//x에 0을 대입한다
	}
	//현재 값을 메모리에 저장(현재값을 메모리 값으로 설정)
	void memorySave() {
		memory = x;//x의 값을 memory에 대입한다
	}
	//메모리에 있는 값을 현재 값으로 설정함(현재 값이 변함)
	void memoryRead() {
		x = memory;//memory의 값을 x에 대입한다
	}
	//메모리에 저장된 값을 0으로 둠
	void memoryClear() {
		memory = 0;//memory를 0으로 초기화
	}
	//메모리에 저장된 값에 현재값을 더해서 그 결과값을 메모리에 저장
	void memoryAdd() {
		memory = memory + x;//memory에 x를 더하고 그 값을 메모리에 저장
	}
	//메모리에 저장된 값에서 현재값을 빼서 그 결과값을 메모리에 저장
	void memorySub() {
		memory = memory - x;//memory 에서 x를 빼고 그 값을 메모리에 저장
	}
	//현재 값을 출력함
	void result() {
		cout << x;//x를 출력한다(현재값)
	}
	

};



int main(void) {
	Calculator cal;//cal이라는 객체 생성
	string input;//명령어를 입력할 변수 input
	

	while (1) {//quit을 입력받기 전까지 반복하는 반복문
		cin >> input; //명령어를 입력받는다
		if (input == "setValue") { //setValue 함수 실행
			cal.setValue();
			
		}
		else if (input == "add") { //add함수 실행
			cal.add();
		}
		else if (input == "sub") {//sub 함수 실행
			cal.sub();
		}
		else if (input == "mul") {//multiply 함수 실행
			cal.multiply();
		}
		else if (input == "div") {//divide 함수 실행
			cal.divide();
		}
		else if (input == "mod") {//mod함수 실행
			cal.mod();
		}
		else if (input == "change") {//changeSing 함수 실행
			cal.changeSign();
		}
		else if (input == "clear") {//clear 함수 실행
			cal.clear();
		}
		else if (input == "MS") {//memorySave 함수 실행
			cal.memorySave();
		}
		else if (input == "MR") {//memoryRead 함수 실행 후 현재값을 출력
			cal.memoryRead();
			cout << cal.getValue() << endl;
		}
		else if (input == "MPlus") {//memoryAdd 함수 실행
			cal.memoryAdd();
		}
		else if (input == "MMinus") {//memorySub 함수 실행
			cal.memorySub();
		}
		else if (input == "MC") {//memoryClear 함수 실행
			cal.memoryClear();
		}
		else if (input == "result") {//현재값을 출력한다
			cout << cal.getValue()<<endl;
		}
		else if (input == "quit") {//반복문을 종료
			break;
		}
		
	}
	return 0;
}
