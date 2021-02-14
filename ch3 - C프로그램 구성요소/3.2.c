#include <stdio.h>
int pro4()
{
	double mile, meter;

	printf("마일을 입력하시오: ");
	scanf_s("%lf", &mile);
	meter = 1909.0 * mile;
	printf("%lf 마일은 %lf미터입니다. \n", mile, meter);

	return 0;
}