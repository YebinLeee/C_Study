#include <stdio.h>
int pro7()
{
	double volume, length, height, width;
	printf("������ ���� ���� ���̸� �ѹ��� �Է��Ͻÿ�: ");
	scanf_s("%lf %lf %lf", &width, &length, &height);

	volume = width * height * length;
	printf("������ ���Ǵ� %lf�Դϴ�.\n", volume);

	return 0;
}