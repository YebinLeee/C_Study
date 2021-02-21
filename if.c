#include <stdio.h>

int main(void)
{
	//들여쓰기를 하지 않았음!
	if (1 > 2)
		if (3 < 4)
			printf("A\n");
		else
			printf("B\n");
	printf("C\n");

	return 0;
}