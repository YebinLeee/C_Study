#include <stdio.h>
int main(void)
{
	double height, weight;

	printf("체중과 키를 입력하세요: ");
	scanf_s("%lf %lf", &height, &weight);

	if (weight > (height - 100) * 0.9)
		printf("과체중입니다. \n");
	else if (weight < (height - 100) * 0.9)
		printf("저체중입니다. \n");
	else
		printf("정상입니다. \n");

	return 0;
}