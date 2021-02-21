#include <stdio.h>
int main(void) {
	//p1();
	//p2();
	//p3();
	//p4();
	p5();

	return 0;
}
int p1() {
	int n;
	printf("출력을 원하는 줄을 입력하시오 : ");
	scanf_s("%d", &n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
}

int p2() {
	int n;
	printf("출력을 원하는 줄을 입력하시오 : ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i++) {
		int num = n - i + 1;
		for (int j = (n - i);j >= 1;j--)
			printf(" ");
		for (int k = 1;k <= i;k++)
			printf("%d", num++);
		printf("\n");
	}

	/* 답안지 
	for (int i = 9;i >= 1;i--) {
		for (int j = 1;j <= i - 1;j++) {
			printf(" ");
		}
		for (int k = i;k <= 9;k++) {
			printf("%d", k);
		}
		printf("\n");
	}
	*/
}

int p3() {
	int n;
	printf("홀수를 입력하시오 : ");
	scanf_s("%d", &n);
	
	//i: 줄번호, j: 공백개수, k: 별개수
	for (int i = 1;i<=(n + 1) / 2;i++) {
		for (int j = 1;j<=(n + 1) / 2 - i;j++)
			printf(" ");
		for (int k = 1;k <= i*2-1;k++)
			printf("*");
		printf("\n");
	}

	/* 답안지
	for (int i = 1;i <= n;i += 2) {
		for (int j = i;j<=(n - 2);j += 2)
			printf(" ");
		for (int k = 1;k <= i;k++)
			printf("*");
		printf("\n");
	}
	*/
	// n==2인경우
	/*for (int i = 0;i < 5;i++) {
		for (int j = 0;j < i + 2;j++)
			printf(" ");
		for (int k = 5;k < (i * 2);k--)
			printf("*");
		printf("\n");
	}
	*/
	
}

int p4() {
	int n;
	printf("홀수를 입력하시오 : ");
	scanf_s("%d", &n);

	for (int i = 1;i <= (n + 1) / 2;i++) {
		for (int j = 1;j <= (n + 1) / 2 - i;j++)
			printf(" ");
		for (int k = 1;k <= i * 2 - 1;k++)
			printf("*");
		printf("\n");
	}
	/*
	for (int i = 1; i < (n + 1) / 2;i++) {
		for (int j = 1;j <= i;j++)
			printf(" ");
		for(int k=)
			printf
		printf("\n");
	}
	*/
}

//파스칼의 삼각형
int p5() {
	int n;
	printf("홀수를 입력하시오 : ");
	scanf_s("%d", &n);

	for (int i = 1;i <= n;i += 2) {
		int num=1;
		for (int j = i;j <= (n - 2);j += 2)
			printf("   ");
		for (int k = 1;k <= i;k++) {
			printf("%3d", num);
			if(num<i) num += 2;
			else num -= 2;
		}
		printf("\n");
	}

	/*답안지
	for (int i = 1;i <= n;i += 2) {
		for (int j = i;j <= (n - 2);j += 2)
			printf(" ");
		for (int k = 1,j=1,l=i-2;k <= i;k++) {
			if (j <= i) {
				printf("%3d", j);
				j += 2;
			}
			else {
				printf("%3d", l);
				l -= 2;
			}
			}
		}
		printf("\n");
	}
	*/
}