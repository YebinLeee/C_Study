#include <stdio.h>
int pro8()
{
	double weight, weight_on_moon;
	printf("�����Ը� �Է��Ͻÿ�(����: kg): ");
	scanf_s("%lf", &weight);
	weight_on_moon = weight * 0.17;
	printf("�޿����� �����Դ� %lfkg�Դϴ�.\n", weight_on_moon);

	return 0;
}