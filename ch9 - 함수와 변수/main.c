#include <stdio.h>
int main(void) {
	//p1(); // programming #1-3, 5-10
	//p2();
	//p3();
	//p4();
	//p5();
	//p6();
	//p7();
	//p8(); 
	p9();


	return 0;
}

int add(int x, int y) {	return x + y;}
int sub(int x, int y) {	return x - y;}
int mul(int x, int y) { return x * y; }
int div_(int x, int y) { return x / y; }
int p1() {
	int x, y;
	char c;

	while (1) {
		static int add_count = 0, sub_count = 0, mul_count = 0, div_count = 0;
		printf("연산을 입력: ");
		scanf_s("%d%c%d", &x, &c, 1, &y);
		switch (c) {
		case '+':
			printf("덧셈은 총 %d번 실행되었습니다.\n연산 결과:%d\n", ++add_count, add(x, y));
			break;
		case '-':
			printf("뺄셈은은 총 %d번 실행되었습니다.\n연산 결과:%d\n", ++sub_count, sub(x, y));
			break;
		case '*':
			printf("곱셈은 총 %d번 실행되었습니다.\n연산 결과:%d\n", ++mul_count, mul(x, y));
			break;
		case '/':
			printf("나눗은 총 %d번 실행되었습니다.\n연산 결과:%d\n", ++div_count, div_(x, y));
			break;
		default:return 0;
		}
	}
}

#include <stdlib.h>
#include <math.h>
int get_dice_face() {
	return rand() % 6 + 1;
}
int p2() {
	srand((unsigned)time(NULL));
	static int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
	for (int i = 0;i <= 100;i++) {
		int result = get_dice_face();
		switch (result) {
		case 1:cnt1++;break;
		case 2:cnt2++;break;
		case 3:cnt3++;break;
		case 4:cnt4++;break;
		case 5:cnt5++;break;
		case 6:cnt6++;break;
		default:break;
		}
	}
	printf("1->%d\n", cnt1);
	printf("2->%d\n", cnt2);
	printf("3->%d\n", cnt3);
	printf("4->%d\n", cnt4);
	printf("5->%d\n", cnt5);
	printf("6->%d\n", cnt6);
}

int check() {
	int pw = 1234;
	int ans;
	printf("비밀번호: ");
	scanf_s("%d", &ans);
	if (ans == pw)return 1;
}
int p3() {
	while (1) {
		static int cnt = 0;
		int result = check();
		cnt++;
		if (result == 1) {
			printf("로그인 성공\n");
			break;
		}
		if (cnt == 3) {
			printf("로그인 시도횟수 초과\n");
			break;
		}
	}
}

int get_sum(int n) {
	if (n == 1)return 1;
	else return n + get_sum(n - 1);
}
int p4() {
	int n;
	printf("정수 입력 : ");
	scanf_s("%d", &n);
	printf("1부터 %d까지의 합 = %d\n", n, get_sum(n));
}

int power(int base, int power_raised) {
	if (power_raised == 1)return base;
	else return base * power(base ,power_raised-1);
}
int p5() {
	int p, r;
	printf("밑수: ");
	scanf_s("%d", &p);
	printf("지수 : ");
	scanf_s("%d", &r);

	printf("%d^%d = %d\n", p, r, power(p, r));
}

void show_digit(int x) {
	if(x/10>0) show_digit(x / 10);
	printf("%d ", x % 10);
}
int p6() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	show_digit(n);
}

int count_digit(int x) {
	static int count = 0;
	if(x/10==0){
		count++;
		return count;
	}
	else {
		count++;
		return count_digit(x / 10);
	}
}
int p7() {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	printf("자리수의 개수 : %d\n", count_digit(n));
}

int get_digit_sum(int n) {
	static int sum = 0;
	if (n / 10 > 0) return (n % 10) + get_digit_sum(n / 10);
	else return n;
}
int p8() {
	int n;
	printf("정수를 입력: ");
	scanf_s("%d", &n);
	printf("자리수의 합 : %d\n", get_digit_sum(n));
}

double recursive(int n) {
	if (n == 1) return 1.0;
	else return (1.0 / n + recursive(n - 1));
}
int p9() {
	int n;
	printf("정수 입력: ");
	scanf_s("%d", &n);
	printf("recursive(%d)의 결과값 = %f\n", n, recursive(n));
}
