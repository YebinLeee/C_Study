#include <stdio.h>

int main(void)
{
	double f_temp, c_temp;

	printf("ȭ���µ��� �Է��ϼ���: ");
	scanf("%lf", &f_temp);
	c_temp = ((double)5 / 9) * (f_temp - 32);

	printf("�����µ��� %f�Դϴ�. \n", c_temp);

	return 0;
}