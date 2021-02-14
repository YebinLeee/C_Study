#include <stdio.h>
int main(void)
{
	/*
	p1();
	p2();
	p3();
	p4();
	p5();
	*/

	//p6();
	//p7();
	p8();

	return 0;
}
int p1(void)
{
	printf("학번: 20204059\n학과: 컴퓨터소프트웨어공학과\n이름: 이예빈\n\n");
}
int p2(void)
{
	int x = 10;
	float z = 15.7;
	printf("x = %d\n", x);
	printf("z = %f\n\n", z);
}
int p3(void)
{
	int age;
	printf("나이를 입력하시오: ");
	scanf_s("%d", &age);
	printf("당신은 %d 살입니다.\n\n", age);
}
int p4(void)
{
	char c;
	printf("문자를 입력하시오: ");
	scanf_s(" %c", &c);
	printf("ASCII 코드: %d\n\n", c);
}
int p5(void)
{
	int num1, num2;
	printf("정수를 입력하시오: ");
	scanf_s("%x", &num1);
	printf("정수를 입력하시오: ");
	scanf_s("%x", &num2);
	printf("덧셈 결과는 %d(10진수)입니다.\n", num1 + num2);
	printf("덧셈 결과는 %x(16진수)입니다.\n\n", num1 + num2);
}
int p6(void)
{
	float quiz1, quiz2, mid, fin;
	printf("==========QUIZZES===========\n");
	printf("퀴즈성적: ");
	scanf_s("%f", &quiz1);
	printf("퀴즈성적: ");
	scanf_s("%f", &quiz2);
	printf("==========MID TERM==========\n");
	printf("중간고사 성적: ");
	scanf_s("%f", &mid);
	printf("==========FINAL=============\n");
	printf("기말고사 성적: ");
	scanf_s("%f", &fin);
	printf("Quizz Total: %f\n", quiz1 + quiz2);
	printf("Mid: %f\n", mid);
	printf("Final: %f\n", fin);
	printf(".........................\n");
	printf("Total: %f\n\n", quiz1 + quiz2 + mid + fin);
	return 0;
}
int p7(void)
{
	int side1, side2, side3;
	printf("삼각형의 세 변을 입력하시오:\n");
	scanf_s("%d %d %d", &side1, &side2, &side3);
	
	if (side1 == side2) {
		if (side3 == side2)
			printf("정삼각형\n");
		else
			printf("이등변 삼각형\n");
	}
	else if (side1 == side3) {
		if (side2 == side3)
			printf("정삼각형\n");
		else
			printf("이등변 삼각형\n");
	}
	else if (side2 == side3) {
		if (side1 == side2)
			printf("정삼각형\n");
		else
			printf("이등변 삼각형\n");
	}
	else
		printf("일반 삼각형\n");
	printf("\n");
}
int p8(void)
{
	char color;
	printf("신호등의 색깔 입력 (R, G, Y): ");
	scanf_s(" %c", &color);
	
	if (color == 'r')
		printf("정지!\n");
	else if (color == 'g')
		printf("진행\n");
	else
		printf("주의\n");
}
