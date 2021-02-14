#include <stdio.h>
int p1()
{
	int x = 1, y = 2, z = 3;
	double f = 0.0;

	printf("3/5 = %d\n3%%5 = %d\n", 3 / 5, 3 % 5);	// 3을 5로 나눈 나머지는 3이다.
	printf("3.0/5.0 = %f\n3.0 %% 5.0 = %f\n", 3 / 5, 3 % 5);
	y *= x;
	printf("y *= x = %d\n", y);
	x++;
	printf("x++ => x= %d\n", x);
	printf("2.0 / 4 = %f\n", 2.0 / 4);

	x = 12.3;
	printf("x= 12.3 => x = %d\n", x);
	f = (double)x;
	printf("f = (double)x = %lf\n", f);

	int i = 5;
	printf("%d\n", i++ * i++);
	printf("i = %d\n", i);

	return 0;
}