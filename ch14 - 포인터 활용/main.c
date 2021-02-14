#include <stdio.h>
#include <math.h>

int main(void) {
	//p1();
	//p2();
	//p3();
	//p4(); // �� ���� �� ���ϱ�
	//p5(); //��ü ������ �� ���ϱ�
	//p6(); // programming #1-9
	//p7();
	//p8();
	//p9();
	//p10();
	p11();

	return 0;
}

int p1() {
	int a[3] = { 1,2,3 };
	int* p;
	int(*pa)[3];
	p = a;
	pa = &a;

	for (int i = 0;i < 3;i++) {
		printf("p=a : %d %p\n", p[i], &p[i]);
		printf("pa=&a : %d %p\n", (*pa)[i], &((*pa)[i]));
	}
}

int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
void menu() {
	printf(" 0. ���� \n 1. ���� \n 2. ���� \n 3. ������ \n 4. ����\n");
}
int p2() {
	int choice, result, x, y;
	menu();

	int (*pf[4])(int, int) = { add, sub, mul,div };
	while (1) {
		printf("�޴��� �����Ͻÿ�: ");
		scanf_s("%d", &choice);
		
		if (choice < 0 || choice >= 4)break;
		printf("�� ���� �Է��Ͻÿ�: ");
		scanf_s("%d %d", &x, &y);

		result = pf[choice](x, y);
		printf("���� ��� : %d\n", result);
	}
}

double f1(double);
double f2(double);
double formula(double (*pf)(double), int n);
int p3() {
	int n;
	printf("���� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	printf("%f\n", formula(f1, n));
	printf("%f\n", formula(f2, n));
}
double formula(double (*pf)(double), int n) {
	double sum = 0.0;
	for (int i = 1;i < n;i++) {
		sum += pf(i) * pf(i) + pf(i) + 1;
	}
	return sum;
}
double f1(double k) {
	return cos(k);
}
double f2(double k) {
	return 1.0 / k;
}


#define ROWS 4
#define COLS 3
int p4() {
	int n;
	int m[ROWS][COLS] = { {10,10,10},{20,20,20}, {30,30,30},{40,40,40} };

	printf("�� ��ȣ �Է�: ");
	scanf_s("%d", &n);
	int* p = &m[n][0];
	int* endp = &m[n][COLS - 1];
	int sum = 0;

	while (p <= endp)
		sum += *p++;
	printf("%d���� ���� %d\n", n,sum);
 }

int p5() {
	int m[ROWS][COLS] = { {10,10,10},{20,20,20}, {30,30,30},{40,40,40} };
;
	int* p = &m[0][0];
	int* endp = &m[ROWS-1][COLS - 1];
	int sum = 0;

	while (p <= endp)
		sum += *p++;
	printf("���� %d\n", sum);
}

void set_proverb(char** q, int n) // �Ű����� ������ ���������� q(���ڿ��� �ּҰ�) �� ������ ���� n�� ���´�
{
	static char* array[3] = {
		"A bad shearer never had a good nickle.",
		"A bad worman (always) blaems his tools.",
		"A bad thing never dies."
	};
	*q = array[n]; // ���������� q�� ����Ű�� ��(������)�� �μ��� ���� n�� �ش��ϴ� array[n] ���ڿ��� ����
}
int p6() {
	int n;
	printf("�� ��° �Ӵ��� ����? ");
	scanf_s("%d", &n);
	char* s;
	set_proverb(&s, n); // �������� �ּ�(���������Ͱ�)�� �ѱ��
	printf("selected proverb = %s\n", s);
}

int get_sum(int array[], int size) {
	int sum = 0;
	for (int i = 0;i < size;i++)
		sum += array[i];
	return sum;
}
int p7() {
	int array[3][6] = { {10,10,10,10,10,10}, {10,10,10,10,10,10}, {10,10,10,10,10,10} };
	int total_sum = 0, sum = 0;

	for (int i = 0;i < 3;i++) {
		sum = get_sum(array[i], 6);
		printf("%d���� ��: %d\n", i, sum);
		total_sum += sum;
	}
	printf("������ ��= %d\n", total_sum);
}

double get_average(int list[], int n) {
	double sum = 0.0;
	for (int i = 0;i < n;i++)
		sum += list[i];
	return sum;
}
int p8() {
	int scores[3][4] = { {100,100,100,100},{90,90,90,90},{80,30,75,80} };

	for (int i = 0;i < 3;i++) {
		double sum = get_average(scores[i], 4);
		printf("%d���� ��հ� = %f\n",i, sum / 4.0);
	}
}

void ptr_str_array(char** dp, int n) {
	static char* array[3] = {
		"A bad shearer never had a good nickle.",
		"A bad worman (always) blaems his tools.",
		"A bad thing never dies."
	};
	*dp = array[n];
}
int p9() {
	char* s;
	for (int i = 0;i < 3;i++) {
		ptr_str_array(&s, i);
		printf("%s\n", s);
	}
}

void set_max_ptr(int m[], int size, int **p) {
	*p = m[0];
	int index=0;

	for (int i = 1;i < size;i++)
		if (m[i] > * p) {
			*p = m[i];
			index = i;
		}
	printf("���� ū ���� %d, �ε��� ���� %d\n", *p, index);
}
int p10() {
	int m[6] = { 5,6,1,3,7,9 };
	int* pmax;

	set_max_ptr(m, 6, &pmax);
	printf("���� ū ���� %d\n",pmax);
}

void sort_strings(char* s[], int size) {
	char* temp;
	int least;

	for (int i = 0;i < size - 1;i++) {
		least = i;
		for (int j = i + 1;j < size;j++)
			if (strcmp((s[j]), s[least]) < 0)
				least = j;
		temp = s[i];
		s[i] = s[least];
		s[least] = temp;
	}
}
int p11() {
	char* s[8] = {"hello", "b", "my","name", "is", "a","yebin", "lee"};
	printf("������ \n\n");
	for (int i = 0;i < 8;i++)
		printf("%s\n", s[i]);
	printf("\n���� ����\n\n");
	sort_strings(&s, 8);
	for (int i = 0;i < 8;i++)
		printf("%s\n", s[i]);
}