#include <stdio.h>

int main(void)
{
	char ch1, ch2, ch3, ch4;
	unsigned int result = 0;

	printf("첫번째 문자를 입력하시오: ");
	scanf(" %c", &ch1);
	result = result + ch1;

	printf("두번째 문자를 입력하시오: ");
	scanf(" %c", &ch2);
	result = result + (ch2 << 8);

	printf("세번째 문자를 입력하시오: ");
	scanf(" %c", &ch3);
	result = result + (ch3 << 16);

	printf("네번째 문자를 입력하시오: ");
	scanf(" %c", &ch4);
	result = result + (ch4 << 24);

	printf("%x\n", result);

	return 0;
}