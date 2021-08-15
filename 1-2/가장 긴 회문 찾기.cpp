#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char input[100];//문자를 저장해줄 input
	cin >> input;//문자를 입력
	int len = strlen(input);//len은 input의 길이
	//대문자는 모두 소문자로 바꾸어 준다. for 반복문으로 input에 들어있는
	//모든 문자를 검사해서 대문자라면 32를 더해 (아스키코드사용) 소문자화 해준다.
	for (int k = 0; k < len; k++) {
		if (input[k] >= 'A' && input[k] <= 'Z') {
			input[k] = input[k] + 32;
		}
	}
	int count = 0;//회문의 글자수를 셀 변수
	int max_1 = 1;//회문의 최대 길이를 저장할 변수. 회문이 홀수일때
	int max_2 = 1;//회문의 최대 길이를 저장할 변수. 회문이 짝수일때

	int start_2=0;//회문이 짝수일때 최대회문의 첫글자의 인덱스
	int temp_start_2 = 0;//회문이 짝수일때 회문의 첫글자의 인덱스
	int end_2=0;//회문이 짝수일때 최대회문의 마지막글자의 인덱스
	int temp_end_2 = 0;//회문이 짝수일때 회문의 마지막글자의 인덱스
	int start_1=0;//회문이 홀수일때 최대회문의 첫글자의 인덱스
	int temp_start_1 = 0;//회문이 홀수일때 회문의 첫글자의 인덱스
	int end_1=0;//회문이 홀수일때 최대회문의 마지막글자의 인덱스
	int temp_end_1 = 0;//회문이 홀수일때 회문의 마지막글자의 인덱스
	

	
		//회문의 길이가 짝수라면
		//i로 input[0]부터 하나씩 오른쪽으로 옮겨가면서 양쪽의 글자가 회문인지 검사
			for (int i = 0; i < len; i++) {
				count = 0;//새로운 검사를 시작할때마다 count는 0으로 초기화
				//변수 j로 양쪽의 글자를 검사해서 같다면 회문이라고 한다.
				for (int j = 0; j < len; j++) {
					//만약 input의 인덱스범위를 벗어나면 for문을 빠져나오도록 한다.
					if ((i - j < 0) || (i + j >= len - 1))
						break;
					else if (input[i - j] == input[i + j + 1]) {
						//양쪽을 검사해서 회문이라면 양 방향이니까 2씩 카운트해준다.
						count += 2;
						temp_start_2 = i - j; //회문의 시작 인덱스를 저장
						temp_end_2 = i + j + 1; //회문의 끝 인덱스를 저장
					}
					//회문이 아니라면 반복문을 빠져나온다
					else
						break;
				}
				//찾은 회문이 기존의 최대회문보다 길이가 긴지 확인한다.
				//만약 더 길다면 최대회문을 갱신해주기 위해 최대 회문의 시작,끝인덱스를 바꿔준다.
				if (count > max_2) {
					max_2 = count;
					start_2 = temp_start_2;
					end_2 = temp_end_2;
				}
				//찾은 회문과 기존 최대 회문의 길이가 같다면 사전식으로 더 앞서야 갱신되도록 한다.
				else if (count == max_2) {
					//글자를 비교했을때 만약 찾은 회문의 아스키코드가 더 작다면(사전순으로 더 앞이라면)
					if (input[temp_start_2] < input[start_2]) {
						//최대 회문 길이값과 시작점, 끝점 인덱스를 갱신해준다.
						max_2 = count;
						start_2 = temp_start_2;
						end_2 = temp_end_2;
					}
				}
			}
		
		//회문의 길이가 홀수라면
		//i로 input[0]부터 하나씩 오른쪽으로 옮겨가면서 양쪽의 글자가 회문인지 검사
			for (int i = 0; i < len; i++) {
				count = 1;//새로운 검사를 시작할때마다 count는 0으로 초기화
				//변수j로 양쪽의 글자를 검사해서 같다면 회문이라고 한다.
				for (int j = 1; j <= len; j++) {
					//만약 input의 인덱스 범위를 벗어나면 for문을 빠져나오도록 한다.
					if ((i - j < 0) || (i + j >= len))
						break;
					else if (input[i - j] == input[i + j]) {
						//양쪽을 검사해서 회문이라면 양방향이니까 2씩 카운트해준다.
						count += 2;
						temp_start_1 = i-j;//회문의 시작 인덱스를 저장
						temp_end_1 = i+j;//회문의 끝 인덱스를 저장
					}
					//회문이 아니라면 반복문을 빠져나온다
					else
						break;
				}
				//찾은 회문이 기존의 최대회문보다 길이가 긴지 확인한다.
				//만약 더 길다면 최대회문을 갱신해주기 위해 최대 회문의 시작, 끝 인덱스를 바꿔준다.
				if (count > max_1) {
					max_1 = count;
					start_1 = temp_start_1;
					end_1 = temp_end_1;
				}
				//찾은 회문과 기존 최대 회문의 길이가 같다면 사전식으로 더 앞서야 갱신되도록 한다
				else if (count == max_1) {
					//글자를 비교했을때 만약 찾은 회문의 아스키코드값이 더 작다면 (사전순으로 더 작다면)
					if (input[temp_start_1] < input[start_1]) {
						//최대 회문의 길이값과 시작점, 끝점 인덱스를 갱신해준다.
						max_1 = count;
						start_1 = temp_start_1;
						end_1 = temp_end_1;
					}
				}
			}
			
			if (max_1 > max_2) { //홀수일때 회문이 더 길면
				cout << max_1 << endl;//홀수일 때의 최대회문길이를 출력
				
				//최대회문의 시작, 끝 인덱스를 이용해서 최대회문도 출력해준다
				for (int i = start_1; i <= end_1; i++) {
					cout << input[i];
				}
			}

			else {//짝수일때 회문이 더 길면
				cout << max_2 << endl;//짝수일때의 최대 회문길이를 출력
				
				//최대회문의 시작, 끝 인덱스를 이용해서 최대회문도 출력해준다
				for (int i = start_2; i <= end_2; i++) {
					cout << input[i];
				}
			}
			
		
	
	return 0;
}
