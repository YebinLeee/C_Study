#include <stdio.h>
int pro5()
{
	double height, base, area;

	printf("�ﰢ���� �غ�: ");
	scanf_s("%lf", &base);
	printf("�ﰢ���� ����: ");
	scanf_s("%lf", &height);

	area = 0.5 * base * height;
	printf("�ﰢ���� ����: %lf\n", area);

	return 0;
}