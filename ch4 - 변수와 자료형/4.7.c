#include <stdio.h>
int pro10()
{
	double m, v, kenergy;
	printf("질량(kg): ");
	scanf_s("%lf", &m);
	printf("속도(m/s): ");
	scanf_s("%lf", &v);

	kenergy = 0.5 * m * v * v;

	printf("운동에너지(J): %lf\n", kenergy);

	return 0;
}