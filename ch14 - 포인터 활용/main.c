#include <stdio.h>
#include <math.h>

int main(void) {
	//p1();
	//p2();
	//p3();
	//p4(); // 한 행의 합 구하기
	//p5(); //전체 원소의 합 구하기
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
	printf(" 0. 덧셈 \n 1. 뺄셈 \n 2. 곱셈 \n 3. 나눗셈 \n 4. 종료\n");
}
int p2() {
	int choice, result, x, y;
	menu();

	int (*pf[4])(int, int) = { add, sub, mul,div };
	while (1) {
		printf("메뉴를 선택하시오: ");
		scanf_s("%d", &choice);
		
		if (choice < 0 || choice >= 4)break;
		printf("두 수를 입력하시오: ");
		scanf_s("%d %d", &x, &y);

		result = pf[choice](x, y);
		printf("연산 결과 : %d\n", result);
	}
}

double f1(double);
double f2(double);
double formula(double (*pf)(double), int n);
int p3() {
	int n;
	printf("수를 입력하시오: ");
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

	printf("행 번호 입력: ");
	scanf_s("%d", &n);
	int* p = &m[n][0];
	int* endp = &m[n][COLS - 1];
	int sum = 0;

	while (p <= endp)
		sum += *p++;
	printf("%d행의 합은 %d\n", n,sum);
 }

int p5() {
	int m[ROWS][COLS] = { {10,10,10},{20,20,20}, {30,30,30},{40,40,40} };
;
	int* p = &m[0][0];
	int* endp = &m[ROWS-1][COLS - 1];
	int sum = 0;

	while (p <= endp)
		sum += *p++;
	printf("합은 %d\n", sum);
}

void set_proverb(char** q, int n) // 매개변수 값으로 이중포인터 q(문자열의 주소값) 과 정수형 변수 n을 갖는다
{
	static char* array[3] = {
		"A bad shearer never had a good nickle.",
		"A bad worman (always) blaems his tools.",
		"A bad thing never dies."
	};
	*q = array[n]; // 이중포인터 q가 가리키는 값(포인터)에 인수로 받은 n에 해당하는 array[n] 문자열을 대입
}
int p6() {
	int n;
	printf("몇 번째 속담을 선택? ");
	scanf_s("%d", &n);
	char* s;
	set_proverb(&s, n); // 포인터의 주소(이중포인터값)를 넘긴다
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
		printf("%d행의 합: %d\n", i, sum);
		total_sum += sum;
	}
	printf("정수의 합= %d\n", total_sum);
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
		printf("%d행의 평균값 = %f\n",i, sum / 4.0);
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
	printf("가장 큰 값은 %d, 인덱스 값은 %d\n", *p, index);
}
int p10() {
	int m[6] = { 5,6,1,3,7,9 };
	int* pmax;

	set_max_ptr(m, 6, &pmax);
	printf("가장 큰 값은 %d\n",pmax);
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
	printf("정렬전 \n\n");
	for (int i = 0;i < 8;i++)
		printf("%s\n", s[i]);
	printf("\n정렬 이후\n\n");
	sort_strings(&s, 8);
	for (int i = 0;i < 8;i++)
		printf("%s\n", s[i]);
}