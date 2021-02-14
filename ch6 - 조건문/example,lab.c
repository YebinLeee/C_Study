#include <stdio.h>
// p.239 성적 계산 프로그램
int pro1()
{
	int score;
	printf("성적을 입력하시오: ");
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
	printf("학점은 %c입니다.\n\n", result);
	
	return 0;
}
// p.240 문자 분류 프로그램
int pro2()
{
	char ch;
	printf("문자를 입력하시오: ");
	scanf_s("%c", &ch);

	if (ch >= 'A' && ch <= 'Z')
		printf("%c는 대문자입니다\n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c는 소문자입니다\n", ch);
	else if (ch >= 0 && ch <= 9)
		printf("%c는 숫자입니다\n", ch);
	else
		printf("%c는 기타문자입니다\n", ch);

	return 0;
}
// p.241 계산기 프로그램
int pro3()
{
	int x, y, result=0;
	char op;
	printf("수식을 입력하시오(예: 2 + 5): ");
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
			printf("지원되지 않는 연산자입니다.\n");
			break;
		}
		printf("%#x %c %#x = %#x\n\n", x, op, y, result);
	}
	return 0;
}
// p/243 이차방정식 근 구하기 프로그램
#include <math.h>
int pro4()
{
	double a, b, c;
	double dis;
	printf("이차방정식의 계수 a, b, c 를 차례대로 입력하시오: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	dis = b * b - 4 * a * c;
	if (dis<0)
		printf("실근은 존재하지 않습니다.\n\n");
	else
	{
		if (a == 0)
			printf("방정식의 근은 %lf입니다.\n\n", -c / b);
		else
		{
			printf("방정식의 근은 %lf입니다.\n", (-b + sqrt(dis)) / (2.0 * a));
			printf("방정식의 근은 %lf입니다.\n", (-b - sqrt(dis)) / (2.0 * a));
		}
	}
	return 0;
}
// p.253 goto 문 작성
int pro5()
{
	int i = 1;
	int num;
	printf("단을 입력하시오: ");
	scanf_s("%d", &num);
loop:
	printf("%d * %i = %d \n", num, i, num * i);
	i++;
	if (i == 10) goto end;
	goto loop;

	end:
	return 0;
}