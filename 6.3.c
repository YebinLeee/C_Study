#include <stdio.h>

int main(void)
{
	int num1, num2, num3, min;
	
	printf("3개의 정수를 입력하시오:");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 < num2) {
		if (num1 < num3)
			printf("제일 작은 정수는 %d입니다.\n", num1);
		else
			printf("제일 작은 정수는 %d입니다.\n", num3);
	}
	else {
		if (num2 < num3)
			printf("제일 작은 정수는 %d입니다.\n", num2);
		else
			printf("제일 작은 정수는 %d입니다.\n", num3);
	}

	return 0;
}