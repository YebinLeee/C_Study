#include <stdio.h>
int pro2()
{
	int id, password;
	printf("���̵�� �н����带 4���� ���ڷ� �Է��Ͻÿ�: \n");
	printf("id: ____\b\b\b\b");	// \b�� ȭ���� Ŀ���� �ڷ� �����̴� ������̴�.
	scanf_s("%d", &id);
	printf("pw: ____\b\b\b\b");
	scanf_s("%d", &password);

	printf("\a�Էµ� ���̵�� \"%d\"�̰� �Էµ� �н����� \"%d\"�Դϴ�.\n", id, password);
	// ȭ�鿡 ""ū����ǥ�� ����ϰ� �ʹٸ�, \""\�� ����ϸ� �ȴ�.

}