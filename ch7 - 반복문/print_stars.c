#include <stdio.h>

// 직사각형 만들기
int p11()
{
	int width, length;
	printf("가로 세로를 입력하시오: ");
	scanf_s("%d %d", &width, &length);

	for (int i = 0;i < width;i++)
	{
		for (int j = 0;j < length;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// 계단 만들기
int p12() {
	int n;
	printf("몇 계단 만들것인가?");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// 역 계단 만들기
int p13() {
	int n;
	printf("계단 수? ");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j<n-i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

// 오른쪽 정렬 계단 만들기
int p14()
{
	int n;
	printf("숫자 입력: ");
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

//피라미드 만들기
int p15()
{
	int n;
	printf("피라미드의 층: ");
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

// 마름모 만들기
int p16()
{
	int n;
	printf("마름모 윗부분의 계단: ");
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

//모래시계 만들기
int p17() {
	int n;
	printf("모래시게 층? ");
	scanf_s("%d", &n);
	
	for (int i=0;i<n;i++)
	return 0;
}