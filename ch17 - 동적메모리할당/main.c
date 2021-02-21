#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student{
	char name[10];
	int num1, num2;
}STU;

int main(void) {
	//p1(); // malloc사용하기 p.747
	//p2(); // 문자열을 위한 메모리 동적 할당 p,749-50
	// p3(); // 자기참조 구조체
	//p4(); // 동적 구조체 배열
	//p5(); // programming #1-7
	//p6();
	//p7();
	//p8();
	//p9();
	//p10();

	return 0;
}

int p1() {
	int* scores = NULL;
	int n;
	printf("학생의 수 :");
	scanf_s("%d", &n);

	scores = (int*)malloc(n * sizeof(int));
	if (scores == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}

	printf("================\n");
	for (int i = 0;i < n;i++) {
		printf("학생 #%d 성적 : ", i + 1);
		scanf_s("%d", &scores[i]);
	}
	printf("================\n");

	for (int i = 0;i < n;i++)
		printf("학생 #%d 성적 : %d\n",i+1, scores[i]);
	free(scores);
}

int p2() {
	int n;
	char* arr[10];
	printf("몇개의 문자열을 입력하시겠습니까? :");
	scanf_s("%d", &n);
	getchar();

	for (int i = 0;i < n;i++) {
		arr[i] = (char*)malloc(sizeof(char) * 100);
		if (arr[i] == NULL) {
			printf("동적 메모리 할당 실패\n");
			exit(1);
		}
		strcpy_s(arr[i], 100, "test string");
	}
	for (int i = 0;i < n;i++)
		printf("문자열 %d : %s\n", i, arr[i]);
	free(arr);
}

#define SIZE 50
typedef struct BOOK {
	char title[SIZE];
	int year;
	struct BOOK* link;
}BOOK;
int p3() {
	BOOK* list=NULL, *p, *prev=NULL, *next;
	char buffer[SIZE];
	int year;

	while (1) {
		printf("책 제목 입력하시오(종료는 엔터): ");
		gets_s(buffer, SIZE);
		if (buffer[0] == NULL) break;
		printf("출판 연도를 입력하시오: ");
		scanf_s("%d", &year);
		getchar();

		p = (BOOK*)malloc(sizeof(BOOK));
		strcpy_s(p->title, SIZE, buffer);
		p->year = year;

		if (list == NULL)list = p;
		else prev->link = p;
		p->link = NULL;
		prev = p;
	}

	p = list;
	while (p != NULL) {
		printf("[ %s %d ] -> ", p->title, p->year);
		p = p->link;
	}

	p = list;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}
 }

typedef struct {
	char name[SIZE];
	double rating;
}MOVIE;
int p4() {
	FILE* fp;
	int size;
	char fname[SIZE];
	
	printf("파일 이름을 입력하시오: ");
	gets_s(fname, SIZE);
	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	printf("몇 편이나 저장하시겠습니까? ");
	scanf_s("%d", &size);
	getchar();
	MOVIE* movies = (MOVIE*)malloc(sizeof(MOVIE) * size);
	if (movies == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}

	for (int i = 0;i < size;i++) {
		printf("영화 제목: ");
		gets_s(movies[i].name, SIZE);
		printf("영화 평점: ");
		scanf_s("%lf", &movies[i].rating);
		getchar();
		fprintf(fp, " %s %f", movies[i].name, movies[i].rating);
	}
	fclose(fp);

	fopen_s(&fp, fname, "rt");

	MOVIE m;

	printf("===================\n");
	printf("제목\t평점\n");
	printf("===================\n");
	while (!feof(fp)) {
		fscanf_s(fp, " %s %lf", m.name, SIZE, &m.rating);
		printf("%s\t%f\n", m.name, m.rating);
	}
	printf("===================\n");
	
	free(movies);
	fclose(fp);
}

int p5() {
	int size;
	int* n=NULL;
	int sum = 0;

	printf("정수의 개수 : ");
	scanf_s("%d", &size);
	n = (int*)malloc(sizeof(int) * size);

	for (int i = 0;i < size;i++) {
		printf("양의 정수를 입력하시오: ");
		scanf_s("%d", &n[i]);
		sum += n[i];
	}
	printf("합은 %d입니다.\n", sum);
}

