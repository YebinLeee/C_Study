#include <stdio.h>
#define SQRMETER_PER_PYEONG 3.3058

int pro8()
{
	double pyeong;
	printf("���� �Է��Ͻÿ�: ");
	scanf_s("%lf", &pyeong);

	double meter = SQRMETER_PER_PYEONG * pyeong;
	printf("%lf �����Դϴ�. \n", meter);

	return 0;
}