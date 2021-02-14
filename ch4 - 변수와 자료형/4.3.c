#include <stdio.h>
int pro6()
{
	int x, y, tmp;

	printf("x와 y값을 입력하시오: ");
	scanf_s("%d %d", &x, &y);
	printf("x=%d y=%d\n", x, y);

	tmp = x;
	x = y;
	y = tmp;

	printf("x=%d y=%d", x, y);

	return 0;
}