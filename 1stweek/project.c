#include <stdio.h>
int main(void)
{
	/*
	p1();
	p2();
	p3();
	p4();
	p5();
	*/

	//p6();
	//p7();
	p8();

	return 0;
}
int p1(void)
{
	printf("�й�: 20204059\n�а�: ��ǻ�ͼ���Ʈ������а�\n�̸�: �̿���\n\n");
}
int p2(void)
{
	int x = 10;
	float z = 15.7;
	printf("x = %d\n", x);
	printf("z = %f\n\n", z);
}
int p3(void)
{
	int age;
	printf("���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &age);
	printf("����� %d ���Դϴ�.\n\n", age);
}
int p4(void)
{
	char c;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &c);
	printf("ASCII �ڵ�: %d\n\n", c);
}
int p5(void)
{
	int num1, num2;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%x", &num1);
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%x", &num2);
	printf("���� ����� %d(10����)�Դϴ�.\n", num1 + num2);
	printf("���� ����� %x(16����)�Դϴ�.\n\n", num1 + num2);
}
int p6(void)
{
	float quiz1, quiz2, mid, fin;
	printf("==========QUIZZES===========\n");
	printf("�����: ");
	scanf_s("%f", &quiz1);
	printf("�����: ");
	scanf_s("%f", &quiz2);
	printf("==========MID TERM==========\n");
	printf("�߰���� ����: ");
	scanf_s("%f", &mid);
	printf("==========FINAL=============\n");
	printf("�⸻��� ����: ");
	scanf_s("%f", &fin);
	printf("Quizz Total: %f\n", quiz1 + quiz2);
	printf("Mid: %f\n", mid);
	printf("Final: %f\n", fin);
	printf(".........................\n");
	printf("Total: %f\n\n", quiz1 + quiz2 + mid + fin);
	return 0;
}
int p7(void)
{
	int side1, side2, side3;
	printf("�ﰢ���� �� ���� �Է��Ͻÿ�:\n");
	scanf_s("%d %d %d", &side1, &side2, &side3);
	
	if (side1 == side2) {
		if (side3 == side2)
			printf("���ﰢ��\n");
		else
			printf("�̵ �ﰢ��\n");
	}
	else if (side1 == side3) {
		if (side2 == side3)
			printf("���ﰢ��\n");
		else
			printf("�̵ �ﰢ��\n");
	}
	else if (side2 == side3) {
		if (side1 == side2)
			printf("���ﰢ��\n");
		else
			printf("�̵ �ﰢ��\n");
	}
	else
		printf("�Ϲ� �ﰢ��\n");
	printf("\n");
}
int p8(void)
{
	char color;
	printf("��ȣ���� ���� �Է� (R, G, Y): ");
	scanf_s(" %c", &color);
	
	if (color == 'r')
		printf("����!\n");
	else if (color == 'g')
		printf("����\n");
	else
		printf("����\n");
}
