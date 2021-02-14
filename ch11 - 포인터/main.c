#include <stdio.h>
int main(void) {
	//p1();
	p2();
	p3();
	p4();
	p5();

	return 0;
}
int p1() {
	int i = 20;
	int* p = NULL;
	p = &i;

	printf("++i= %d\n", ++i);
	printf("i++ =%d\n", i++);
	printf("p=%d *p=%d\n", p, *p);
	printf("(*p)++= %d\n", (*p)++);
	printf("++(*p) = %d\n", ++(*p));
}

void get_sum_diff(int x, int y, int* p_sum, int *p_diff) {
	*p_sum = x + y;
	*p_diff = x - y;
}
int p2() {
	int sum, diff, x, y;
	printf("�� ���� �Է�: ");
	scanf_s("%d %d", &x, &y);

	get_sum_diff(x, y, &sum, &diff);
	printf("���ҵ��� ��=  %d\n", sum);
	printf("���ҵ��� �� = %d\n\n", diff);
}

void array_fill(int A[], int size) {
	for (int i = 0;i < size;i++)
		*(A + i) = rand();
}
void array_print(int* A, int size) {
	printf("A = [" );
	for (int i = 0;i < size;i++)
		printf("%d ", *(A + i));
	printf("]\n\n");
}
void array_copy(int* A, int* B, int size) {
	for (int i = 0;i < size;i++)
		*(B + i) = *(A + i);
}
int p3() {
	srand((unsigned)time(NULL));
	int arr[10] = { 0 };
	int B[10] = { 0 };
	array_fill(arr, 10);
	array_print(arr, 10);
	array_copy(arr, B, 10);
	array_print(B, 10);
}

void array_add(int A[], int B[], int C[], int size) {
	for (int i = 0;i < size;i++)
		*(C + i) = *(A + i) + *(B + i);
}
int array_sum(int A[], int size) {
	int sum = 0;
	for (int i = 0;i < size;i++)
		sum += *(A + i);
	return sum;
}
int search(int *A, int size, int search) {
	for (int i = 0;i < size;i++)
		if (search == *(A+i)) return i;
	return 0;
}
int p4() {
	srand((unsigned)time(NULL));
	int A[10] = { 0 };
	int B[10] = { 0 };
	int C[10] = { 0 };

	for (int i = 0;i < 10;i++) {
		*(A + i) = rand() % 100;
		*(B + i) = rand() % 10;
	}
	array_print(A, 10);

	int n;
	printf("�˻��ϰ� ���� ����? : ");
	scanf_s("%d", &n);
	printf("������ %d������ ����� �ε��� = %d\n", n, search(A,10,n));

	array_print(B, 10);
	array_add(A, B, C, 10);	
	array_print(C, 10);

	printf("������ ���� %d, ���ʽ��� ���� %d, �� �׼��� %d\n\n", array_sum(A, 10), array_sum(B, 10), array_sum(C, 10));
}

void merge(int A[], int B[], int C[], int size){
	for (int i = 0;i < size;i++)
		*(C + i) = *(A + i);
	for (int i = 0;i < size;i++)
		*(C + i+size) = *(B + i);
	
	int  j, least, tmp;
	for (int i = 0;i < 2 * size - 1;i++) {
		least = i;
		for (j = i + 1;j < 2 * size;j++)
			if (C[least] > C[j]) least = j;
		tmp = C[i];
		C[i] = C[least];
		C[least] = tmp;
	}

}
int p5() {
	int A[4] = { 2,5,7,8 };
	int B[4] = { 1,3,4,6 };
	int C[10] = { 0 };
	array_print(A, 4);
	array_print(B, 4);

	merge(A, B, C, 4);
	array_print(C, 8);
}