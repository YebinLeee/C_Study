#include <stdio.h>
int main(void)
{
	char a;

	printf("���ڸ� �Է��Ͻÿ�: ");
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