#include <stdio.h>

int main(void) {
	p1(); // 포인터 전위, 후위 연산자 
	p2(); // 함수와 포인터
	p3(); // 함수의 매개변수로써의 포인터/배열
	p4(); // 직원의 월급과 보너스를 난수로 생성하여 배열(포인터)에 저장하고, 두 배열의 합으로 새로운 배열 생성 & 탐색
	p5(); // 두 배열 이어 붙인 후 정렬

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
	printf("두 정수 입력: ");
	scanf_s("%d %d", &x, &y);

	get_sum_diff(x, y, &sum, &diff);
	printf("원소들의 합=  %d\n", sum);
	printf("원소들의 차 = %d\n\n", diff);
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
	printf("검색하고 싶은 봉급? : ");
	scanf_s("%d", &n);
	printf("월급이 %d만원인 사람의 인덱스 = %d\n", n, search(A,10,n));

	array_print(B, 10);
	array_add(A, B, C, 10);	
	array_print(C, 10);

	printf("봉급의 합은 %d, 보너스의 합은 %d, 총 액수는 %d\n\n", array_sum(A, 10), array_sum(B, 10), array_sum(C, 10));
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
