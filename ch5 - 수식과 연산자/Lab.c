#include <stdio.h>
//p.180 �Ž����� ��� :Lab
int p3()
{
	int price, money, change;
	int change5000, change1000, change500, change100;

	printf("���� ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &price);
	printf("����ڰ� �� ��: ");
	scanf_s("%d", &money);
	
	change = price - money;	// ���� ������ ����ڰ� �� �� (������ ��)�� ����Ѵ�.
	change5000 = change / 5000;	//5000�� �Ž������� change�� 5000������ ���� ���̴�.
	change = change % change5000;	// change���� 5000������ ���� ���������� �ٽ� �����Ѵ�.

	change1000 = change / 1000;	// change�� 1000���� ���� ���� 1000�� �Ž����� �����̴�.
	change = change % change1000;	// change�� 1000���� ���� ���� ���������� �����Ѵ�.

	change500 = change / 500;
	change = change % change500;

	change100 = change / 100;

	printf("��õ����: %d\n", change5000);
	printf("õ����: %d\n", change1000);
	printf("�������: %d\n", change500);
	printf("�����: %d\n\n", change100);

	return 0;
}

// p. 192 ���� �Ǵ�
int p4()
{
	int year;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &year);
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		printf("%d�⵵�� �����Դϴ�.\n", year);
	else
		printf("%d�⵵�� ������ �ƴմϴ�.\n", year);
		
	return 0;
}

// p.201  lab 10������ 2������ �ٲٱ�
int p5()
{
	unsigned int num;	// ��ȣ ���� unsingd int�� ���� ���� num ����.
	printf("10���� ������ �Է��Ͻÿ�: "); // 128(2���� : 10000000)���� ���� �� �Է¹ޱ�
	scanf_s("%d", &num);
	printf("10����: %d\n", num);
	printf("2����: ");

	unsigned int mask = 1 << 7;	// '1'�� 7��Ʈ �մ��, �ϳ��� num�� mask�� ��Ʈ�� ���� ���̴�. &�����ڸ� �̿��Ͽ�
	// num�� ��Ʈ �� 1�� �ִٸ�, mask�� num�� ���� 1�� ��� �� ���̴�. �̸� 8�� �ݺ��ϸ� �ȴ�.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;

	printf("\n\n");

	return 0;
}

//p. 202 XOR�� �̿��� ��ȣȭ
int p6()
{
	char data, key = 0xff;
	printf("���� �����͸� �Է��Ͻÿ�: ");
	scanf_s(" %c", &data);

	char encrpted_data = data ^ key;
	printf("��ȣȭ�� ����= %c  \n", encrpted_data);

	char orig_data = encrpted_data ^ key;
	printf("������ ������ = %c \n\n", data);

	return 0;
}