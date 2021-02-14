#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// p.333 �µ� ��ȯ��
double c_to_f(double c_temp) {
	return 9.0 / 5.0 * c_temp + 32;
}
double f_to_c(double f_temp) {
	return (f_temp - 32.0) * 5.0 / 9.0;
}
int p1()
{
	char choice;
	double temp;
	
	printf("'c' : �����µ����� ȭ���µ��� ��ȯ\n");
	printf("'f' : ȭ���µ����� �����µ��� ��ȯ\n");
	printf("'q' : �����ư \n");
	while (1) {
		printf("�޴����� �����Ͻÿ�: ");
		scanf_s(" %c", &choice);
		if (choice == 'q') break;
		if (choice == 'c') {
			printf("�µ��� �Է��Ͻÿ�: ");
			scanf_s("%lf", &temp);
			printf("%lf���� ȭ���µ��� %lf���Դϴ�.\n", temp, c_to_f(temp));
		}
		else if (choice == 'f') {
			printf("�µ��� �Է��Ͻÿ�: ");
			scanf_s("%lf", &temp);
			printf("%lf���� �����µ��� %lf���Դϴ�. \n", temp, f_to_c(temp));
		}
		else
			continue;	
	}
	return 0;
}

// p.335 ���� ����ϴ� ���α׷�
int factorial(int n)
{
	int result=1;
	for (int i = 1;i < n;i++)
		result *= i;
	return result;
}
int combination(int n, int r) {
	return factorial(n) / (factorial(n - r) * factorial(r));
}
int p2(void)
{
	int n, r;
	printf("���տ� ���� �� n, r�� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &n, &r);

	printf("C(%d, %d)�� ���� %d�Դϴ�.\n",n,r, combination(n, r));

	return 0;
}

// p.336 �Ҽ�ã�� ���α׷�
int is_prime(int n)
{
	for (int i = 2;i < n;i++) {
		if (n % i == 0) return 1;
	}
		return 0;
}
int p3() {
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	if (is_prime(n) == 1)
		printf("%d�� �Ҽ��� �ƴմϴ�.\n", n);
	else
		printf("%d�� �Ҽ��Դϴ�.\n", n);

	return 0;
}

// p.338 1�� �Է��� ���� n������ �Ҽ��� ��� ���ϴ� ���α׷�
int get_prime(int n) {
	int i;
	for (i = 2;i < n;i++)
		if (n % i == 0)
			break;
	if (i == n)
		return 1;
	else return 0;
}
int p4(void)
{
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	printf("1���� %d ������ ��� �Ҽ��� ������ ����. \n", n);
	for (int i = 2;i <= n;i++) {
		if (get_prime(i) == 1)
			printf("%d ", i);
	}
	printf("\n\n");
	return 0;
}

// p.344 ���� ������ ���α׷�
int coin_toss(int n)
{
	return rand() % 2;

}
int p5() {
	int n;
	int heads = 0;
	int tails = 0;
	srand((unsigned)time(NULL));
	printf("���� ��� �����̴ϱ�? ");
	scanf_s("%d", &n);
	
	for (int i = 0;i < n;i++)
		if (coin_toss(i) == 1)
			heads++;
		else
			tails++;
	printf("������ %d�� ���� �� �ո��� %d�� �޸��� %d�� ����.\n\n", n, heads, tails);

	return 0;
}