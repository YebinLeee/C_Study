#include <stdio.h>
int pro1()
{
	int a, b, max, min;
	printf("2���� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d", &a, &b);

	if (a > b)
		max = a, min = b;
	else
		max = b, min = a;

	printf("��:%d ������:%d\n\n", max / min, max % min);

	return 0;
}
int pro2()
{
	double a, b;
	printf("2���� �Ǽ��� �Է��Ͻÿ�: ");
	scanf_s("%lf %lf", &a, &b);
	printf("��: %lf, ��: %lf, ��: %lf, ��: %lf\n\n", a + b, a - b, a * b, a /b);
	return 0;
}
int pro3()
{
	int a, b, c, max;

	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d %d", &a, &b, &c);
	
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	// ���� ���� �����ڽ��� �̿��ؼ� �ִ��� �� ���� ���ϱ�
	
	/*
	max = a > b ? a : b;
	max = max > c ? max : c;
	*/

	printf("�ִ�: %d\n", max);

	return 0;
}
int pro4()
{
	int cm, feet;
	double inch;

	printf("Ű�� �Է��Ͻÿ�(cm): ");
	scanf_s("%d", &cm);
	
	inch = cm / 2.54;	// cm�� inch �� �ٲ۴�.
	feet = inch / 12;	// �� inch�� feet�� �ٲ۴�. (�ᱹ ���� cm�� feet�� �ٲ۴�.)
	inch = inch-(feet*12);	// ���� inch���� feet�� �ٲ� �����͸� inch�� �ٽ� �ٲپ� ���� inch�� ���Ѵ�.

	printf("%dcm�� %d��Ʈ %lf��ġ�Դϴ�.\n", cm, feet, inch);

	return 0;
}
int pro5()
{
	int num;
	
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num);
	printf("�����ڸ�: %d\n", num / 10);
	printf("�����ڸ�: %d\n", num % 10);
	
	return 0;
}
int pro6()
{
	int num;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num);
	printf("2�� ����: %d \n", ~num + 1);
	return 0;
}
int pro7()
{
	int x,y;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &x);
	printf("2�� ���ϰ� ���� Ƚ��: ");
	scanf_s("%d", &y);
	printf("x<<y�� ��: %d\n\n", x << y);

	return 0;
}
int pro8()
#define PI 3.141592
{
	double radius, surface_area, volume;
	printf("���� �������� �Է��Ͻÿ�: ");
	scanf_s("%lf", &radius);

	surface_area = 4 * PI * radius * radius;
	volume = 4 / 3 * PI * radius * radius * radius;
	printf("ǥ������ %lf�Դϴ�.\n", surface_area);
	printf("ü���� %lf�Դϴ�.\n\n", volume);

	return 0;
}
int pro9()
{
	double height, shadow;
	double pyramid_height, length;

	printf("�������� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%lf", &height);
	printf("������ �׸����� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%lf", &shadow);
	printf("�Ƕ�̵������ �Ÿ��� �Է��Ͻÿ�: ");
	scanf_s("%lf", &length);

	pyramid_height = height * length / shadow;
	printf("�Ƕ�̵��� ���̴� %lf�Դϴ�.\n\n", pyramid_height);

	return 0;
}
int pro10()
{
	int x, y;
	printf("x��ǥ�� y��ǥ�� ���ʴ�� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &x, &y);
	
	if (x > 0)
		y > 0 ? printf("1��и�\n") : printf("4��и�\n");
	else
		y > 0 ? printf("2��и�\n") : printf("3��и�\n");

	return 0;
}
#define PI 3.141592
int pro11()
{
	double distance, angle, radius;

	printf("�Ÿ��� �Է��Ͻÿ�: ");
	scanf_s("%lf", &distance);
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%lf", &angle);

	radius = distance * 360.0 / (angle*PI*2);
	printf("������ �������� %lf\n\n", radius);

	return 0;
}
int pro12()
{
	unsigned int num = 0;	// �ݵ�� 0���� �ʱ�ȭ�����ش�. 
	char ch1, ch2, ch3, ch4;

	printf("ù��° ���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &ch1);	// a�� �Է¹޴´�. ���ڸ� �Է¹��� ���� �տ� ������ �߰����ش�.
	num = num | ch1;	// 

	printf("�ι�° ���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &ch2);
	num = num| ch2<<8;

	printf("����° ���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &ch3);
	num = num | ch3<<16;

	printf("�׹�° ���ڸ� �Է��Ͻÿ�: ");
	scanf_s(" %c", &ch4);
	num |= ch4<<24;

	printf("�����: %x\n\n", num);

	return 0;
}