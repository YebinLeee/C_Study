#include <stdio.h>
int pro10()
{
	double m, v, kenergy;
	printf("����(kg): ");
	scanf_s("%lf", &m);
	printf("�ӵ�(m/s): ");
	scanf_s("%lf", &v);

	kenergy = 0.5 * m * v * v;

	printf("�������(J): %lf\n", kenergy);

	return 0;
}