#include <stdio.h>
int pro6()
{
	double c_temp, f_temp;
	printf("화씨값을 입력하시오: ");
	scanf_s("%lf", &f_temp);
	c_temp = 5.0 / 9.0 * (f_temp - 32.0);	// 실수형으로 c_temp를 저장하기 위해서는 수식의 피연산자 또한 실수형으로.
	printf("섭씨값은 %lf도입니다.\n", c_temp);
	return 0;
}