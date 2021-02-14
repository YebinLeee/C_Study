#include <stdio.h>
int pro1()
{
	int a, b, max, min;
	printf("2개의 정수를 입력하시오: ");
	scanf_s("%d %d", &a, &b);

	if (a > b)
		max = a, min = b;
	else
		max = b, min = a;

	printf("몫:%d 나머지:%d\n\n", max / min, max % min);

	return 0;
}
int pro2()
{
	double a, b;
	printf("2개의 실수를 입력하시오: ");
	scanf_s("%lf %lf", &a, &b);
	printf("합: %lf, 차: %lf, 곱: %lf, 몫: %lf\n\n", a + b, a - b, a * b, a /b);
	return 0;
}
int pro3()
{
	int a, b, c, max;

	printf("3개의 정수를 입력하시오: ");
	scanf_s("%d %d %d", &a, &b, &c);
	
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	// 삼항 조건 연산자식을 이용해서 최댓값을 한 번에 구하기
	
	/*
	max = a > b ? a : b;
	max = max > c ? max : c;
	*/

	printf("최댓값: %d\n", max);

	return 0;
}
int pro4()
{
	int cm, feet;
	double inch;

	printf("키를 입력하시오(cm): ");
	scanf_s("%d", &cm);
	
	inch = cm / 2.54;	// cm를 inch 로 바꾼다.
	feet = inch / 12;	// 그 inch를 feet로 바꾼다. (결국 원래 cm를 feet로 바꾼다.)
	inch = inch-(feet*12);	// 원래 inch에서 feet로 바꾼 데이터를 inch로 다시 바꾸어 남은 inch를 구한다.

	printf("%dcm는 %d피트 %lf인치입니다.\n", cm, feet, inch);

	return 0;
}
int pro5()
{
	int num;
	
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);
	printf("십의자리: %d\n", num / 10);
	printf("일의자리: %d\n", num % 10);
	
	return 0;
}
int pro6()
{
	int num;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);
	printf("2의 보수: %d \n", ~num + 1);
	return 0;
}
int pro7()
{
	int x,y;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &x);
	printf("2를 곱하고 싶은 횟수: ");
	scanf_s("%d", &y);
	printf("x<<y의 값: %d\n\n", x << y);

	return 0;
}
int pro8()
#define PI 3.141592
{
	double radius, surface_area, volume;
	printf("구의 반지름을 입력하시오: ");
	scanf_s("%lf", &radius);

	surface_area = 4 * PI * radius * radius;
	volume = 4 / 3 * PI * radius * radius * radius;
	printf("표면적은 %lf입니다.\n", surface_area);
	printf("체적은 %lf입니다.\n\n", volume);

	return 0;
}
int pro9()
{
	double height, shadow;
	double pyramid_height, length;

	printf("지팡이의 높이를 입력하시오: ");
	scanf_s("%lf", &height);
	printf("지팡이 그림자의 길이를 입력하시오: ");
	scanf_s("%lf", &shadow);
	printf("피라미드까지의 거리를 입력하시오: ");
	scanf_s("%lf", &length);

	pyramid_height = height * length / shadow;
	printf("피라미드의 높이는 %lf입니다.\n\n", pyramid_height);

	return 0;
}
int pro10()
{
	int x, y;
	printf("x좌표와 y좌표를 차례대로 입력하시오: ");
	scanf_s("%d %d", &x, &y);
	
	if (x > 0)
		y > 0 ? printf("1사분면\n") : printf("4사분면\n");
	else
		y > 0 ? printf("2사분면\n") : printf("3사분면\n");

	return 0;
}
#define PI 3.141592
int pro11()
{
	double distance, angle, radius;

	printf("거리를 입력하시오: ");
	scanf_s("%lf", &distance);
	printf("각도를 입력하시오: ");
	scanf_s("%lf", &angle);

	radius = distance * 360.0 / (angle*PI*2);
	printf("지구의 반지름은 %lf\n\n", radius);

	return 0;
}
int pro12()
{
	unsigned int num = 0;	// 반드시 0으로 초기화시켜준다. 
	char ch1, ch2, ch3, ch4;

	printf("첫번째 문자를 입력하시오: ");
	scanf_s(" %c", &ch1);	// a를 입력받는다. 문자를 입력받을 때는 앞에 공백을 추가해준다.
	num = num | ch1;	// 

	printf("두번째 문자를 입력하시오: ");
	scanf_s(" %c", &ch2);
	num = num| ch2<<8;

	printf("세번째 문자를 입력하시오: ");
	scanf_s(" %c", &ch3);
	num = num | ch3<<16;

	printf("네번째 문자를 입력하시오: ");
	scanf_s(" %c", &ch4);
	num |= ch4<<24;

	printf("결과값: %x\n\n", num);

	return 0;
}