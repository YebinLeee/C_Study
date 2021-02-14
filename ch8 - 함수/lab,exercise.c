#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// p.333 온도 변환기
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
	
	printf("'c' : 섭씨온도에서 화씨온도로 변환\n");
	printf("'f' : 화씨온도에서 섭씨온도로 변환\n");
	printf("'q' : 종료버튼 \n");
	while (1) {
		printf("메뉴에서 선택하시오: ");
		scanf_s(" %c", &choice);
		if (choice == 'q') break;
		if (choice == 'c') {
			printf("온도를 입력하시오: ");
			scanf_s("%lf", &temp);
			printf("%lf도는 화씨온도로 %lf도입니다.\n", temp, c_to_f(temp));
		}
		else if (choice == 'f') {
			printf("온도를 입력하시오: ");
			scanf_s("%lf", &temp);
			printf("%lf도는 섭씨온도로 %lf도입니다. \n", temp, f_to_c(temp));
		}
		else
			continue;	
	}
	return 0;
}

// p.335 조합 계산하는 프로그램
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
	printf("조합에 사용될 값 n, r을 입력하시오: ");
	scanf_s("%d %d", &n, &r);

	printf("C(%d, %d)의 값은 %d입니다.\n",n,r, combination(n, r));

	return 0;
}

// p.336 소수찾는 프로그램
int is_prime(int n)
{
	for (int i = 2;i < n;i++) {
		if (n % i == 0) return 1;
	}
		return 0;
}
int p3() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	if (is_prime(n) == 1)
		printf("%d는 소수가 아닙니다.\n", n);
	else
		printf("%d는 소수입니다.\n", n);

	return 0;
}

// p.338 1과 입력한 숫자 n사이의 소수를 모두 구하는 프로그램
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
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	printf("1부터 %d 사이의 모든 소수는 다음과 같다. \n", n);
	for (int i = 2;i <= n;i++) {
		if (get_prime(i) == 1)
			printf("%d ", i);
	}
	printf("\n\n");
	return 0;
}

// p.344 동전 던지기 프로그램
int coin_toss(int n)
{
	return rand() % 2;

}
int p5() {
	int n;
	int heads = 0;
	int tails = 0;
	srand((unsigned)time(NULL));
	printf("동전 몇번 던질겁니까? ");
	scanf_s("%d", &n);
	
	for (int i = 0;i < n;i++)
		if (coin_toss(i) == 1)
			heads++;
		else
			tails++;
	printf("동전은 %d번 던진 후 앞면은 %d번 뒷면은 %d번 나옴.\n\n", n, heads, tails);

	return 0;
}