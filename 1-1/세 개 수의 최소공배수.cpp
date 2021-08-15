#include <stdio.h>

int gcm(int x, int y) // 최대공약수 구하는 함수
{
    int result = 1;//결과값 변수 1로 초기화
    for (int i = 1; i <= x; i++) //i가 1부터 첫번째 수까지 1씩 증가
    {
        if (!(x % i) && !(y % i)) // x와 y가 i로 나누어 떨어질 때
            result = i; //i값을 반환함
    }
    return result; //결과값을 반환함
}
int lcm(int x, int y) // 두 수의 최소공배수 구하는 함수
{
    return x * y / gcm(x, y); // 두수를 곱하고 최대공약수로 나눈값을 반환
}
int main() { //메인함수
    int num1, num2, num3; //num1, num2,num3 변수를 선언
    scanf_s("%d", &num1); //num1값을 입력받음
    scanf_s("%d", &num2); //num2값을 입력받음
    scanf_s("%d", &num3); //num3값을 입력받음

                                      //lcm_save는 최소공배수를 저장해두는 변수
    int lcm_save = lcm(num1, num2);   //num1과 num2의 최소공배수를 구해서 lcm_save에저장
    lcm_save = lcm(num3, lcm_save);   //num3와 lcm_save에 저장된 값의 최소공배수를 구해서 lcm_save에 다시 저장
    printf("세 자연수의 최소공배수: %d\n", lcm_save);  //lcm_save에 저장되어 있는 값을 출력


}
