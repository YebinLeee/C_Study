// ���� ǥ������ ü������ ���ϴ� ���α׷�
#include <stdio.h>

int main(void)
{
	double radius;
	double const �� = 3.141592; // ���̸� ��ȣ����� ����Ͽ� �����Ѵ�.

	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%lf", &radius);

	printf("ǥ������ %lf�Դϴ�.\n", 4 * �� * radius * radius);
	printf("ü���� %lf�Դϴ�.\n", 4.0/3.0 * �� * radius * radius * radius);


	return 0;
}