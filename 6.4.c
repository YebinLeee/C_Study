#include <stdio.h>

int main(void)
{
	int num, random;

	printf("�����Ͻÿ�(1���� 2:���� 3:��)");
	scanf("%d", &num);

	random = (rand() % 3 + 1);

	if (num == 1) {
		if (random == 3)
			printf("����ڰ� �̰��� \n��ǻ���� ����: %d\n", random);
		else if (random==1)
			printf("����ڿ� ����� \n��ǻ���� ����: %d\n", random);
		else
			printf("����ڰ� ���� \n��ǻ���� ����: %d\n", random);
	}
	else if (num == 2) {
		if (random == 1)
			printf("����ڰ� �̰��� \n��ǻ���� ����: %d\n", random);
		if (random == 2)
			printf("����ڿ� ����� \n��ǻ���� ����: %d\n", random);
		else
			printf("����ڰ� ���� \n��ǻ���� ����: %d\n", random);
	}
	else {
		if (random == 2)
			printf("����ڰ� �̰��� \n��ǻ���� ����: %d\n", random);
		if (random == 3)
			printf("����ڿ� ����� \n��ǻ���� ����: %d\n", random);
		else
			printf("����ڰ� ���� \n��ǻ���� ����: %d\n", random);
	}

	return 0;
}