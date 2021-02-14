#include <stdio.h>
#include <limits.h>
int pro3()
{
	char code = 'A';
	char code2 = 65;
	char beep = 7;
	char beep2 = '\a';

	// 문자 상수를 표기할때는 아스키코드 값을 직접 입력하거나, 작은 따옴표 ''를 이용해 문자를 직접 대입할 수 있다.
	// 제어 상수 또한 아스키코드 값을 입력하거나, /문자를 작은따옴표 안에 넣어 대입할 수 있다.

	printf("%d %c \n%d %c \n%d % \n%d %c\n", code + 1, code + 1, code2 + 1, code2 + 1, beep+1, beep+1, beep+1, beep+1);

	int a = 100;
	char b = 'X';
	float c = 1.2345;
	printf("%d, %c, %f\n", a, b, c);

	return 0;
}