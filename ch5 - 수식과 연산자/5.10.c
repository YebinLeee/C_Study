#include <stdio.h>

int main(void)
{
	int x, y;
	printf("x ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d", &x);
	printf("y ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d", &y);

	(x > 0) ? ((y > 0) ? printf("1��и�\n") : printf("4��и�\n"))
		: ((y > 0) ? printf("2��и�\n") : printf("3��и�\n"));

	return 0;
}