#include <stdio.h>
int pro7()
{
	double volume, length, height, width;
	printf("상자의 가로 세로 높이를 한번에 입력하시오: ");
	scanf_s("%lf %lf %lf", &width, &length, &height);

	volume = width * height * length;
	printf("상자의 부피는 %lf입니다.\n", volume);

	return 0;
}