#include <stdio.h>

// ���簢�� �����
int p11()
{
	int width, length;
	printf("���� ���θ� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &width, &length);

	for (int i = 0;i < width;i++)
	{
		for (int j = 0;j < length;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// ��� �����
int p12() {
	int n;
	printf("�� ��� ������ΰ�?");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// �� ��� �����
int p13() {
	int n;
	printf("��� ��? ");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j<n-i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// ������ ���� ��� �����
int p14()
{
	int n;
	printf("���� �Է�: ");
	scanf_s("%d", &n);
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j<n - i;j++)
			printf(" ");
		for (int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

//�Ƕ�̵� �����
int p15()
{
	int n;
	printf("�Ƕ�̵��� ��: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < n - i;j++)
			printf(" ");
		for (int j = 0;j < 2 * i - 1;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// ������ �����
int p16()
{
	int n;
	printf("������ ���κ��� ���: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < n - i;j++)
			printf(" ");
		for (int j = 0;j < 2 * i - 1;j++)
			printf("*");
		printf("\n");
	}
	for (int i = 1;i <n ;i++)
	{
		for (int j = 0;j<i;j++)
			printf(" ");
		for (int j = 0;j<2*(n-i)-1;j++)
			printf("*");
		printf("\n");
	}
	return 0;
	return 0;
}

//�𷡽ð� �����
int p17() {
	int n;
	printf("�𷡽ð� ��? ");
	scanf_s("%d", &n);
	
	for (int i=0;i<n;i++)
	return 0;
}