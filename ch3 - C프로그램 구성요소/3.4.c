#include <stdio.h>
int pro6()
{
	double c_temp, f_temp;
	printf("ȭ������ �Է��Ͻÿ�: ");
	scanf_s("%lf", &f_temp);
	c_temp = 5.0 / 9.0 * (f_temp - 32.0);	// �Ǽ������� c_temp�� �����ϱ� ���ؼ��� ������ �ǿ����� ���� �Ǽ�������.
	printf("�������� %lf���Դϴ�.\n", c_temp);
	return 0;
}