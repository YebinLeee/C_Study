#include <stdio.h>
int pro11()
{
	int letter;
	printf("아스키 코드값을 입력하시오: ");
	scanf_s("%d", &letter);
	printf("해당 아스키코드 값 %d은 문자 %c입니다.\n", letter, letter);

	return 0;
}