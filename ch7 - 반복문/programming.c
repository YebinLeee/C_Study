#include <stdio.h>
int pro1()
{
	int n;
	printf("카운터의 초기값을 입력하시오: ");
	scanf_s("%d", &n);
	//while loop 사용
	/*
	while (n > 0) {
		printf("%d ", n);
		n--;
	}
	*/
	//for 문 사용
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
	printf("1부터 100 사이의 모든 3의 배수의 합은 %d입니다.\n\n", sum);
	return 0;
}
int pro3()
{
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	printf("약수: ");
	for (int i = 1;i <= n;i++)
		if (n % i == 0)
			printf("%d ", i);
	printf("\n");
	return 0;
}
int pro4()
{
	int n;
	printf("층의 계수를 입력: ");
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
	printf("정수를 입력하시오: ");
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
		printf("연산을 선택하시오: ");
		scanf_s(" %c", &ans);
		if((ans == 'A') || (ans == 'S') || (ans == 'M')) {
			printf("두 수를 공백으로 분리하여 입력하시오: ");
			scanf_s("%d %d", &x, &y);
			switch (ans) {
			case 'A': result = x + y;break;
			case 'S': result = x - y;break;
			case 'M':result = x * y;break;
			}
			printf("결과값은 %d\n\n", result);
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
		printf("막대의 높이(종료: -1): ");
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
			break;	// break문은 속해있는 반복문을 빠져나오게 하는 문장이다. 따라서, while문을 고대로 빠져나온다.
		n++;	// break문이 실행됐을때 마지막에 n은 더해지지 않는다.
	}
	sum -= n;	// sum이 10000이 된 직후, if문 속 break문으로 빠져나왔으므로, 마지막으로 더해진 n만큼 값을 빼준다.
	n--;	// 마지막 n값 또한 빼준다.
	printf("1부터 %d까지의 합은 %d입니다.\n\n", n, sum);
	
	return 0;
}
int pro10()
{
	double r, n, result=1;
	printf("실수의 값을 입력하시오: ");
	scanf_s("%lf", &r);
	printf("거듭제곱횟수를 입력하시오: ");
	scanf_s("%lf", &n);
	for (int i = 0;i < n;i++)
		result *= r;
	printf("%lf의 %lf 거듭제곱 결과값은 %lf입니다.\n\n", r, n, result);
	return 0;
}
int pro11()
{
	int n, result=0;
	printf("n의 값을 입력하시오: ");
	scanf_s("%d", &n);
	for (int i = 0;i <= n;i++)
		result += i * i;
	printf("계산값은 %d입니다.\n\n", result);
	return 0;
}
int pro12()
{
	int n;
	int a = 0, b = 1, c;
	printf("몇번째 항까지 구할까요? ");
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
	printf("n의 값: ");
	scanf_s("%d", &n);
	printf("r의 값: ");
	scanf_s("%d", &r);

	for (int i = n;i >= n - r + 1;i--)
		result *= i;
	printf("순열의 값은 %d입니다.\n\n", result);

	return 0;
}
int pro14()
{
	int n;
	printf("정수를 입력하시오: ");
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