#include <stdio.h>
int pro5()
{
	double height, base, area;

	printf("»ï°¢ÇüÀÇ ¹Øº¯: ");
	scanf_s("%lf", &base);
	printf("»ï°¢ÇüÀÇ ³ôÀÌ: ");
	scanf_s("%lf", &height);

	area = 0.5 * base * height;
	printf("»ï°¢ÇüÀÇ ³ĞÀÌ: %lf\n", area);

	return 0;
}