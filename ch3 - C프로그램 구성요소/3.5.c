#include <stdio.h>
int pro7()
{
	double x, result;
	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf_s("%lf", &x);
	result = 3 * x * x + 7 * x + 11;
	printf("���׽��� ���� %lf�Դϴ�.\n", result);

	return 0;
}