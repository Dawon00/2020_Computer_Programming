#include <stdio.h>
using namespace std;
int main(void)
{
	int price; // 물건가격
	int payment; // 지불금액
	int c5000; // 5000원권 지폐의 개수
	int c1000; // 1000원권 지폐의 개수
	int c500; // 500원 동전의 개수
	int c100; // 100원 동전의 개수


	printf("물건가격은 얼마인가? "); // 물건가격을 입력받기 위한 안내문구
	scanf_s("%d", &price); // 물건가격을 입력받아 price에 저장

	printf("지불금액은 얼마인가? "); // 지불금액을 입력받기 위한 안내문구
	scanf_s("%d", &payment); // 지불금액을 입력받아 payment에 저장

	

	int change; // 거스름돈 변수선언
	change = payment - price; // 거스름돈은 지불금액에서 물건가격을 뺀 값이다.

	c5000 = change / 5000; // 5000원권의 개수를 구한다.
	change = change % 5000; // 남은 잔돈을 계산한다.

	c1000 = change / 1000; // 1000원권의 개수를 구한다.
	change = change % 1000; // 남은 잔돈을 계산한다.

	c500 = change / 500; // 500원 동전의 개수를 계산한다.
	change = change % 500; // 남은 잔돈을 계산한다.

	c100 = change / 100; // 100원 동전의 개수를 계산한다.
	change = change % 100; // 남은 잔돈을 계산한다.


	if (price > payment) // 물건가격이 지불금액보다 크다면 구입할 수 없는 경우(조건문 사용)
		printf("%d 원이 부족합니다.", price - payment); // 부족한 금액을 출력한다.

	else // 반대로, 지불금액이 물건가격보다 커서 구입할 수 있는 경우(조건문 사용)
	{
		if (c5000 <= 5) // 5000원권 지폐가 5장 이하인경우(최대 5장까지 밖에 사용하지 못하므로)
		{
			printf("5000원 지폐: %d 장\n", c5000); // 5000원 지폐의 개수를 출력한다.
			printf("1000원 지폐: %d 장\n", c1000); // 1000원 지폐의 개수를 출력한다.
			printf("500원 동전: %d 개\n", c500); // 500원 동전의 개수를 출력한다.
			printf("100원 동전: %d 개\n", c100); // 100원 동전의 개수를 출력한다.
		}

		else // 5000원권 지폐가 5장보다 더 많이 필요한경우
		{
			change = payment - price; // 거스름돈은 지불금액에서 물건가격을 뺀 값이다.

			c5000 = 5; // 5000원권 지폐는 5장으로 고정.
			c1000 = (change - 5 * 5000) / 1000; // 1000원권 지폐의 개수는 거스름돈에서 (5000원 * 5장)을 뺀 값을 1000으로 나눈 몫이다.
			change = change % 1000; // 남은 잔돈을 계산한다.
			c500 = change / 500; // 500원 동전의 개수를 구한다.
			change = change % 500; // 남은 잔돈을 계산한다.
			c100 = change / 100; // 100원 동전의 개수를 구한다.
			change = change % 100; // 남은 잔돈을 계산한다.
			

			printf("5000원 지폐: 5 장\n"); // 5000원 지폐의 개수를 출력한다(5장으로 고정)
			printf("1000원 지폐: %d 장\n", c1000); // 1000원 지폐의 개수를 출력한다.
			printf("500원 동전: %d 개\n", c500); // 500원 동전의 개수를 출력한다.
			printf("100원 동전: %d 개\n", c100); // 100원 동전의 개수를 출력한다.
		}
	}


		return 0;

}
