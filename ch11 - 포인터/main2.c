#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main() {

	p1();
	p2();
	p3();
	p4();
	p5();
	p6();
	p7();
	p8();

	pro1();
	pro2();
	pro3();
	pro4();
	pro5();
	pro6();
	pro7();
	pro8();

	return 0;
}

int p1()
{
	int i = 10;
	int* pi = &i;

	printf("i = %d, pi = %p\n", i, pi);
	(*pi)++;
	printf("i = %d, pi = %p\n", i, pi);

	printf("i = %d, pi = %p\n", i, pi);
	*pi++;
	printf("i = %d, pi = %p\n", i, pi);

	return 0;
}
void swap(int x, int y)
{
	int tmp;
	printf("x = %d, y = %d\n", x, y);

	tmp = x;
	x = y;
	y = tmp;

	printf("x = %d, y = %d\n", x, y);
}
int p2()
{
	int a = 100, b = 200;
	printf("a = %d, b = %d\n", a, b);

	swap(a, b);

	printf("a = %d, b = %d\n", a, b);
	return 0;
}
void pswap(int* px, int* py)
{
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;
}
int p3()
{
	int a = 100, b = 200;
	printf("a = %d, b = %d\n", a, b);

	pswap(&a, &b);

	printf("a = %d, b = %d\n", a, b);
	return 0;
}
// 두 개 이상의 반환값 설정 가능
int get_line_parameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept)
{
	if (x1 == x2)
		return -1;
	else
	{
		*slope = (float)(y2 - y1) / (float)(x2 - x1);
		*yintercept = y1 - (*slope) * x1;
		return 0;
	}
}
int p4(void)
{
	float s, y;
	if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1)
		printf("에러\n");
	else
		printf("기울기는 %lf, y절편은 %lf\n", s, y);
	return 0;
}
int p5()
{
	int a[] = { 10,20,30,40,50 };
	printf("&a[0] = %u\n", &a[0]);
	printf("a = %u\n", a);
	printf("a + 1 = %u\n", a + 1);
	printf("*a = %d\n", *a);
	printf("*(a+1) = %d\n", *(a + 1));

	return 0;
}
int p6()
{
	int a[] = { 10,20,30,40,50 };
	int* p;
	p = a;

	printf("a[0]=%d, a[1]=%d, a[2]=%d\n", a[0], a[1], a[2]);
	printf("p[0]=%d, p[1]=%d, p[2]=%d\n\n", p[0], p[1], p[2]);

	p[0] = 60, p[1] = 70, p[2] = 80;

	printf("a[0]=%d, a[1]=%d, a[2]=%d\n", a[0], a[1], a[2]);
	printf("p[0]=%d, p[1]=%d, p[2]=%d\n", p[0], p[1], p[2]);
	return 0;
}
void sub(int b[], int n)	// (int *b, int n) 과 같이 포인터를 매개변수로 호출해도 된다.
{
	b[0] = 4, b[1] = 5, b[2] = 6; // *b= 4, *(b+1)=5, *(b+2)=6
}
int p7() {
	int a[3] = { 1,2,3 };

	printf("%d %d %d\n", a[0], a[1], a[2]);
	sub(a, 3);
	printf("%d %d %d\n", a[0], a[1], a[2]);
	return 0;
}
int* add(int x, int y)
{
	int result;
	result = x + y;
	return &result;	// 일반 지역변수의 주소값을 반환해서는 안 된다.
}
int p8()
{
	int a = 5, b = 3, c;
	c = add(a, b);
	printf("a + b = %d\n", c);

	return 0;
}

void get_sum_diff(int x, int y, int* p_sum, int* p_diff)
{
	*p_sum = x + y;
	*p_diff = x - y;

	return 0;
}
int pro1()
{
	int x, y;
	int sum, diff;

	printf("두 개의 정수를 입력하시오: ");
	scanf_s("%d %d", &x, &y);
	
	get_sum_diff(x, y, &sum, &diff);

	printf("원소들의 합 = %d\n", sum);
	printf("원소들의 차 = %d\n\n", diff);

	return 0;
}

