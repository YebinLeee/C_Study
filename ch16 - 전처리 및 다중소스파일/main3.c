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
	printf("�迭���� 5�� ��ġ = %d\n", search(m, sizeof(m) / sizeof(m[0]), 5));
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

// #define PRINT(exp) printf("exp=%d\n",exp); // exp�� �״�� ������ ���
#define PRINT(exp) printf(#exp"=%d\n",exp); // #exp�� �Լ� ������ ����� ���� �̸����� ġȯ�Ǵ°��
int p3() {
	int x = 5;
	PRINT(x);
}

#include <stdlib.h>
#define ASSERT(exp) {if(!(exp))\
		{printf("����(" #exp ")�� �ҽ����� %s %d��° �ٿ��� ����.\n" \
		,__FILE__, __LINE__), exit(1);}}
int p4() {
	int sum = 100;
	ASSERT(sum == 0);
}

#define LINUX
int p5() {
#ifdef LINUX
	printf("������ �����Դϴ�.\n");
#elif
	printf("������ �����Դϴ�. \n");
#endif
}