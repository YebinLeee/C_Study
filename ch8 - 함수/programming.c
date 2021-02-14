#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double square(double n) {
	return n * n;
}
int pro1()
{
	double n;
	printf("정수를 입력하시오: ");
	scanf_s("%lf", &n);
	printf("주어진 정수 %lf의 제곱은 %lf입니다.\n\n", n, square(n));
	return 0;
}

int check_alpha(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return 1;
	else
		return 0;
}
int pro2()
{
	char ch;
	printf("문자를 입력하시오: ");
	scanf_s(" %c", &ch);
	if (check_alpha(ch) == 1)
		printf("%c는 알파벳 문자입니다.\n\n", ch);
	else
		printf("%c는 알파벳 문자가 아닙니다.", ch);
	return 0;
}

#define PI 3.141592
double cal_area(double radius) {
	return(PI * radius * radius);
}
int pro3()
{
	double radius;
	printf("반지름을 입력: ");
	scanf_s("%lf", &radius);
	printf("원의 면적은 %lf입니다.\n\n", cal_area(radius));

	return 0;
}

int is_leap(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400) == 0)
		return 366;
	else
		return 365;
}
int pro4()
{
	int year;
	printf("연도를 입력하시오: ");
	scanf_s("%d", &year);
	printf("%d년은 %d일입니다.\n\n", year, is_leap(year));
	return 0;
}

int round1(double f)
{
	int result = (int)(f + 0.5);
	return result;
}
int pro5()
{
	double n;
	printf("실수를 입력하시오: ");
	scanf_s("%lf", &n);
	printf("%lf을 반올림한 값은 %d\n\n", n, round1(n));

	return 0;
}

int even(int n) {
	if (n % 2 == 0)
		return 1;
	else return 0;
}
int abs(int n) {
	if (n < 0)
		return -n;
	else
		return n;
}
int sign(int n) {
	if (n < 0)
		return 0;
	else
		return 1;
}
int pro6()
{
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	printf("짝 or 홀: ");
	if (even(n) == 1)
		printf("짝수\n");
	else
		printf("홀수\n");
	printf("절댓값 : %d\n", abs(n));
	printf("양수 or 음수: ");
	if (sign(n) == 1)
		printf("양수\n\n");
	else
		printf("음수\n\n");
	
	return 0;
}

int get_tax(int income) {
	int result =0;
	if (income >= 1000)
		result += 80 + (income - 1000) * 0.1;
	else
		result += 80;
	return result;

}
int pro7()
{
	int income;
	printf("소득을 입력하시오(만원): ");
	scanf_s("%d", &income);
	printf("소득세는 %d입니다.\n\n", get_tax(income));
	return 0;
}

double sin_degree(double degree) {
	double deg = (PI * degree) / 180.0;
		return sin(deg);
}
int pro8()
{
	double degree;
	for (int i=0;i<5;i++) {
		scanf_s("%lf", &degree);
		printf("sin(%lf)의 값은 %lf\n", degree, sin_degree(degree));
	}
	return 0;
}

int b_rand1() {
	printf("%d ", rand() % 2);
}
int pro9()
{
	srand((unsigned)time(NULL));
	for (int i = 0;i < 5;i++)
		b_rand1();

	return 0;
}

int b_rand() {
	return rand() % 2;
}
int pro10()
{
	int ans;
	char ans1;
	
	while (1) {
		int com_ans = b_rand();
		printf("앞면(1) 또는 뒷면(0): ");
		scanf_s("%d", &ans);
		if (com_ans == ans)
			printf("맞았습니다\n");
		else
			printf("틀렸습니다\n");
		printf("컴퓨터의 선택 확인: %d\n", com_ans);
		printf("계속 하시겠습니까? (y 또는 n): ");
		scanf_s(" %c", &ans1);
		if (ans1 == 'n') break;
	}
	return 0;
}

double f_rand()
{
	return rand()/(double)RAND_MAX;
}
int pro11()
{
	for (int i = 0;i < 5;i++)
		f_rand();
	return 0;
}

void printf_value(int n) {
	for (int i = 0;i < n;i++)
		printf("*");
	printf("\n");
}
int pro12()
{
	int ans;
	while (1) {
		printf("값을 입력하시오(종료는 음수): ");
		scanf_s("%d", &ans);
		if (ans < 0)
			break;
		printf_value(ans);
	}
	return 0;
}


int is_multiple(int n, int m) {
	if (n % m == 0) return 1;
	else
		return 0;
}
int pro13()
{
	int x, y;
	printf("첫번째 정수를 입력하시오: ");
	scanf_s("%d", &x);
	printf("두번째 정수를 입력하시오: ");
	scanf_s("%d", &y);
	if (is_multiple(x,y) == 1)
		printf("%d는 %d의 배수입니다.\n\n", x, y);
	else
		printf("%d는 %d의 배수가 아닙니다.\n\n", x, y);

	return 0;
}


double get_distance(double x1, double y1, double x2, double y2) {
	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return d;
}
int pro14()
{
	double x1, x2, y1, y2;

	printf("첫번째 점의 좌표를 입력하시오(x,y): ");
	scanf_s("%lf %lf", &x1, &y1);
	printf("두번째 점의 좌표를 입력하시오(x,y): ");
	scanf_s("%lf %lf", &x2, &y2);
	printf("두 점 사이의 거리는 %lf\n\n", get_distance(x1, y1, x2, y2));

	return 0;
}

int pro15()
{
	is_prime();
	return 0;
}

int get_factorial(int n) {
	int result = 1;
	for (int i = 1;i <= n;i++)
		result *= i;
	return result;
}
double get_oiler(int n) {
	double sum=0;
	for (int i = 1;i <= n;i++)
		sum += (1.0 / get_factorial(i));
	return sum;

}
int pro16()
{
	int n;
	printf("어디까지 계산할까요? ");
	scanf_s("%d", &n);
	printf("오일러의 수는 %lf입니다,\n\n", 1.0 + get_oiler(n));
	return 0;
}

int get_sum(int x, int y) {
	return x + y;
}
int get_diff(int x, int y) {
	return x - y;
}
int get_mult(int x, int y) {
	return x * y;
}
int get_div(int x, int y) {
	return x / y;
}
int get_rem(int x, int y) {
	return x % y;
}
int pro17()
{
	int ans, result;
	int x, y;
	char ch;

	printf("=================\n");
	printf("MENU\n");
	printf("=================\n");
	printf("1.덧셈\n2.뺄셈\n3.곱셈\n4.나눗셈\n5.나머지\n");
	
	while (1) {
		printf("원하는 메뉴를 선택하시오(1~5): ");
		scanf_s("%d", &ans);
		printf("정수 두 개를 입력하시오: ");
		scanf_s("%d %d", &x, &y);

		switch (ans) {
		case 1:result = get_sum(x, y);break;
		case 2:result = get_diff(x, y);break;
		case 3:result = get_mult(x, y);break;
		case 4:result = get_div(x, y);break;
		case 5:result = get_rem(x, y);break;
		default:break;
		}
		printf("연산결과: %d\n", result);
		printf("계속하려면 y를 누르시오: ");
		scanf_s(" %c", &ch);
		if (ch != 'y') break;
	}

		return 0;
}

