#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int p1()
{
	char ch;
	printf("문자를 입력하시오: ");
	scanf_s("%c", &ch);
	switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("모음입니다.\n\n");
			break;
		default:
			printf("자음입니다.\n\n");
	}
	return 0;
}
int p2()
{
	int num1, num2;
	
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num1);
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num2);
	
	if (num1 % num2 == 0)
		printf("%d는 %d의 약수입니다.\n\n", num2, num1);
	else
		printf("%d는 %d의 약수가 아닙니다.\n\n", num2, num1);

	return 0;
}
int p3()
{
	int x, y, z, min;
	printf("3개의 정수를 입력하시오: ");
	scanf_s("%d %d %d", &x, &y, &z);

	min = x < y ? x : y;
	min = min < z ? min : z;

	printf("제일 작은 정수는 %d입니다.\n\n", min);
	return 0;
}
int p4()
{
	int ans;
	srand(time(NULL));
	int com_ans = rand() % 3 + 1;

	printf("선택하시오(1: 가위, 2:바위, 3:보): ");
	scanf_s("%d", &ans);

	if (com_ans == 1)
	{
		if (ans == 1)
			printf("사용자와 비김\n");
		else if (ans == 2)
			printf("사용자가 이김\n");
		else
			printf("사용자가 짐\n");
	}
	else if (com_ans == 2)
	{
		if (ans == 2)
			printf("사용자와 비김\n");
		else if (ans == 3)
			printf("사용자가 이김\n");
		else
			printf("사용자가 짐\n");
	}
	else
	{
		if (ans == 3)
			printf("사용자와 비김\n");
		else if (ans == 1)
			printf("사용자가 이김\n");
		else
			printf("사용자가 짐\n");
	}
	printf("사용자의 선택: %d\n", ans);
	printf("컴퓨터의 선택: %d\n\n", com_ans);
	
	return 0;
}
int p5()
{
	int height, age;
	printf("키를 입력하시오(cm): ");
	scanf_s("%d", &height);
	printf("나이를 입력하시오: ");
	scanf_s("%d", &age);

	if (age >= 10 && height >= 140)
		printf("탑승 가능\n\n");
	else
		printf("탑승 불가\n\n");

	return 0;
}
int p6()
{
	int month;

	printf("월번호를 입력하시오: ");
	scanf_s("%d", &month);
	
	switch (month) {
	case 1: printf("Jan\n\n"); break;
	case 2: printf("Feb\n\n");break;
	case3:printf("Mar\n\n");break;
	default:break;
	}
	return 0;
}
int p7()
{
	int height, weight;
	double avg_weight;
	printf("체중과 키를 입력하시오: ");
	scanf_s("%d %d", &weight, &height);
	avg_weight = (height - 100.0) * 0.9;

	if (weight < avg_weight)
		printf("저체중입니다.\n\n");
	else if (weight >= avg_weight)
		printf("과체중입니다\n\n");
	else
		printf("표준입니다.\n\n");
	return 0;
}
int p8()
{
	int time, age, fee;

	printf("현재 시간과 나이를 입력하시오: ");
	scanf_s("%d %d", &time, &age);
	if (time <= 17)
		if (age >= 3 && age <= 12 && age >= 65)
			fee = 25000;
		else
			fee = 34000;
	else
		fee = 10000;
	printf("요금은 %d원입니다.\n\n", fee);

	return 0;
}
int p9()
{
	double x, result;
	
	printf("x의 값을 입력하시오: ");
	scanf_s("%lf", &x);

	if (x <= 0)
		result = x * x - 9 * x + 2;
	else
		result = 7 * x + 2;

	printf("f(x)의 값은 %lf\n\n", result);

	return 0;
}
int p10()
{
	int x, y, result;

	printf("좌표(x, y): ");
	scanf_s("%d %d", &x, &y);
	
	if (x > 0 && y > 0)
		printf("1사분면\n\n");
	else if (x > 0 && y < 0)
		printf("4사분면\n\n");
	else if (x < 0 && y>0)
		printf("2사분면\n\n");
	else
		printf("3사분면\n\n");

	return 0;
}
int p11() {

	char ch;
	printf("문자를 입력하시오: ");
	ch = getchar();

	switch (ch) {
	case 'r':
	case 'R':
		printf("Rectangle\n\n");
		break;
	case 't':
	case 'T':
		printf("Triangle\n\n");
	case 'c':
	case 'C':
		printf("Circle\n\n");
	default: printf("Unknown");break;
	}

	return 0;
}