#include <stdio.h>
#define SQRMETER_PER_PYEONG 3.3058

int pro8()
{
	double pyeong;
	printf("평을 입력하시오: ");
	scanf_s("%lf", &pyeong);

	double meter = SQRMETER_PER_PYEONG * pyeong;
	printf("%lf 미터입니다. \n", meter);

	return 0;
}