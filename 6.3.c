#include <stdio.h>

int main(void)
{
	int num1, num2, num3, min;
	
	printf("3���� ������ �Է��Ͻÿ�:");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 < num2) {
		if (num1 < num3)
			printf("���� ���� ������ %d�Դϴ�.\n", num1);
		else
			printf("���� ���� ������ %d�Դϴ�.\n", num3);
	}
	else {
		if (num2 < num3)
			printf("���� ���� ������ %d�Դϴ�.\n", num2);
		else
			printf("���� ���� ������ %d�Դϴ�.\n", num3);
	}

	return 0;
}