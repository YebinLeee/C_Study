#include <stdio.h>
int pro1()
{
	int n;
	printf("ī������ �ʱⰪ�� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	//while loop ���
	/*
	while (n > 0) {
		printf("%d ", n);
		n--;
	}
	*/
	//for �� ���
	for (int i = n;i > 0;i--)
		printf("%d ", i);
	printf("\n");
	return 0;
}
int pro2()
{
	int sum = 0;
	for (int i = 0;i <= 100;i++)
		if (i % 3 == 0)
			sum += i;
	printf("1���� 100 ������ ��� 3�� ����� ���� %d�Դϴ�.\n\n", sum);
	return 0;
}
int pro3()
{
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	printf("���: ");
	for (int i = 1;i <= n;i++)
		if (n % i == 0)
			printf("%d ", i);
	printf("\n");
	return 0;
}
int pro4()
{
	int n;
	printf("���� ����� �Է�: ");
	scanf_s("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n - i;j++)
			printf(" ");
		for (int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
	printf("\n");
	return 0;
}
int pro5()
{
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++)
			printf("%d ", j);
		printf("\n");
	}
	return 0;
}
int pro6()
{
	char ans;
	int x, y, result;
	printf("********************\n");
	printf("A---- Add\n");
	printf("S---- Subtract\n");
	printf("M---- Multiply\n");
	printf("Q---- Quit\n");
	printf("********************\n");
	do {
		printf("������ �����Ͻÿ�: ");
		scanf_s(" %c", &ans);
		if((ans == 'A') || (ans == 'S') || (ans == 'M')) {
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ�: ");
			scanf_s("%d %d", &x, &y);
			switch (ans) {
			case 'A': result = x + y;break;
			case 'S': result = x - y;break;
			case 'M':result = x * y;break;
			}
			printf("������� %d\n\n", result);
		}
		else
			continue;
	} while (ans != 'Q');
	return 0;
}
int pro7()
{
	int i, j;
	for (i = 2;i <= 100;i++) {
		for (j = 2;j < i;j++)
			if (i % j == 0) break;
		if (i == j)
			printf("%d ", i);
	}
	printf("\n\n");

	return 0;
}
int pro8()
{
	int n;
	do {
		printf("������ ����(����: -1): ");
		scanf_s("%d", &n);
		for (int i = 0;i < n;i++)
			printf("*");
		printf("\n");
	} while (n != -1);

	return 0;
}
int pro9()
{
	int n = 1;
	int sum = 0;
	
	while (1) {
	sum += n;
		if (sum > 10000)
			break;	// break���� �����ִ� �ݺ����� ���������� �ϴ� �����̴�. ����, while���� ���� �������´�.
		n++;	// break���� ��������� �������� n�� �������� �ʴ´�.
	}
	sum -= n;	// sum�� 10000�� �� ����, if�� �� break������ �����������Ƿ�, ���������� ������ n��ŭ ���� ���ش�.
	n--;	// ������ n�� ���� ���ش�.
	printf("1���� %d������ ���� %d�Դϴ�.\n\n", n, sum);
	
	return 0;
}
int pro10()
{
	double r, n, result=1;
	printf("�Ǽ��� ���� �Է��Ͻÿ�: ");
	scanf_s("%lf", &r);
	printf("�ŵ�����Ƚ���� �Է��Ͻÿ�: ");
	scanf_s("%lf", &n);
	for (int i = 0;i < n;i++)
		result *= r;
	printf("%lf�� %lf �ŵ����� ������� %lf�Դϴ�.\n\n", r, n, result);
	return 0;
}
int pro11()
{
	int n, result=0;
	printf("n�� ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	for (int i = 0;i <= n;i++)
		result += i * i;
	printf("��갪�� %d�Դϴ�.\n\n", result);
	return 0;
}
int pro12()
{
	int n;
	int a = 0, b = 1, c;
	printf("���° �ױ��� ���ұ��? ");
	scanf_s("%d", &n);
	printf("0, ");
	for (int i = 0;i <= n;i++) {
		printf("%d, ", a);
		c = a + b;
		a = b;
		b = c;
	}
	printf("\n\n");
	return 0;
}
int pro13()
{
	int n, r, result=1;
	printf("n�� ��: ");
	scanf_s("%d", &n);
	printf("r�� ��: ");
	scanf_s("%d", &r);

	for (int i = n;i >= n - r + 1;i--)
		result *= i;
	printf("������ ���� %d�Դϴ�.\n\n", result);

	return 0;
}
int pro14()
{
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	/*
	while(1){
		if (n < 10)
		{
			printf("%d", n);
			break;
		}
		printf("%d", n % 10);
		n /= 10;
	}
	*/
	do {
		printf("%d ", n % 10);
		n /= 10;
	} while (n >= 10);
	printf("%d\n", n);
	printf("\n\n");
	return 0;
}