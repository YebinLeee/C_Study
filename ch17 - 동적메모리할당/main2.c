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
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	list[0] = 10;list[1] = 20;list[2] = 30;
	printf("%d %d %d", list[0], list[1], list[2]);
	free(list);
}

int p2() {
	int* list;
	int i, students;
	printf("�л��� ��: ");
	scanf_s("%d", &students);
	list = (int*)malloc(students * sizeof(int));
	
	if (list == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	for (i = 0;i < students;i++) {
		printf("�л� #%d����: ", i + 1);
		scanf_s("%d", &list[i]);
	}
	
	printf("=====================\n");
	for (i = 0;i < students;i++)
		printf("�л� #%d ����: %d\n", i + 1, list[i]);
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
		printf("�޸� �Ҵ� ����\n");
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
	char* list[10]; // 10���� char�� �迭 ������ ���� ����(���� �޸� �Ҵ絵 10�� �����)
	for (int i = 0;i < 10;i++) {
		list[i] = (char*)malloc(100 * sizeof(char));
		// �� ���ڿ��� �ִ� ���̴� 100�̴�.
		if (list[i] == NULL) {
			printf("malloc() ����!\n\n");
			exit(1);
		}
		strcpy_s(list[i], 12, "test string");
	}
	for (int i = 0;i < 10;i++)
		printf("���ڿ� %d: %s\n", i, list[i]);

	/*
	for (int i = 0;i < 10;i++)
		free(list[i]); // ���� ���� �޸𸮿� ���� �ݳ��� ���־����
		*/
}

int p5() {
	printf("���� 2���� ������ ������ �ʿ�\n");
	int* list = (int*)malloc(sizeof(int) * 2);
	int* list_new;
	list[0] = 10;
	list[1] = 20;

	printf("���� 3���� ������ �������� Ȯ��\n");
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
	struct NODE* link; // ������ ��带 ����Ű�� ���� ������ ����(�ڱ� ���� ��� ����)
}NODE;
int p6() {
	// ���� �޸� �Ҵ�. linked list���Ḯ��Ʈ. ������ �󸶳� ������ �� ��
	NODE* list = NULL; // ��带 ����� ������ ������
	NODE* prev = NULL;
	NODE* p = NULL;
	NODE* next = NULL; // NULL�� �ʱ�ȭ ��
	char buffer[SIZE]; // å ������ ������ �ӽ� ���ڿ� ���� ����
	int year;

	while (1) {
		printf("å�� ������ �Է��Ͻÿ�(����� ����): ");
		gets_s(buffer, SIZE);
		if (buffer[0] == '\0') break; // ���Ͱ��� ������ ���(get_s()�Լ����� ���ʹ� NULL������ ó��)
		p = (NODE*)malloc(sizeof(NODE)); // ���� NODE���� ����Ű�� ������ ����
		strcpy_s(p->title,SIZE,buffer); // buffer�� ������ �ξ��� ���� (*p).title�� ����
		
		printf("å�� ���ǿ����� �Է��Ͻÿ�: ");
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

	printf("������ ����: ");
	scanf_s("%d", &num);

	p = (int*)malloc(num * sizeof(int));
	for (int i = 0;i < num;i++) {
		printf("���� ������ �Է��Ͻÿ�: ");
		scanf_s("%d", &p[i]);
		sum += p[i];
	}
	printf("���� %d�Դϴ�.\n", sum);
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

	printf("�ּ��� ����: ");
	scanf_s("%d", &num);
	getchar();

	list = (struct PHONE*)malloc(sizeof(struct PHONE) * num);
	if (list == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	for (int i = 0;i < num;i++) {
		printf("�̸��� �Է��Ͻÿ�: ");
		gets_s(list[i].name, SIZE);
		printf("�޴��� ��ȣ�� �Է��Ͻÿ�: ");
		gets_s(list[i].phone, SIZE);
	}
	printf("======================\n");
	printf("�̸�\t�޴��� ��ȣ\n");
	printf("====================\n");
	for (int i = 0;i < num;i++)
		printf("%-6s %s\n", list[i].name, list[i].phone);
	printf("======================\n");
	free(list);
}