#include <stdio.h>
#define SIZE 3
int pro3()
{
	double a[SIZE], sum=0, avg;
	for (int i = 0;i < SIZE;i++)
	{
		printf("실수를 입력하시오: ");
		scanf_s("%lf", &a[i]);
		sum += a[i];
	}
	avg = sum / SIZE;

	printf("합은 %lf이고 평균은 %lf입니다.\n", sum, avg);
	
	return 0;
}