// 2의 보수를 계산하는 프로그램

#include <stdio.h>

int main(void)
{
	int num;

	printf("정수를 입력하시오: ");
	scanf("%d", &num);

	printf("2의보수: %d\n", ~num + 1); // 2의 보수는 입력받은 정수의 비트를 반전시킨 후 1을 더한다.

	return 0;
}