int p6() {
	char**arr=NULL;
	int size;
	printf("문자열의 개수: ");
	scanf_s("%d", &size);
	getchar();

	arr = (char*)malloc(sizeof(char*)*size); // 이중 포인터 size 개수 만큼 할당 (arr[i]를 가리킬 주소)
	if (arr == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	for (int i = 0;i < size;i++) {
		arr[i] = (char*)malloc(sizeof(char) * 100); // 포인터 (char형 공간 100) 할당(*arr[i]:문자열을 가리킬 주소)
		if (arr[i] == NULL) {
			printf("동적 메모리 할당 오류\n");
			exit(1);
		}
		printf("문자열을 입력하시오: ");
		gets(arr[i]);
	}
	for (int i = 0;i < size;i++) {
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}

typedef struct phone {
	char name[10];
	char tel[20];
	struct phone* link;
}PHONE;
int p7() {
	int n;
	PHONE* p;

	printf("주소의 개수: ");
	scanf_s("%d", &n);
	getchar();
	p = (PHONE*)malloc(sizeof(PHONE) * n);

	for (int i = 0;i < n;i++) {
		printf("이름을 입력하시오: ");
		gets(p[i].name);
		printf("번호를 입력하시오: ");
		gets(p[i].tel);
		printf("\n");
	}

	printf("=========================\n");
	printf("이름\t\t전화번호\n");
	printf("=========================\n");
	for (int i = 0;i < n;i++)
		printf("%s\t%s\n", p[i].name, p[i].tel);
	printf("=========================\n");
	free(p);

}
char* get_word() {
	char* p = malloc(sizeof(char) * 50);
	if (p == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	printf("단어를 입력하시오(최대 50글자): ");
	gets(p);
	return p;
}
int p8() {
	char* p = get_word();
	printf("동적 메모리에 저장된 단어는 %s입니다.\n", p);
	free(p);
}

struct NODE {
	int n;
	struct NODE* link;
};
int p9() {
	struct NODE* list = NULL, * p, * prev=NULL, * next;
	int num;

	while (1) {
		printf("양의 정수를 입력하시오(종료는 -1): ");
		scanf_s("%d", &num);
		getchar();
		if (num == -1)break;
		

		p = (struct NODE*)malloc(sizeof(struct NODE));
		if (p == NULL) {
			printf("동적 메모리 할당 오류\n");
			exit(1);
		}
		p->n = num;

		if (list == NULL) list = p;
		else prev->link = p;
		p->link = NULL;
		prev = p;
	}

	p = list;
	while (p != NULL) {
		printf("%d->",p->n);
		p = p->link;
	}
	printf("NULL\n");

	p = list;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}
}

enum choice{RESET=1, ADD, SEARCH, CHANGE, PRINT, EXIT};
PHONE* reset(PHONE* list);
PHONE* add(PHONE* list);
void search(PHONE* list);
PHONE* change(PHONE* list);
void print(PHONE* list);
void menu_();

PHONE* list = NULL;
int p10() {
	menu_();
	enum choice choice;

	while (1) {
		printf("번호를 입력하시오: ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice) {
		case RESET:list=reset(list);break;
		case ADD:list=add(list);break;
		case SEARCH:search(list);break;
		case CHANGE:list=change(list);break;
		case PRINT:print(list);break;
		case EXIT:return 0;
		}
	}
}
void menu_() {
	printf("연결 리스트를 이용한 전화 번호부 메뉴\n");
	printf("-------------------------\n");
	printf("1. 초기화\n2. 전화 번호 추가\n3. 전화 번호 탐색\n4. 전화 번호 변경\n5. 번호 목록 출력\n6. 종료\n");
	printf("-------------------------\n");
}
PHONE* reset(PHONE* list) {
	PHONE* p, * next;

	p = list;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}
	list= NULL;
	printf("\n전화 번호부를 성공적으로 초기화하였습니다.\n\n");

	return list;
}
PHONE* add(PHONE* list) {
	PHONE* new = (PHONE*)malloc(sizeof(PHONE));
	
	if (new == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}

	printf("이름 : "); gets(new->name);
	printf("번호 : ");gets(new->tel);

	if (list == NULL) {
		new->link = NULL;
		list= new; 
	}
	else {
		new->link=list->link;
		list->link = new;
	}
	printf("\n%s가 목록에 성공적으로 추가되었습니다.\n\n", new->name);

	return list;
}
void search(PHONE* list) {
	int check = 0;
	char name[10];
	printf("탐색할 이름 : "); gets_s(name,10);

	PHONE* p=list;
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			printf("%s의 번호 : %s\n", name, p->tel);
			check = 1;
			break;
		}
		p = p->link;
	}
	if (check == 0) printf("\n목록에서 %s 탐색 실패\n\n", name);

}
PHONE* change(PHONE* list) {
	PHONE* change = (PHONE*)malloc(sizeof(PHONE));
	int check = 0;
	
	printf("탐색할 이름 : "); gets(change->name);
	printf("변경할 번호 : "); gets(change->tel);

	PHONE* p = list, * prev = NULL;
	while (p != NULL) {
		if (strcmp(p->name, change->name) == 0) {
			if (p == list) {
				change->link = p->link;
				list = change;
			}
			else {
				change->link = p->link;
				prev->link = change;
			}
			printf("\n%s의 번호는 %s에서 %s로 변경되었습니다.\n\n", change->name, p->tel, change->tel);
			check = 1;
			free(p);
			break;
		}
		prev = p;
		p = p->link;
		}
	if (check == 0) printf("\n목록에서 %s 탐색 실패\n\n", change->name);

	return list;
}
void print(PHONE* list) {
	PHONE* p=NULL;
	int n = 0, check = 0;

	p = list;
	if (list != NULL) {
		check = 1;
		while (p != NULL) {
			printf("< %d번 >\n", ++n);
			printf("이름: %s, 번호 : %s\n", p->name, p->tel);
			p = p->link;
		}
	}

	if (check == 1)printf("\n목록을 성공적으로 출력하였음\n\n");
	else printf("목록에 저장된 번호가 없음\n\n");
}
