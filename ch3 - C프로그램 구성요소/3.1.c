#include <stdio.h>
#define SIZE 3
int pro3()
{
	double a[SIZE], sum=0, avg;
	for (int i = 0;i < SIZE;i++)
	{
		printf("�Ǽ��� �Է��Ͻÿ�: ");
		scanf_s("%lf", &a[i]);
		sum += a[i];
	}
	avg = sum / SIZE;

	printf("���� %lf�̰� ����� %lf�Դϴ�.\n", sum, avg);
	
	return 0;
}