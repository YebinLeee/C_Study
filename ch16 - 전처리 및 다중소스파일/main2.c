#include <stdio.h>
int main(void) {
	//p1(); // 예제1: 비트 필드 구조체
	//p2(); // 예제2: 전처리기 활용
	//p3(); // 문제1: 구구단 역순 출력
	//p4(); // 문제2: 3단씩 구구단 출력
	//p5(); // 문제3: 홀,짝에 따라 구구단 출력
	//p6(); // 실습 4번
	p7(); // 실습 5번
	return 0;
}

struct product {
	unsigned style : 3; // 비트 단위로 메모리를 할당하는 멤버(3비트:0~7값)
	unsigned size : 2;
	unsigned color : 1;
};
int p1() {
	struct product p1;
	
	p1.style = 5;
	p1.size = 3;
	p1.color = 1;

	printf("style=%d size=%d color=%d\n", p1.style, p1.size, p1.color);
	printf("sizeof(p1)=%d\n", sizeof(p1));
	// 비트필드 구조체 p1의 크기는 정수 4 byte (그 공간 안에서 3,2,1 bit 공간을 사용)
	printf("p1=%x\n", p1);
}


#define USA // 사용하지 않는 경우 주석처리 하기 -> 두가지 버전의 프로그램 실행 가능
#define DEBUG

#ifndef PI
#define PI 3.141592
#endif

#ifndef SQUARE
#define SQUARE(r) (r)*(r)
#endif

double area(double radius) {
	double result = 0.0;
#ifdef DEBUG
#ifdef USA
	printf("area(%f) is called \n", radius);
#else
	printf("area(%f)가 호출되었음\n", radius);
#endif
#endif
	result = PI * SQUARE(radius);
	return result;
}

int p2() {
	double radius;
#ifdef USA
	printf("Please enter radius of a circle(inch): ");
#else
	printf("원의 반지름을 입력하시오: ");
#endif
	scanf_s("%lf", &radius);
#ifdef USA
	printf("area of the circle is %f \n", area(radius));
#else
	printf("원의 면적은 %f입니다\n", area(radius));
#endif
}

// 문제1 : 출력하고 싶은 구구단의 단 입력받아 역순으로 출력
int p3() {
	int n; // 변수 선언

	printf("출력할 구구단을 입력하시오 : ");
	scanf_s("%d", &n); // 키보드로 입력받는 함수

	for (int i = 9;i >= 1;i--) // 반복문과 출력함수
		printf("%d * %d = %2d\n", n, i, i * n); // 오른쪽 정렬
}

// 한 줄에 3단씩 출력하는 구구단
int p4() {
	for (int i = 1;i <= 9;i+=3)
	{
		printf(" %d단\t %d단 \t%d단\n", i, i + 1, i + 2); // 한 줄에 3단씩
		for (int j = 1;j <= 9;j++) {
			printf("%d*%d=%2d\t", i, j, i * j);
			printf("%d*%d=%2d\t", i + 1, j, (i + 1) * j);
			printf("%d*%d=%2d\n", i + 2, j, (i + 2) * j);
		}
	}
}

// 단의 수가 홀,짝이냐에 따라 구분
int p5() {
	for (int i = 1;i <= 9;i++) {
		printf(" %d단\n", i);
		if (i % 2 == 0) {
			for (int j = 0;j <= 8;j += 2) {
				printf("%d * %d = %d\n", i, j, i * j);
			}
		}
		else {
			for (int j=1;j<=9;j+=2)
				printf("%d * %d = %d\n", i, j, i * j);
		}
	}
}


#ifndef PI
#define PI 3.141592
#endif

#ifndef VOLUME
#define VOLUME(r,h) (PI)*(r)*(r)*(h)
#endif

int p6() {
	int r, h;
	
	printf("원기둥의 반지름을 입력하시오: ");
	scanf_s("%d", &r);
	printf("원기둥의 높이를 입력하시오: ");
	scanf_s("%d", &h);
	printf("원기둥의 부피: %f\n", VOLUME(r, h));
}

#ifndef IS_SPACE(c)
#define IS_SPACE(c) ((c==' ' || c=='\t' || c=='\n')? 1:0)
#endif

int p7() {
	char s[50];
	int n=0;

	printf("문자열을 입력하시오: ");
	gets(s);
	for (int i = 0;s[i] != NULL;i++) {
		if (IS_SPACE(s[i])) n++;
	}
	printf("공백문자의 개수: %d\n", n);
}