#include<stdio.h>
using namespace std;
int main() 
{
//현재 가지고 있는 돈과 캔디의 가격을 변수로 선언
int money, candy_price;

//현재 가지고 있는 돈 정보 받기
printf("현재 가지고 있는 돈: ");
scanf_s("%d", &money);

//캔디의 가격정보 받기
printf("캔디의 가격: ");
scanf_s("%d", &candy_price);

//최대한 살 수 있는 캔디의 개수를 계산하고 출력
printf("최대로 살 수 있는 캔디의 개수=%d\n", money / candy_price);

//캔디 구입 후 남은 돈을 계산하고 출력
printf("캔디 구입 후 남은 돈=%d\n", money % candy_price);

return 0;

}
