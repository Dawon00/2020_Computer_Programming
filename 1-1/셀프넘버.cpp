#include <stdio.h>



int solution(int n) //solution함수 선언
{
	int num = n;//첫 수
	int result = 0;//결과값

	int temp = num;//나누고 나머지 계산할 변수


	while (1) //1 = True 이므로 계속 반복
	{

		result += (temp % 10);//일의자리는 더하기

		if (temp / 10 == 0)//몫이 0이면 더이상 계산할게 없음
		{
			break;//while문을 빠져나온다
		}
		else
		{
			temp = temp / 10;//몫이 남아있다면 몫부분만 넣기
		}
		
	}
	result += num;//첫 수와 결과값을 더해준다
	return result;//결과값 반환
}

int main()//메인함수
{
	int n;//변수n선언
	printf("N is = ");//값을 입력받기위한 안내메세지
	scanf_s("%d", &n);//n값을 입력한다

	int limit = 5 * n;//5*n값을 limit라는변수에 고정시킨다.

    while (1)//1=True이므로 계속반복
		{
			printf("%d\n", solution(n));//solution(n)의값을 출력
			n = solution(n);//solution함수에 n을 대입한 값을 다시 n에 대입
			
			if(solution(n)>limit)//만약 solution(n)값이 limit(=5*n)값을 넘는다면
			break;//while문을 빠져나온다
		}
	return 0;
