#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num1);
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num2);

	if (num1 % num2 == 0)
		printf("����Դϴ�.\n");

	return 0;
}