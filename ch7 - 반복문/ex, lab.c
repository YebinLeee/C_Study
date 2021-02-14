#include <stdio.h>
//p. 267 ������ ���α׷�
int p1()
{
	int n;
	printf("���� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	
	// for�� �̿��ϱ�
	for (int i = 1;i <= 9;i++)
		printf("%d * %d = %d\n", n, i, n * i);
	//while�� �̿��ϱ�
	int i = 1;
	while (i <= 9)
	{
		printf("%d * %d = %d\n", n, i, n * i);
		i++;
	}
	return 0;
}
// 1���� n������ �� ������ ������ ����ϴ� ���α׷�
int p2()
{
	int n;
	int i = 1;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	printf("----------------------\n");
	
	while ( i <= n) {
		printf("%5d %5d\n", i, i * i * i);
		i++;
	}
	printf("----------------------\n");
	return 0;
}
int p3()
{
	int students,grade, average, sum = 0;
	printf("�л��� ����? : ");
	scanf_s("%d", &students);
	for (int i = 1;i <= students;i++) {
		printf("�л� %d�� ������ �Է��Ͻÿ�: ", i);
		scanf_s("%d", &grade);
		sum += grade;
	}
	average = sum / students;
	printf("�л����� ��� ������ %d�Դϴ�.\n", average);

	//�迭�� ��Ÿ����
	/*
	int grades[10]={0};
	for (int i=0;i<10;i++){
		printf("�л� %d�� ������ �Է��Ͻÿ�: );
		scanf_s("%d", &grades[i]);
		sum += grades[i]);
		}
	average = sum / 10;
	printf("�л����� ��� ������ %d�Դϴ�. \n", average);
	*/
	
	return 0;
}
// p.276 �ִ� ����� ���ϴ� ���α׷�
int p4()
{
	int x, y, r;
	printf("�� ���� �Է��Ͻÿ�(ū ���� ����): ");
	scanf_s("%d %d", &x, &y);
	
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	printf("%�ִ� ������� %d�Դϴ�.\n", x);

	return 0;
}
//p.278 �ݰ��� ���α׷�
int p5()
{
	int years=0, halflife;
	int initial;
	printf("������ ���� ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &initial);
	int current = initial;

	printf("������ �ݰ��⸦ �Է��Ͻÿ�: ");
	scanf_s("%d", &halflife);

	while (current >= initial * 0.1) {
		years += halflife;
		current =current / 2.0;
		printf("%d�� �� ���� ������ ��.= %d \n", years, current);
	}
	printf("���� 1/10�� �Ǳ���� �ɸ� �ð�: %d��\n\n", years);
	return 0;
}
// �������� (1)
int p6()
{
	int initial = 10;
	double current = initial;
	int quarter_num = 4;
	int hours=1;
	while (hours <= 7) {
		current *= 4;
		printf("%d�ð� ���� ������ �� = %lf\n", hours, current);
		hours++;
	}
	return 0;
}
// �������� (2)
int p7()
{
	unsigned int current = 1;
	for (int i = 0;i < 30;i++)
		current = current * 2;
	
	printf("���̸� 50�� ���� �� �β��� %u�Դϴ�.\n\n", current);
	return 0;
}
//p.281 do...while�� �̿��Ͽ� �޴��� ����
int p8()
{
	int ans;
	printf("1--���θ����\n");
	printf("2--���Ͽ���\n");
	printf("3--���ϴݱ�\n");
	do {
		printf("�޴� �� �ϳ��� �����Ͻÿ�: ");
		scanf_s("%d", &ans);
	} while (ans < 1 || ans>3);
	printf("���õ� �޴� = %d\n\n", ans);

	return 0;
}

#include <stdlib.h>
#include <time.h>
//p.282 ���� ã�� ����
int p9(){

	srand((unsigned)time(NULL));
	int guess;
	int ans = rand() % 100;
	int tries = 0;
	do {
		tries++;
		printf("���� �Է��Ͻÿ�: ");
		scanf_s("%d", &guess);
		if (guess > ans)
			printf("�Է��Ͻ� ���� �亸�� Ů�ϴ�.\n");
		else
			printf("�Է��Ͻ� ���� �亸�� �۽��ϴ�.\n");
	} while (guess != ans);

	printf("�����մϴ�! �õ� Ƚ���� �� %d���Դϴ�.\n", tries);
	return 0;
}

// p.289 n! factorial �� ���ϴ� ���α׷�
int p10() {
	int n;
	int factorial = 1;
	printf("n�� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	for (int i = 1;i <= n;i++)
		factorial *= i;
	printf("%d!�� ���� %d�Դϴ�.\n\n", n, factorial);
	return 0;
}
// ��Ÿ����� ��Ģ�� �����ϴ� �����ﰢ���� �� �� ���ϱ�
int p18()
{
	int a, b, c;
	for (a = 1;a <= 100;a++)
		for (b = 1;b <= 100;b++)
			for (c = 1;c <= 100;c++)
				if ((a* a + b * b == c * c) && (a<b) && (b<c))
					printf("%d %d %d\n", a, b, c);

	return 0;
}
// �� �ֻ����� ���� ���� 10�� �Ǵ� ���α׷�
int p19()
{
	int a, b, c;
	
	for (a = 1;a <= 6;a++)
		for (b = 1;b <= 6;b++)
			for (c = 1;c <= 6;c++)
				if ((a + b + c == 10) && (a < b))
					printf("%d %d %d\n", a, b, c);
	return 0;
}

#define SEED_MONEY 1000000
// p.298 ����ũ ��� ���α׷� break�� ���
int p20()
{
	int year = 0;
	int money = SEED_MONEY;

	while (1)
	{
		money += SEED_MONEY * 0.30;
		year++;
		if (money >= SEED_MONEY * 10)
			break;
	}
	printf("%��\n\n", year);
	return 0;
}

// p.300 continue�� ����ϱ�
int p21() {
	int n;
	
	for (int i = 0;i <= 10;i++)
	{
		if (i % 3 == 0)
			continue;
		printf("%d ", i);
	}
	return 0;
}
// p. 310 �ҹ��ڸ� �빮�ڷ� �ٲٱ�
int p22()
{
	char letter;
	while (1)
	{
		printf("�ҹ��ڸ� �Է��Ͻÿ�: ");
		scanf_s(" %c", &letter);
		if (letter == 'Q')
			break;
		if (letter < 'a' || letter>'z')
			continue;
		letter -= 32;
		printf("�ش� �ҹ��ڴ� �빮�ڷ� %c �Դϴ�.\n\n", letter);
	}
	return 0;
}

//p.304 ���� ��ģ���� ���α׷�
int p23()
{
	srand((unsigned)time(NULL));

	int x, y, guess, ans;
	char opc=0;
	int op;
	for (int i = 0;i < 10;i++) {
		
		op = rand() % 4 + 1;
		x = rand() % 10;
		y = rand() % 10;

		switch (op) {
		case 1: opc = '+'; ans = x + y; break;
		case 2:opc = '-';ans = x - y;break;
		case 3: opc = '*';ans = x * y;break;
		case 4:opc = '/';ans = x / y;break;
		}

		printf("%d %c %d = ", x, opc, y);
		scanf_s("%d", &guess);
		while (guess != ans)
		{
			printf("Ʋ�Ƚ��ϴ�. �ٽ� �õ��ϼ���.\n\n");
			printf("%d %c %d = ", x, opc, y);
			scanf_s("%d", &guess);
		}
		printf("�¾ҽ��ϴ�.\n");
	
	}
	return 0;
}
#include <time.h>
#include <stdlib.h>

// p.305 while��, break�� ��� ���� ����
#define INITIAL 50
int p24(){

	srand((unsigned)time(NULL));
	int money = INITIAL;
	int result;

	int n = 1;
	while (n <= 50) {
		result = rand() % 2;
		n++;
		if (result == 1)
			money++;
		else
			money--;
		if (money >= 250)
			break;
	}
	printf("100���� %d�� ���� 250�޷��� �޼��߽��ϴ�.\n\n", n);
	return 0;
}