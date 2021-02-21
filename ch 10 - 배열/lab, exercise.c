#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int main(void) {

	//lab , exercise
	//p1();
	//p2();
	//p3();
	//p4();
	p6();
	
	return 0;
}
int p3() {
	int a[SIZE] = { 0 };
	char ans;
	int num;
	int ppl;

	int b[SIZE] = { 0 };
	for (int i = 1;i <= 10;i++)
		a[SIZE] = i;
	while (1)
	{
		printf("좌석을 예약하시겠습니까?(y 또는 n): ");
		scanf_s(" %c", &ans);
		if (ans == 'n') break;
		printf("몇 명 예약 하시겠습니까? : ");
		scanf_s("%d", &ppl);
		printf("------------------\n");
		for (int i = 0;i < SIZE;i++)
			printf("%d ", a[i]);
		printf("------------------\n");
		for (int i = 0;i < SIZE;i++)
			printf("%d ", b[i]);
		printf("몇번째 좌석 예약? : ");
		for (int i = 0;i < ppl;i++)
		{
			printf("%d번쨰 사람: ", i + 1);
			scanf_s("%d", &num);
			if (a[num - 1] == 0) {
				a[num - 1] == 1;
				printf("예약되었습니다.\n");
			}
			else {
				printf("이미 예약된 자리입니다. 처음부터 다시\n");
				break;
			}
		}
	}
	return 0;
}

int get_average(int n[], int size) {

	int sum = 0;
	for (int i = 0;i < n;i++)
		sum += n[i];
	return sum/size;
}
int p5()
{
	int scores[SIZE] = {1,2,3,4,5};
	int avg;

	avg = get_average(scores, SIZE);
	printf("평균은 %d입니다.\n", avg);
	return 0;
}

int p6() {
	int list[SIZE] = { 6,2,9,12,1 };
	int i, j, least, tmp;

	for (i = 0;i < SIZE - 1;i++) {
		least = i;
		for (j = i + 1;j < SIZE;j++)
			if (list[j] < list[least])
				least = j;
		tmp = list[i];
		list[i] = list[least];
		list[least] = tmp;
	}
	for (i = 0;i < SIZE;i++)
		printf("%d ", list[i]);

	return 0;
}