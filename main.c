#include <stdio.h>
int main(void) {
	/*p1(); // #Programmig #2
	p2(); //#3
	p3(); //#4
	p4(); //#5
	p5(); //#7
	p6(); //#9
	p7(); //#10
	p8(); //#11
	*/
	p9(); //#13
	p10(); //#14

	return 0;
}
int p1() {
	int x, y, sum = 0;
	printf("�� ���� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &x, &y);
	
	for (int i = x;i <= y;i++)
		if (i % 3 == 0)sum += i;
	printf("%d���� %d ������ ��� 3�� ����� ���� %d�Դϴ�.\n",x,y, sum);
}
int p2() {
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	
	printf("��� : ");
	for (int i = 1;i <= n;i++)
		if (n % i == 0) printf("%d ", i);
}
int p3() {
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n - i;j++) printf(" ");
		for (int k = 1;k <= i;k++)printf("*");
		printf("\n");
	}
}
int p4() {
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++)printf("%d ", j);
		printf("\n");
	}
}
int p5() {
	int x, y, i, j;
	printf("�� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d", &x, &y);

	printf("%d���� %d���� �����ϴ� �Ҽ��� : \n", x, y);
	for (i = x;i <= y;i++) {
		for (j = 2;j < i;j++)
			if (i % j == 0) break;
		if (i == j)printf("%d ", i);
	} 
	printf("\n");
}
int p6() {
	int sum = 0, i = 0;
	while (sum <= 10000) {
		i++;
		sum += i;
	}
	sum -= i;
	i--;
	printf("1���� %d������ ���� %d�Դϴ�\n", i, sum);
}
int p7() {
	double x, sum = 1.0;
	int n;
	printf("�Ǽ� �� : ");
	scanf_s("%lf", &x);
	printf("�ŵ�����Ƚ�� : ");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
		sum *= x;
	printf("������� %f\n", sum);
}
int p8() {
	int n, sum = 0;
	printf("n�� ���� �Է� : ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++)
		sum += i * i;
	printf("��갪�� %d\n", sum);
}

int p9() {
	int n, r, p = 1;
	printf("n�� ��: ");
	scanf_s("%d", &n);
	printf("r�� �� : ");
	scanf_s("%d", &r);

	for (int i = n;i > n - r;i--)
		p *= i;
	printf("������ ���� %d\n", p);
}
int p10() {
	int n;
	printf("���� �Է� : ");
	scanf_s("%d", &n);

	do {
		printf("%d", n % 10);
		n /= 10;
	} while (n != 0);
}