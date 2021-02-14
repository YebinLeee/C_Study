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
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%lf", &n);
	printf("�־��� ���� %lf�� ������ %lf�Դϴ�.\n\n", n, square(n));
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
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &ch);
	if (check_alpha(ch) == 1)
		printf("%c�� ���ĺ� �����Դϴ�.\n\n", ch);
	else
		printf("%c�� ���ĺ� ���ڰ� �ƴմϴ�.", ch);
	return 0;
}

#define PI 3.141592
double cal_area(double radius) {
	return(PI * radius * radius);
}
int pro3()
{
	double radius;
	printf("�������� �Է�: ");
	scanf_s("%lf", &radius);
	printf("���� ������ %lf�Դϴ�.\n\n", cal_area(radius));

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
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &year);
	printf("%d���� %d���Դϴ�.\n\n", year, is_leap(year));
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
	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf_s("%lf", &n);
	printf("%lf�� �ݿø��� ���� %d\n\n", n, round1(n));

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
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	printf("¦ or Ȧ: ");
	if (even(n) == 1)
		printf("¦��\n");
	else
		printf("Ȧ��\n");
	printf("���� : %d\n", abs(n));
	printf("��� or ����: ");
	if (sign(n) == 1)
		printf("���\n\n");
	else
		printf("����\n\n");
	
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
	printf("�ҵ��� �Է��Ͻÿ�(����): ");
	scanf_s("%d", &income);
	printf("�ҵ漼�� %d�Դϴ�.\n\n", get_tax(income));
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
		printf("sin(%lf)�� ���� %lf\n", degree, sin_degree(degree));
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
		printf("�ո�(1) �Ǵ� �޸�(0): ");
		scanf_s("%d", &ans);
		if (com_ans == ans)
			printf("�¾ҽ��ϴ�\n");
		else
			printf("Ʋ�Ƚ��ϴ�\n");
		printf("��ǻ���� ���� Ȯ��: %d\n", com_ans);
		printf("��� �Ͻðڽ��ϱ�? (y �Ǵ� n): ");
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
		printf("���� �Է��Ͻÿ�(����� ����): ");
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
	printf("ù��° ������ �Է��Ͻÿ�: ");
	scanf_s("%d", &x);
	printf("�ι�° ������ �Է��Ͻÿ�: ");
	scanf_s("%d", &y);
	if (is_multiple(x,y) == 1)
		printf("%d�� %d�� ����Դϴ�.\n\n", x, y);
	else
		printf("%d�� %d�� ����� �ƴմϴ�.\n\n", x, y);

	return 0;
}


double get_distance(double x1, double y1, double x2, double y2) {
	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return d;
}
int pro14()
{
	double x1, x2, y1, y2;

	printf("ù��° ���� ��ǥ�� �Է��Ͻÿ�(x,y): ");
	scanf_s("%lf %lf", &x1, &y1);
	printf("�ι�° ���� ��ǥ�� �Է��Ͻÿ�(x,y): ");
	scanf_s("%lf %lf", &x2, &y2);
	printf("�� �� ������ �Ÿ��� %lf\n\n", get_distance(x1, y1, x2, y2));

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
	printf("������ ����ұ��? ");
	scanf_s("%d", &n);
	printf("���Ϸ��� ���� %lf�Դϴ�,\n\n", 1.0 + get_oiler(n));
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
	printf("1.����\n2.����\n3.����\n4.������\n5.������\n");
	
	while (1) {
		printf("���ϴ� �޴��� �����Ͻÿ�(1~5): ");
		scanf_s("%d", &ans);
		printf("���� �� ���� �Է��Ͻÿ�: ");
		scanf_s("%d %d", &x, &y);

		switch (ans) {
		case 1:result = get_sum(x, y);break;
		case 2:result = get_diff(x, y);break;
		case 3:result = get_mult(x, y);break;
		case 4:result = get_div(x, y);break;
		case 5:result = get_rem(x, y);break;
		default:break;
		}
		printf("������: %d\n", result);
		printf("����Ϸ��� y�� �����ÿ�: ");
		scanf_s(" %c", &ch);
		if (ch != 'y') break;
	}

		return 0;
}

