#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int p1()
{
	char ch;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%c", &ch);
	switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("�����Դϴ�.\n\n");
			break;
		default:
			printf("�����Դϴ�.\n\n");
	}
	return 0;
}
int p2()
{
	int num1, num2;
	
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num1);
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num2);
	
	if (num1 % num2 == 0)
		printf("%d�� %d�� ����Դϴ�.\n\n", num2, num1);
	else
		printf("%d�� %d�� ����� �ƴմϴ�.\n\n", num2, num1);

	return 0;
}
int p3()
{
	int x, y, z, min;
	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d %d", &x, &y, &z);

	min = x < y ? x : y;
	min = min < z ? min : z;

	printf("���� ���� ������ %d�Դϴ�.\n\n", min);
	return 0;
}
int p4()
{
	int ans;
	srand(time(NULL));
	int com_ans = rand() % 3 + 1;

	printf("�����Ͻÿ�(1: ����, 2:����, 3:��): ");
	scanf_s("%d", &ans);

	if (com_ans == 1)
	{
		if (ans == 1)
			printf("����ڿ� ���\n");
		else if (ans == 2)
			printf("����ڰ� �̱�\n");
		else
			printf("����ڰ� ��\n");
	}
	else if (com_ans == 2)
	{
		if (ans == 2)
			printf("����ڿ� ���\n");
		else if (ans == 3)
			printf("����ڰ� �̱�\n");
		else
			printf("����ڰ� ��\n");
	}
	else
	{
		if (ans == 3)
			printf("����ڿ� ���\n");
		else if (ans == 1)
			printf("����ڰ� �̱�\n");
		else
			printf("����ڰ� ��\n");
	}
	printf("������� ����: %d\n", ans);
	printf("��ǻ���� ����: %d\n\n", com_ans);
	
	return 0;
}
int p5()
{
	int height, age;
	printf("Ű�� �Է��Ͻÿ�(cm): ");
	scanf_s("%d", &height);
	printf("���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &age);

	if (age >= 10 && height >= 140)
		printf("ž�� ����\n\n");
	else
		printf("ž�� �Ұ�\n\n");

	return 0;
}
int p6()
{
	int month;

	printf("����ȣ�� �Է��Ͻÿ�: ");
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
	printf("ü�߰� Ű�� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &weight, &height);
	avg_weight = (height - 100.0) * 0.9;

	if (weight < avg_weight)
		printf("��ü���Դϴ�.\n\n");
	else if (weight >= avg_weight)
		printf("��ü���Դϴ�\n\n");
	else
		printf("ǥ���Դϴ�.\n\n");
	return 0;
}
int p8()
{
	int time, age, fee;

	printf("���� �ð��� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &time, &age);
	if (time <= 17)
		if (age >= 3 && age <= 12 && age >= 65)
			fee = 25000;
		else
			fee = 34000;
	else
		fee = 10000;
	printf("����� %d���Դϴ�.\n\n", fee);

	return 0;
}
int p9()
{
	double x, result;
	
	printf("x�� ���� �Է��Ͻÿ�: ");
	scanf_s("%lf", &x);

	if (x <= 0)
		result = x * x - 9 * x + 2;
	else
		result = 7 * x + 2;

	printf("f(x)�� ���� %lf\n\n", result);

	return 0;
}
int p10()
{
	int x, y, result;

	printf("��ǥ(x, y): ");
	scanf_s("%d %d", &x, &y);
	
	if (x > 0 && y > 0)
		printf("1��и�\n\n");
	else if (x > 0 && y < 0)
		printf("4��и�\n\n");
	else if (x < 0 && y>0)
		printf("2��и�\n\n");
	else
		printf("3��и�\n\n");

	return 0;
}
int p11() {

	char ch;
	printf("���ڸ� �Է��Ͻÿ�: ");
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