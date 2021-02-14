#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIG(x,y) x>y?x:y
#define MAX(x,y,z) (BIG(x,y) > z ? BIG(x,y) : z)
int mystery(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if (*s1 == 0) return 5;
		printf("%s %s\n", s1++, s2++);
	}
	return(1);
}
typedef struct student{
	char name[10];
	int num1, num2;
}STU;
enum color{white, red=3, blue, black=9};
int main(void) {
	//p1(); // malloc����ϱ� p.747
	//p2(); // ���ڿ��� ���� �޸� ���� �Ҵ� p,749-50
	// p3(); // �ڱ����� ����ü
	//p4(); // ���� ����ü �迭
	//p5(); // programming #1-7
	//p6();
	//p7();
	//p8();
	//p9();
	//p10();
	/*
	STU list[3] = { {"KIM",1,2},{"KIMMM", 3,4},{"LEE", 5,6 } };
	STU* p = list;

	printf("%d\n", mystery(list[0].name, list[1].name));
	*/
	int x, y, z;
	printf("�� ���� �Է� : ");
	scanf_s("%d %d %d", &x, &y, &z);
	printf("�ִ밪�� %d\n", MAX(x, y, z));

	enum color c;
	int s = 4;
	switch (s) {
	case white:printf("white\n");break;
	case red:printf("red\n");break;
	case blue:printf("blue\n");break;
	case black:printf("black\n");break;
	default:printf("����\n");break;
	}

	return 0;
}

int p1() {
	int* scores = NULL;
	int n;
	printf("�л��� �� :");
	scanf_s("%d", &n);

	scores = (int*)malloc(n * sizeof(int));
	if (scores == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}

	printf("================\n");
	for (int i = 0;i < n;i++) {
		printf("�л� #%d ���� : ", i + 1);
		scanf_s("%d", &scores[i]);
	}
	printf("================\n");

	for (int i = 0;i < n;i++)
		printf("�л� #%d ���� : %d\n",i+1, scores[i]);
	free(scores);
}

int p2() {
	int n;
	char* arr[10];
	printf("��� ���ڿ��� �Է��Ͻðڽ��ϱ�? :");
	scanf_s("%d", &n);
	getchar();

	for (int i = 0;i < n;i++) {
		arr[i] = (char*)malloc(sizeof(char) * 100);
		if (arr[i] == NULL) {
			printf("���� �޸� �Ҵ� ����\n");
			exit(1);
		}
		strcpy_s(arr[i], 100, "test string");
	}
	for (int i = 0;i < n;i++)
		printf("���ڿ� %d : %s\n", i, arr[i]);
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
		printf("å ���� �Է��Ͻÿ�(����� ����): ");
		gets_s(buffer, SIZE);
		if (buffer[0] == NULL) break;
		printf("���� ������ �Է��Ͻÿ�: ");
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
	
	printf("���� �̸��� �Է��Ͻÿ�: ");
	gets_s(fname, SIZE);
	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "������ �� �� ����\n");
		exit(1);
	}

	printf("�� ���̳� �����Ͻðڽ��ϱ�? ");
	scanf_s("%d", &size);
	getchar();
	MOVIE* movies = (MOVIE*)malloc(sizeof(MOVIE) * size);
	if (movies == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}

	for (int i = 0;i < size;i++) {
		printf("��ȭ ����: ");
		gets_s(movies[i].name, SIZE);
		printf("��ȭ ����: ");
		scanf_s("%lf", &movies[i].rating);
		getchar();
		fprintf(fp, " %s %f", movies[i].name, movies[i].rating);
	}
	fclose(fp);

	fopen_s(&fp, fname, "rt");

	MOVIE m;

	printf("===================\n");
	printf("����\t����\n");
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

	printf("������ ���� : ");
	scanf_s("%d", &size);
	n = (int*)malloc(sizeof(int) * size);

	for (int i = 0;i < size;i++) {
		printf("���� ������ �Է��Ͻÿ�: ");
		scanf_s("%d", &n[i]);
		sum += n[i];
	}
	printf("���� %d�Դϴ�.\n", sum);
}

