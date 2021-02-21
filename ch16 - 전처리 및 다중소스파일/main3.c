#include <stdio.h>
int main(void) {
	// p1();
	// p2();
	// p3();
	// p4();
	// p5();

	return 0;
}

#define AND &&
# define OR ||
#define NOT !
#define IS ==
#define ISNOT !=
int search(int list[], int n, int key) {
	int i = 0;
	while (i < n AND list[i] ISNOT key)
		i++;
	if (i IS n) return -1;
	else return i;
}
int p1() {
	int m[] = { 1,2,3,4,5,6,7 };
	printf("배열에서 5의 위치 = %d\n", search(m, sizeof(m) / sizeof(m[0]), 5));
}

#define SQUARE(x) ((x)*(x))
int p2() {
	int x = 2;
	printf("%d\n", SQUARE(x));
	printf("%d\n", SQUARE(3));
	printf("%f\n", SQUARE(1.2));
	printf("%d\n", SQUARE(x+3));
	printf("%d\n", 100/SQUARE(x));
	printf("%d\n", SQUARE(++x));
}

// #define PRINT(exp) printf("exp=%d\n",exp); // exp가 그대로 나오는 경우
#define PRINT(exp) printf(#exp"=%d\n",exp); // #exp가 함수 내에서 사용한 변수 이름으로 치환되는경우
int p3() {
	int x = 5;
	PRINT(x);
}

#include <stdlib.h>
#define ASSERT(exp) {if(!(exp))\
		{printf("가정(" #exp ")이 소스파일 %s %d번째 줄에서 실패.\n" \
		,__FILE__, __LINE__), exit(1);}}
int p4() {
	int sum = 100;
	ASSERT(sum == 0);
}

#define LINUX
int p5() {
#ifdef LINUX
	printf("윈도우 버전입니다.\n");
#elif
	printf("윈도우 버전입니다. \n");
#endif
}