// 구의 표면적과 체면적을 구하는 프로그램
#include <stdio.h>

int main(void)
{
	double radius;
	double const π = 3.141592; // 파이를 기호상수를 사용하여 정의한다.

	printf("구의 반지를 입력하시오: ");
	scanf("%lf", &radius);

	printf("표면적은 %lf입니다.\n", 4 * π * radius * radius);
	printf("체적은 %lf입니다.\n", 4.0/3.0 * π * radius * radius * radius);


	return 0;
}