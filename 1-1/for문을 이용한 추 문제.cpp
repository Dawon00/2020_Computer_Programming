#include <stdio.h>
using namespace std;
int main() {
	int n2, n3, n5, nt, total;
	printf("사과의 무게를 입력하시오: ");
    scanf_s("%d", &nt);
		

		printf("\n모든 경우의 수는 다음과 같습니다.\n");
		for (int n2 = 0; n2 <= 10; n2++)
		{
			for (int n3 = 0; n3 <= 10; n3++)
			{
				for (int n5 = 0; n5 <= 10; n5++)
				{
					total = 2 * n2 + 3 * n3 + 5 * n5;
					if (total == nt)
						printf("5g: %d개 3g: %d개 2g: %d개\n", n5, n3, n2);

				}

			}

        }



}
