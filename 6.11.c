#include <stdio.h>
int main(void)
{
	char a;

	printf("문자를 입력하시오: ");
	a = getchar();

	switch (a)
	{ case 'r':
	case 'R':
		printf("Rectangle \n");
		break;
	case 't':
	case 'T':
		printf("Triangle \n");
		break;
	case 'c':
	case 'C':
		printf("Circle \n");
		break;
	default:
		printf("Unknown \n");
	}

	return 0;
}