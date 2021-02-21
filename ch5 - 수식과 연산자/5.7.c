#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("정수를 입력하시오: ");
	scanf("%d", &num1);
	printf("2를 곱하고 싶은 횟수: ");
	scanf("%d", &num2);
	printf("num1<<num2의 값: %d \n", num1 << num2);


	return 0;
}