void array_fill(int* A, int size)
{
	srand(time(NULL));
	for (int i = 0;i < size;i++) {
		A[i] = rand();
		printf("%d ",A[i]);
	}
}
int pro2()
{
	int a[SIZE] = { 0 };
	array_fill(a, SIZE);
	printf("\n\n");

	return 0;
}

void array_print(int* A, int size) {
	int i;
	printf("A[] = { ");
	for (i = 0;i < size;i++)
		printf("%d ", A[i]);
	printf("}\n\n");
}
int pro3()
{
	srand(time(NULL));
	int a[SIZE] = { 0 };

	for (int i = 0;i < SIZE;i++)
		a[i] = rand() % 100;
	array_print(a, SIZE);
	return 0;
}

void convert(double* grades, double* scores, int size)
{
	for (int i = 0;i < size;i++) {
		scores[i] = grades[i] * 100 / 4.3;
		printf("%08lf ", scores[i]);
	}
	printf("\n\n");
}
int pro4()
{
	srand(time(NULL));
	double grades[SIZE] = { 0 };
	double scores[SIZE] = { 0 };

	printf("학생 10명의 학점(4.3만점): \n");
	for (int i = 0;i < SIZE;i++)
	{
		grades[i] = (rand() % 44) / 10.0;
		printf("%08lf ", grades[i]);
	}
	printf("\n\n");

	printf("학생 10명의 학점변환 결과 (100점만점): \n");
	convert(grades, &scores, SIZE);

	return 0;
}

void array_copy(int* A, int* B, int size)
{
	for (int i = 0;i < size;i++) {
		B[i] = A[i];
		printf("%d ", B[i]);
	}
	printf("\n\n");
}
int pro5()
{
	srand(time(NULL));
	int a[SIZE] = { 0 };
	int b[SIZE] = { 0 };

	for (int i = 0;i < SIZE;i++) {
		a[i] = rand() % 100;
		printf("%d ", a[i]);
	}
	array_copy(a, &b, SIZE);

	return 0;
}

void array_add(int* A, int* B, int* C, int size) {
	
	printf("sum[%d] = ", size);
	for (int i = 0;i < SIZE;i++){
		*(C + i) = *(A + i) + *(B + i);
		printf("%d ", C[i]);
	}
	printf("\n\n");
}
int pro6()
{
	srand(time(NULL));
	int pay[SIZE] = { 0 };
	int bonus[SIZE] = { 0 };
	int sum[SIZE] = { 0 };

	printf("pay[%d] =  ", SIZE);
	for (int i = 0;i < SIZE;i++)
	{
		pay[i] = rand() % 500 + 100;
		printf("%d ", pay[i]);
	}
	printf("\n");

	printf("bonus[%3d] = ", SIZE);
	for (int i = 0;i < SIZE;i++)
	{
		bonus[i] = rand() % 99 + 1;
		printf("%d ", bonus[i]);
	}
	printf("\n");

	array_add(pay, bonus, &sum, SIZE);
	return 0;
}

int array_sum(int* A, int size)
{
	int sum = 0;
	for (int i = 0;i < size;i++)
		sum += A[i];
	return sum;
}
int pro7()
{
	srand(time(NULL));
	int pay[SIZE];
	
	printf("pay[%d] = ", SIZE);
	for (int i = 0;i < SIZE;i++) {
		pay[i] = rand() % 500 + 100;
		printf("%d ", pay[i]);
	}
	printf("\n");
	printf("월급의 합 = %d\n\n", array_sum(pay, SIZE));

	return 0;
}

int search(int* A, int size, int search_value)
{
	int index = 0;
	int result =0 ;

	for (int i = 0;i < size;i++)
		if (A[i] == search_value)
		{
			index = i;
			printf("월급이 200만원인 직원의 인덱스 = %d\n\n", i);
			result = 1;
		}
	if (result ==0)
		printf("200만원에 해당되는 월급을 받는 직원이 없음\n\n");
}
int pro8()
{
	srand(time(NULL));
	int pay[SIZE] = { 0, 200 };
	for (int i = 2;i < SIZE;i++)
		pay[i] = rand() % 500 + 100;
	search(pay, SIZE, 200);

	return 0;
}