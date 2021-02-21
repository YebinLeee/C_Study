#include <stdio.h>
int main(void) {
	//p1(); // ����1: ��Ʈ �ʵ� ����ü
	//p2(); // ����2: ��ó���� Ȱ��
	//p3(); // ����1: ������ ���� ���
	//p4(); // ����2: 3�ܾ� ������ ���
	//p5(); // ����3: Ȧ,¦�� ���� ������ ���
	//p6(); // �ǽ� 4��
	p7(); // �ǽ� 5��
	return 0;
}

struct product {
	unsigned style : 3; // ��Ʈ ������ �޸𸮸� �Ҵ��ϴ� ���(3��Ʈ:0~7��)
	unsigned size : 2;
	unsigned color : 1;
};
int p1() {
	struct product p1;
	
	p1.style = 5;
	p1.size = 3;
	p1.color = 1;

	printf("style=%d size=%d color=%d\n", p1.style, p1.size, p1.color);
	printf("sizeof(p1)=%d\n", sizeof(p1));
	// ��Ʈ�ʵ� ����ü p1�� ũ��� ���� 4 byte (�� ���� �ȿ��� 3,2,1 bit ������ ���)
	printf("p1=%x\n", p1);
}


#define USA // ������� �ʴ� ��� �ּ�ó�� �ϱ� -> �ΰ��� ������ ���α׷� ���� ����
#define DEBUG

#ifndef PI
#define PI 3.141592
#endif

#ifndef SQUARE
#define SQUARE(r) (r)*(r)
#endif

double area(double radius) {
	double result = 0.0;
#ifdef DEBUG
#ifdef USA
	printf("area(%f) is called \n", radius);
#else
	printf("area(%f)�� ȣ��Ǿ���\n", radius);
#endif
#endif
	result = PI * SQUARE(radius);
	return result;
}

int p2() {
	double radius;
#ifdef USA
	printf("Please enter radius of a circle(inch): ");
#else
	printf("���� �������� �Է��Ͻÿ�: ");
#endif
	scanf_s("%lf", &radius);
#ifdef USA
	printf("area of the circle is %f \n", area(radius));
#else
	printf("���� ������ %f�Դϴ�\n", area(radius));
#endif
}

// ����1 : ����ϰ� ���� �������� �� �Է¹޾� �������� ���
int p3() {
	int n; // ���� ����

	printf("����� �������� �Է��Ͻÿ� : ");
	scanf_s("%d", &n); // Ű����� �Է¹޴� �Լ�

	for (int i = 9;i >= 1;i--) // �ݺ����� ����Լ�
		printf("%d * %d = %2d\n", n, i, i * n); // ������ ����
}

// �� �ٿ� 3�ܾ� ����ϴ� ������
int p4() {
	for (int i = 1;i <= 9;i+=3)
	{
		printf(" %d��\t %d�� \t%d��\n", i, i + 1, i + 2); // �� �ٿ� 3�ܾ�
		for (int j = 1;j <= 9;j++) {
			printf("%d*%d=%2d\t", i, j, i * j);
			printf("%d*%d=%2d\t", i + 1, j, (i + 1) * j);
			printf("%d*%d=%2d\n", i + 2, j, (i + 2) * j);
		}
	}
}

// ���� ���� Ȧ,¦�̳Ŀ� ���� ����
int p5() {
	for (int i = 1;i <= 9;i++) {
		printf(" %d��\n", i);
		if (i % 2 == 0) {
			for (int j = 0;j <= 8;j += 2) {
				printf("%d * %d = %d\n", i, j, i * j);
			}
		}
		else {
			for (int j=1;j<=9;j+=2)
				printf("%d * %d = %d\n", i, j, i * j);
		}
	}
}


#ifndef PI
#define PI 3.141592
#endif

#ifndef VOLUME
#define VOLUME(r,h) (PI)*(r)*(r)*(h)
#endif

int p6() {
	int r, h;
	
	printf("������� �������� �Է��Ͻÿ�: ");
	scanf_s("%d", &r);
	printf("������� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &h);
	printf("������� ����: %f\n", VOLUME(r, h));
}

#ifndef IS_SPACE(c)
#define IS_SPACE(c) ((c==' ' || c=='\t' || c=='\n')? 1:0)
#endif

int p7() {
	char s[50];
	int n=0;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(s);
	for (int i = 0;s[i] != NULL;i++) {
		if (IS_SPACE(s[i])) n++;
	}
	printf("���鹮���� ����: %d\n", n);
}