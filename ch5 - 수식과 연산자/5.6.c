// 2�� ������ ����ϴ� ���α׷�

#include <stdio.h>

int main(void)
{
	int num;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num);

	printf("2�Ǻ���: %d\n", ~num + 1); // 2�� ������ �Է¹��� ������ ��Ʈ�� ������Ų �� 1�� ���Ѵ�.

	return 0;
}