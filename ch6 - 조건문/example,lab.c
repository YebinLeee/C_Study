#include <stdio.h>
// p.239 ���� ��� ���α׷�
int pro1()
{
	int score;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &score);
	
	char result;
	if (score >= 90)
		result = 'A';
	else if (score >= 80)
		result = 'B';
	else if (score >= 70)
		result = 'C';
	else if (score >= 60)
		result = 'D';
	else
		result = 'F';
	printf("������ %c�Դϴ�.\n\n", result);
	
	return 0;
}
// p.240 ���� �з� ���α׷�
int pro2()
{
	char ch;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%c", &ch);

	if (ch >= 'A' && ch <= 'Z')
		printf("%c�� �빮���Դϴ�\n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c�� �ҹ����Դϴ�\n", ch);
	else if (ch >= 0 && ch <= 9)
		printf("%c�� �����Դϴ�\n", ch);
	else
		printf("%c�� ��Ÿ�����Դϴ�\n", ch);

	return 0;
}
// p.241 ���� ���α׷�
int pro3()
{
	int x, y, result=0;
	char op;
	printf("������ �Է��Ͻÿ�(��: 2 + 5): ");
	printf(">>");
	scanf_s("%d %c %d", &x, &op, 1, &y);

	if (op == '+' || op == '*' || op == '-' || op == '/' || op == '%')
	{
		switch (op) {
		case '*': result = x * y;
			break;
		case '+': result = x + y;
			break;
		case '-': result = x - y;
			break;
		case '/': result = x / y;
			break;
		case '%': result = x % y;
			break;
		default: break;
		}
		printf("%d %c %d = %d\n\n", x, op, y, result);
	}
	else
	{
		switch (op) {
		case '|': result = x | y;
			break;
		case '&': result = x & y;
			break;
		case '^': result = x ^ y;
			break;
		default:
			printf("�������� �ʴ� �������Դϴ�.\n");
			break;
		}
		printf("%#x %c %#x = %#x\n\n", x, op, y, result);
	}
	return 0;
}
// p/243 ���������� �� ���ϱ� ���α׷�
#include <math.h>
int pro4()
{
	double a, b, c;
	double dis;
	printf("������������ ��� a, b, c �� ���ʴ�� �Է��Ͻÿ�: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	dis = b * b - 4 * a * c;
	if (dis<0)
		printf("�Ǳ��� �������� �ʽ��ϴ�.\n\n");
	else
	{
		if (a == 0)
			printf("�������� ���� %lf�Դϴ�.\n\n", -c / b);
		else
		{
			printf("�������� ���� %lf�Դϴ�.\n", (-b + sqrt(dis)) / (2.0 * a));
			printf("�������� ���� %lf�Դϴ�.\n", (-b - sqrt(dis)) / (2.0 * a));
		}
	}
	return 0;
}
// p.253 goto �� �ۼ�
int pro5()
{
	int i = 1;
	int num;
	printf("���� �Է��Ͻÿ�: ");
	scanf_s("%d", &num);
loop:
	printf("%d * %i = %d \n", num, i, num * i);
	i++;
	if (i == 10) goto end;
	goto loop;

	end:
	return 0;
}