#include <stdio.h>

int main(void)
{
	char ch1, ch2, ch3, ch4;
	unsigned int result = 0;

	printf("ù��° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &ch1);
	result = result + ch1;

	printf("�ι�° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &ch2);
	result = result + (ch2 << 8);

	printf("����° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &ch3);
	result = result + (ch3 << 16);

	printf("�׹�° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &ch4);
	result = result + (ch4 << 24);

	printf("%x\n", result);

	return 0;
}