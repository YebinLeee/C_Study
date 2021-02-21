#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	//p1();
	//p2();
	//p3();
	//p4();
	//p5();
	//p6();
	//p7();
	p8();
	
	return 0;
}
int p1(){
	int* list;
	list = (int*)malloc(3 * sizeof(int));
	if (list == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	list[0] = 10;list[1] = 20;list[2] = 30;
	printf("%d %d %d", list[0], list[1], list[2]);
	free(list);
}

int p2() {
	int* list;
	int i, students;
	printf("학생의 수: ");
	scanf_s("%d", &students);
	list = (int*)malloc(students * sizeof(int));
	
	if (list == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	for (i = 0;i < students;i++) {
		printf("학생 #%d성적: ", i + 1);
		scanf_s("%d", &list[i]);
	}
	
	printf("=====================\n");
	for (i = 0;i < students;i++)
		printf("학생 #%d 성적: %d\n", i + 1, list[i]);
	printf("=====================\n");
	free(list);
}

struct Book {
	int number;
	char title[50];};
int p3() {
	struct Book* p;
	p = (struct Book*)malloc(2 * sizeof(struct Book));
	if (p == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	p[0].number = 1;
	strcpy_s(p[0].title, 50, "C Programming");
	p[1].number = 2;
	strcpy_s(p[1].title, 50, "Data Structure");
	printf("%d, %s", p[0].number, p[0].title);
	free(p);
}

int p4() {
	char* list[10]; // 10개의 char형 배열 포인터 변수 선언(동적 메모리 할당도 10번 실행됨)
	for (int i = 0;i < 10;i++) {
		list[i] = (char*)malloc(100 * sizeof(char));
		// 각 문자열의 최대 길이는 100이다.
		if (list[i] == NULL) {
			printf("malloc() 실패!\n\n");
			exit(1);
		}
		strcpy_s(list[i], 12, "test string");
	}
	for (int i = 0;i < 10;i++)
		printf("문자열 %d: %s\n", i, list[i]);

	/*
	for (int i = 0;i < 10;i++)
		free(list[i]); // 각각 동적 메모리에 대해 반납을 해주어야함
		*/
}

int p5() {
	printf("정수 2개를 저장할 공간이 필요\n");
	int* list = (int*)malloc(sizeof(int) * 2);
	int* list_new;
	list[0] = 10;
	list[1] = 20;

	printf("정수 3개를 저장할 공간으로 확장\n");
	list_new = (int*)realloc(list, sizeof(int) * 3);
	list_new[2] = 30;
	for (int i = 0;i < 3;i++)
		printf("%d ", list_new[i]);
	printf("\n");
	free(list_new);
}
#define SIZE 50
typedef struct NODE {
	char title[SIZE];
	int year;
	struct NODE* link; // 다음번 노드를 가리키기 위한 포인터 변수(자기 참조 멤버 변수)
}NODE;
int p6() {
	// 동적 메모리 할당. linked list연결리스트. 정보가 얼마나 들어올지 모를 때
	NODE* list = NULL; // 노드를 만들어 대입할 포인터
	NODE* prev = NULL;
	NODE* p = NULL;
	NODE* next = NULL; // NULL로 초기화 꼭
	char buffer[SIZE]; // 책 제목을 저장할 임시 문자열 변수 선언
	int year;

	while (1) {
		printf("책의 제목을 입력하시오(종료는 엔터): ");
		gets_s(buffer, SIZE);
		if (buffer[0] == '\0') break; // 엔터값이 들어오는 경우(get_s()함수에서 엔터는 NULL값으로 처리)
		p = (NODE*)malloc(sizeof(NODE)); // 현재 NODE값을 가리키는 포인터 변수
		strcpy_s(p->title,SIZE,buffer); // buffer에 저장해 두었던 것을 (*p).title에 저장
		
		printf("책의 출판연도를 입력하시오: ");
		gets_s(buffer, SIZE);
		year = atoi(buffer);
		p->year = year;

		if (list == NULL) list = p;
		else prev->link = p;
		p->link = NULL;
		prev = p;
	}
	printf("\n");
	
	p = list;
	while (p != NULL) {
		printf
		("[%s %d]->", p->title, p->year);
		p = p->link;
	}
	printf("\n");

	p = list;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}
}

int p7() {
	int* p;
	int num, sum = 0;

	printf("정수의 개수: ");
	scanf_s("%d", &num);

	p = (int*)malloc(num * sizeof(int));
	for (int i = 0;i < num;i++) {
		printf("양의 정수를 입력하시오: ");
		scanf_s("%d", &p[i]);
		sum += p[i];
	}
	printf("합은 %d입니다.\n", sum);
	free(p);
}

typedef struct PHONE {
	char name[SIZE];
	char phone[SIZE];
	struct PHONE* link;
}PHONE;
int p8() {
	PHONE* list=NULL;
	int num;

	printf("주소의 개수: ");
	scanf_s("%d", &num);
	getchar();

	list = (struct PHONE*)malloc(sizeof(struct PHONE) * num);
	if (list == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	for (int i = 0;i < num;i++) {
		printf("이름을 입력하시오: ");
		gets_s(list[i].name, SIZE);
		printf("휴대폰 번호를 입력하시오: ");
		gets_s(list[i].phone, SIZE);
	}
	printf("======================\n");
	printf("이름\t휴대폰 번호\n");
	printf("====================\n");
	for (int i = 0;i < num;i++)
		printf("%-6s %s\n", list[i].name, list[i].phone);
	printf("======================\n");
	free(list);
}