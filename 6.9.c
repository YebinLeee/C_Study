#include <stdio.h>

int main(void)
{
	float x, result;

	printf("x�� ���� �Է��Ͻÿ�: ");
	scanf_s("%f", &x);

	if (x > 0)
		result = 7 * x + 2;
	else
		result = x * x - 9 * x + 2;

	printf("f(x)�� ���� %f \n", result);

	return 0;
}