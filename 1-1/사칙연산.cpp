#include <stdio.h>
using namespace std;
int main(void)
{

int x;
int y;
int add, sub, mul, div, mok;

printf("What is a? = ");
scanf_s("%d, &x);

printf("What is b? = ");
scanf_s("%d, &y);

printf("====================\n";
add = x + y;
sub = x - y;
mul = x * y;
div = x / y;
mok = x % y;

printf("a+b is = %d\n", add);
printf("a-b is = %d\n", sub);
printf("a*b is = %d\n", mul);
printf("a/b is = %d\n", div);
printf("a%%b is = %d\n", mok);
printf("====================\n");

return 0;

}
