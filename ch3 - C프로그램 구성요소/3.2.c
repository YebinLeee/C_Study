#include <stdio.h>
int pro4()
{
	double mile, meter;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%lf", &mile);
	meter = 1909.0 * mile;
	printf("%lf ������ %lf�����Դϴ�. \n", mile, meter);

	return 0;
}