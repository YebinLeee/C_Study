#include <stdio.h>
#include <limits.h>
int pro3()
{
	char code = 'A';
	char code2 = 65;
	char beep = 7;
	char beep2 = '\a';

	// ���� ����� ǥ���Ҷ��� �ƽ�Ű�ڵ� ���� ���� �Է��ϰų�, ���� ����ǥ ''�� �̿��� ���ڸ� ���� ������ �� �ִ�.
	// ���� ��� ���� �ƽ�Ű�ڵ� ���� �Է��ϰų�, /���ڸ� ��������ǥ �ȿ� �־� ������ �� �ִ�.

	printf("%d %c \n%d %c \n%d % \n%d %c\n", code + 1, code + 1, code2 + 1, code2 + 1, beep+1, beep+1, beep+1, beep+1);

	int a = 100;
	char b = 'X';
	float c = 1.2345;
	printf("%d, %c, %f\n", a, b, c);

	return 0;
}