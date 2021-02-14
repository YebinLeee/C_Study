#include <stdio.h>
int pro8()
{
	double weight, weight_on_moon;
	printf("몸무게를 입력하시오(단위: kg): ");
	scanf_s("%lf", &weight);
	weight_on_moon = weight * 0.17;
	printf("달에서의 몸무게는 %lfkg입니다.\n", weight_on_moon);

	return 0;
}