int p6() {
	char**arr=NULL;
	int size;
	printf("���ڿ��� ����: ");
	scanf_s("%d", &size);
	getchar();

	arr = (char*)malloc(sizeof(char*)*size); // ���� ������ size ���� ��ŭ �Ҵ� (arr[i]�� ����ų �ּ�)
	if (arr == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	for (int i = 0;i < size;i++) {
		arr[i] = (char*)malloc(sizeof(char) * 100); // ������ (char�� ���� 100) �Ҵ�(*arr[i]:���ڿ��� ����ų �ּ�)
		if (arr[i] == NULL) {
			printf("���� �޸� �Ҵ� ����\n");
			exit(1);
		}
		printf("���ڿ��� �Է��Ͻÿ�: ");
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

	printf("�ּ��� ����: ");
	scanf_s("%d", &n);
	getchar();
	p = (PHONE*)malloc(sizeof(PHONE) * n);

	for (int i = 0;i < n;i++) {
		printf("�̸��� �Է��Ͻÿ�: ");
		gets(p[i].name);
		printf("��ȣ�� �Է��Ͻÿ�: ");
		gets(p[i].tel);
		printf("\n");
	}

	printf("=========================\n");
	printf("�̸�\t\t��ȭ��ȣ\n");
	printf("=========================\n");
	for (int i = 0;i < n;i++)
		printf("%s\t%s\n", p[i].name, p[i].tel);
	printf("=========================\n");
	free(p);

}
char* get_word() {
	char* p = malloc(sizeof(char) * 50);
	if (p == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	printf("�ܾ �Է��Ͻÿ�(�ִ� 50����): ");
	gets(p);
	return p;
}
int p8() {
	char* p = get_word();
	printf("���� �޸𸮿� ����� �ܾ�� %s�Դϴ�.\n", p);
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
		printf("���� ������ �Է��Ͻÿ�(����� -1): ");
		scanf_s("%d", &num);
		getchar();
		if (num == -1)break;
		

		p = (struct NODE*)malloc(sizeof(struct NODE));
		if (p == NULL) {
			printf("���� �޸� �Ҵ� ����\n");
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
		printf("��ȣ�� �Է��Ͻÿ�: ");
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
	printf("���� ����Ʈ�� �̿��� ��ȭ ��ȣ�� �޴�\n");
	printf("-------------------------\n");
	printf("1. �ʱ�ȭ\n2. ��ȭ ��ȣ �߰�\n3. ��ȭ ��ȣ Ž��\n4. ��ȭ ��ȣ ����\n5. ��ȣ ��� ���\n6. ����\n");
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
	printf("\n��ȭ ��ȣ�θ� ���������� �ʱ�ȭ�Ͽ����ϴ�.\n\n");

	return list;
}
PHONE* add(PHONE* list) {
	PHONE* new = (PHONE*)malloc(sizeof(PHONE));
	
	if (new == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}

	printf("�̸� : "); gets(new->name);
	printf("��ȣ : ");gets(new->tel);

	if (list == NULL) {
		new->link = NULL;
		list= new; 
	}
	else {
		new->link=list->link;
		list->link = new;
	}
	printf("\n%s�� ��Ͽ� ���������� �߰��Ǿ����ϴ�.\n\n", new->name);

	return list;
}
void search(PHONE* list) {
	int check = 0;
	char name[10];
	printf("Ž���� �̸� : "); gets_s(name,10);

	PHONE* p=list;
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			printf("%s�� ��ȣ : %s\n", name, p->tel);
			check = 1;
			break;
		}
		p = p->link;
	}
	if (check == 0) printf("\n��Ͽ��� %s Ž�� ����\n\n", name);

}
PHONE* change(PHONE* list) {
	PHONE* change = (PHONE*)malloc(sizeof(PHONE));
	int check = 0;
	
	printf("Ž���� �̸� : "); gets(change->name);
	printf("������ ��ȣ : "); gets(change->tel);

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
			printf("\n%s�� ��ȣ�� %s���� %s�� ����Ǿ����ϴ�.\n\n", change->name, p->tel, change->tel);
			check = 1;
			free(p);
			break;
		}
		prev = p;
		p = p->link;
		}
	if (check == 0) printf("\n��Ͽ��� %s Ž�� ����\n\n", change->name);

	return list;
}
void print(PHONE* list) {
	PHONE* p=NULL;
	int n = 0, check = 0;

	p = list;
	if (list != NULL) {
		check = 1;
		while (p != NULL) {
			printf("< %d�� >\n", ++n);
			printf("�̸�: %s, ��ȣ : %s\n", p->name, p->tel);
			p = p->link;
		}
	}

	if (check == 1)printf("\n����� ���������� ����Ͽ���\n\n");
	else printf("��Ͽ� ����� ��ȣ�� ����\n\n");
}