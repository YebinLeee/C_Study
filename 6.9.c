#include <stdio.h>

int main(void)
{
	float x, result;

	printf("x의 값을 입력하시오: ");
	scanf_s("%f", &x);

	if (x > 0)
		result = 7 * x + 2;
	else
		result = x * x - 9 * x + 2;

	printf("f(x)의 값은 %f \n", result);

	return 0;
}