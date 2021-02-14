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
	printf("두 수를 입력하시오: ");
	scanf_s("%d %d", &x, &y);
	
	for (int i = x;i <= y;i++)
		if (i % 3 == 0)sum += i;
	printf("%d부터 %d 사이의 모든 3의 배수의 합은 %d입니다.\n",x,y, sum);
}
int p2() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	
	printf("약수 : ");
	for (int i = 1;i <= n;i++)
		if (n % i == 0) printf("%d ", i);
}
int p3() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n - i;j++) printf(" ");
		for (int k = 1;k <= i;k++)printf("*");
		printf("\n");
	}
}
int p4() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++)printf("%d ", j);
		printf("\n");
	}
}
int p5() {
	int x, y, i, j;
	printf("두 정수를 입력하시오: ");
	scanf_s("%d %d", &x, &y);

	printf("%d부터 %d까지 존재하는 소수는 : \n", x, y);
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
	printf("1부터 %d까지의 합이 %d입니다\n", i, sum);
}
int p7() {
	double x, sum = 1.0;
	int n;
	printf("실수 값 : ");
	scanf_s("%lf", &x);
	printf("거듭제곱횟수 : ");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++)
		sum *= x;
	printf("결과값은 %f\n", sum);
}
int p8() {
	int n, sum = 0;
	printf("n의 값을 입력 : ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++)
		sum += i * i;
	printf("계산값은 %d\n", sum);
}

int p9() {
	int n, r, p = 1;
	printf("n의 값: ");
	scanf_s("%d", &n);
	printf("r의 값 : ");
	scanf_s("%d", &r);

	for (int i = n;i > n - r;i--)
		p *= i;
	printf("순열의 값은 %d\n", p);
}
int p10() {
	int n;
	printf("정수 입력 : ");
	scanf_s("%d", &n);

	do {
		printf("%d", n % 10);
		n /= 10;
	} while (n != 0);
}