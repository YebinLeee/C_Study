#include <stdio.h>
int main(void)
{
	double height, weight;

	printf("ü�߰� Ű�� �Է��ϼ���: ");
	scanf_s("%lf %lf", &height, &weight);

	if (weight > (height - 100) * 0.9)
		printf("��ü���Դϴ�. \n");
	else if (weight < (height - 100) * 0.9)
		printf("��ü���Դϴ�. \n");
	else
		printf("�����Դϴ�. \n");

	return 0;
}