#include <stdio.h>

int main(void)
{
	double f_temp, c_temp;

	printf("화씨온도를 입력하세요: ");
	scanf("%lf", &f_temp);
	c_temp = ((double)5 / 9) * (f_temp - 32);

	printf("섭씨온도는 %f입니다. \n", c_temp);

	return 0;
}