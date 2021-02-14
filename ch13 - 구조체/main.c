#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
	//p1(); // p.570 �� �� ������ �Ÿ�
	//p2(); // p.572 ����ü ���� ����ü
	/* p3(); // programming #1-11, 13, 14
	p4();
	p5();
	p6();
	p7();
	p8();
	p9(); */

	/*p10();
	p11();
	p12();*/
	//p13();
	//p14();
	
	char s[20];
	scanf_s("%[^abc]", s,20);
	printf(s);
	return 0;
}

typedef struct {
	int x, y;
}POINT;
int p1() {
	POINT p1, p2;
	int xdiff, ydiff;
	double length;

	printf("���� ��ǥ�� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &p1.x, &p1.y);
	printf("���� ��ǥ�� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &p2.x, &p2.y);

	xdiff = p1.x - p2.x;
	ydiff = p1.y - p2.y;

	length = sqrt((double)(xdiff * xdiff + ydiff * ydiff));
	printf("�Ÿ��� %f�Դϴ�.\n", length);
	
}

typedef struct rect{
	POINT a;
	POINT b;
}RECT;
int p2() {
	RECT rec;
	int w, h;

	printf("���� ����� ��ǥ�� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &rec.a.x, &rec.a.y);
	printf("������ �ϴ��� ��ǥ�� �Է��Ͻÿ� :");
	scanf_s("%d %d", &rec.b.x, &rec.b.y);

	w = rec.b.x - rec.a.x;
	if (w < 0)w = -w;
	h = rec.a.y - rec.b.y;
	if (h < 0)h = -h;

	printf("������ %d�̰� �ѷ��� %d�Դϴ�.\n", w * h, 2*(w + h));
}

struct book {
	int id;
	char title[100];
	char author[20];
};
int p3() {
	struct book b = { 1,"�ٶ��� �Բ� �������", "������ ��ÿ" };
	printf("{ %d, %s, %s }\n", b.id, b.title, b.author);
}

struct account {
	int number;
	char name[20];
	int balance;
};
int p4() {
	struct account ac = { 1, "ȫ�浿", 100000 };
	printf("{ %d, %s, %d }\n", ac.number, ac.name, ac.balance);
}
struct date {
	int year, month, day;
};
struct email {
	char title[20];
	char sender[20];
	char receiver[20];
	char content[50];
	struct date dat;
	int pri;
};
int p5() {
	struct email em = { "�Ⱥ� ����", "chulsoo@hankuk.ac.kr", "hsh@hankuk.ac.kr",
	"�ȳ��Ͻʴϱ�? ���� ����������?", {2020, 12,03},1 };

	printf("���� : %s\n", em.title);
	printf("������: %s\n�߽���: %s\n", em.sender, em.receiver);
	printf("���� : %s\n", em.content);
	printf("��¥ : %d / %d / %d\n", em.dat.year, em.dat.month, em.dat.day);
	printf("�켱���� : %d\n", em.pri);
}

typedef struct{
	double real, imag;
}COMPLEX;
COMPLEX complex_add(COMPLEX c1, COMPLEX c2) {
	COMPLEX c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	return c;
}
int p6() {

	COMPLEX c1 = { 1.0,2.0 };
	COMPLEX c2 = { 2.0,3.0 };
	COMPLEX c3;

	c3 = complex_add(c1, c2);
	printf("%lf + %lfi\n", c1.real, c1.imag);
	printf("%lf + %lfi\n", c2.real, c2.imag);
	printf("%lf + l%fi\n", c3.imag, c3.real);
}

int equal(POINT *p1, POINT *p2) {
	if (p1->x == p2->y)
		if (p1->y == p2->y)
			return 1;
		else return 0;
	else return 0;

}
int p7() {
	POINT p1, p2;
	printf("��ǥ�� �Է��Ͻÿ�(x y) : ");
	scanf_s("%d %d", &p1.x, &p1.y);
	printf("��ǥ�� �Է��Ͻÿ�(x y) : ");
	scanf_s("%d %d", &p2.x, &p2.y);

	if (equal(&p1, &p2))
		printf("(%d, %d) == (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	else
		printf("(%d, %d) != (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
}

int quadrant(POINT p) {
	if (p.x > 0)
		if (p.y > 0) return 1;
		else return 4;
	else
		if (p.y > 0)return 2;
		else return 3;
}
int p8() {
	POINT p;
	printf("��ǥ�� �Է��Ͻÿ�(x y): ");
	scanf_s("%d %d", &p.x, &p.y);
	
	printf("(%d, %d)�� ��и�: %d\n", p.x, p.y, quadrant(p));
}

#define PI 3.141592
typedef struct{
	POINT center;
	double radius;
}CIRCLE;
double area(CIRCLE c) {
	return PI * c.radius * c.radius;
}
double perimeter(CIRCLE c) {
	return 2 * PI * c.radius;
}
int p9(){
	CIRCLE c;
	printf("���� �߽��� : ");
	scanf_s("%d %d", &c.center.x, &c.center.y);
	printf("���� ������ : ");
	scanf_s("%lf", &c.radius);

	printf("���� ����=%f, ���� �ѷ�=%f\n", area(c), perimeter(c));
}

typedef struct {
	char name[100];
	int calories;
}FOOD;
int p10() {
	FOOD food_array[3];
	int sum = 0;

	for (int i = 0;i < 3;i++) {
		printf("������ �̸�: ");
		scanf_s("%s", food_array[i].name,100);
		printf("Į�θ�: ");
		scanf_s("%d", &food_array[i].calories);
		printf("\n");
		sum += food_array[i].calories;
	}
	printf("�� Į�θ�=%d\n", sum);
}

typedef struct {
	int number;
	char name[10];
	char tel[20];
	int age;
}EMPLOYEE;
int p11() {
	srand((unsigned)time(NULL));

	EMPLOYEE arr[10] = {
	{1,"ȫ�浿1", "010-0000-0000", rand() % 100 },
	{2, "ȫ�浿2", "010-0000-0001", rand() % 100 },
	{3, "ȫ�浿3", "010-0000-0002", rand() % 100 },
	{4, "ȫ�浿4", "010-0000-0003", rand() % 100 },
	{5, "ȫ�浿5", "010-0000-0004", rand() % 100 },
	{6, "ȫ�浿6", "010-0000-0005", rand() % 100 },
	{7, "ȫ�浿7", "010-0000-0006", rand() % 100 },
	{8, "ȫ�浿8", "010-0000-0007", rand() % 100 },
	{9, "ȫ�浿9", "010-0000-0008", rand() % 100 },
	{10, "ȫ�浿10", "010-0000-0009", rand() % 100 }	};

	for (int i = 0;i < 10;i++)
		if (arr[i].age >= 20 && arr[i].age <= 30)
			printf("�̸�=%s ����=%d\n", arr[i].name, arr[i].age);
}

typedef struct {
	char name[10];
	char homtel[20];
	char ptel[20];
}PERSON;
int p12() {
	PERSON list[3];
	char answer[20];

	for (int i = 0;i < 3;i++) {
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf_s("%s", list[i].name, 10);
		printf("����ȭ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%s", list[i].homtel, 20);
		printf("�޴�����ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%s", list[i].ptel, 20);
	}

	printf("�˻��� �̸��� �Է��Ͻÿ� : ");
	scanf_s("%s", answer, 20);
	for (int i = 0;i < 3;i++)
		if (strcmp(answer, list[i].name) == 0)
			printf("����ȭ��ȣ : %s\n�޴�����ȣ : %s\n", list[i].homtel, list[i].ptel);
}

typedef struct {
	int type;
	union {
		struct { int base, height; }tri;
		struct { int w, h; }rect;
		struct { double radius; }circle;
	} data;
}shape;
enum type { TRI, REC, CIRC };
int p13() {
	shape s;
	enum type type;

	printf("������ Ÿ���� �Է��Ͻÿ�(0, 1, 2) : ");
	scanf_s("%d", &type);

	switch (type) {
	case TRI:
		printf("�غ��� ������ ���̸� �Է��Ͻÿ�: ");
		scanf_s("%d %d", &s.data.tri.base, &s.data.tri.height);
		printf("������ %f\n", 0.5 * s.data.tri.base * s.data.tri.height);
		break;
	case REC:
		printf("���ο� ������ ���̸� �Է��Ͻÿ�: ");
		scanf_s("%d %d\n", &s.data.rect.w, &s.data.rect.h);
		printf("������ %d\n", s.data.rect.w * s.data.rect.h);
		break;
	case CIRC:
		printf("�������� �Է��Ͻÿ�: ");
		scanf_s("%lf", &s.data.circle.radius);
		printf("������ %f\n", PI * s.data.circle.radius * s.data.circle.radius);
		break;
	default:
		printf("�߸� �Է�\n");
		break;
	}
}

enum choice{ADD=1, PRINT, SEARCH, DELETE, EXIT};
enum genre{KPOP, POP, CLASSIC, OST};
typedef struct music {
	char title[20];
	char artist[20];
	char location[20];
	int genre;
}MUSIC;
MUSIC arr[10];
void menu() {
	printf("===============\n");
	printf(" 1. �߰�\n 2. ���\n 3. �˻�\n 4. ����\n 5. ����\n");
	printf("===============\n");
}
MUSIC add(MUSIC list[], int size) {
	MUSIC m;
	
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%s", m.title, 20);
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%s", m.artist, 20);
	printf("��ġ�� �Է��Ͻÿ�: ");
	scanf_s("%s", m.location, 20);
	printf("�帣�� �Է��Ͻÿ�(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����): ");
	scanf_s("%d", &m.genre);
	
	return m;
}
void print(MUSIC list[], int size) {
	for (int i = 0;i < size;i++) {
		char genre[20];
		enum genre type = list[i].genre;
		switch (type) {
		case KPOP: strcpy_s(genre, 20, "����");break;
		case POP: strcpy_s(genre, 20, "��");break;
		case CLASSIC: strcpy_s(genre, 20, "Ŭ����");break;
		case OST: strcpy_s(genre, 20, "��ȭ����");break;
		default:break;
		}
		printf("����: %s\n����: %s\n��ġ: %s\n�帣: %s\n\n", list[i].title, list[i].artist, list[i].location, genre);
	}
}
void search(MUSIC list[], int size) {
	char title[20];
	int check = 0;
	
	printf("ã�� ���� ���� ������ �Է��Ͻÿ�: ");
	scanf_s("%s", title, 20);
	
	for (int i = 0;i < size;i++) {
		if (strcmp(title, list[i].title) == 0) {
			char genre[20];
			enum genre type = list[i].genre;
			check = 1;
			
			switch (type) {
			case KPOP: strcpy_s(genre, 20, "����");break;
			case POP: strcpy_s(genre, 20, "��");break;
			case CLASSIC: strcpy_s(genre, 20, "Ŭ����");break;
			case OST: strcpy_s(genre, 20, "��ȭ����");break;
			default:break;
			}

			printf("%d������ %s �˻� \n", i, title);
			printf("\n����: %s\n����: %s\n��ġ: %s\n�帣: %s\n\n", list[i].title, list[i].artist, list[i].location, genre);
		}
	}
	if (check == 0) printf("%s �˻� ����\n", title);
}
void delete(MUSIC list[], int size) {
	char title[20];
	printf("�����ϰ� ���� ���� ������ �Է��Ͻÿ�: ");
	scanf_s("%s", title, 20);
	int check = 0, i;

	for (i = 0;i < size;i++) {
		if (strcmp(title, list[i].title) == 0) {
			check = 1;
			break;
		}
	}
	if (check == 1) {
		for (;i < size - 1;i++) {
			strcpy_s(list[i].title, 20, list[i + 1].title);
			strcpy_s(list[i].artist, 20, list[i + 1].artist);
			strcpy_s(list[i].location, 20, list[i + 1].location);
			list[i].genre = list[i + 1].genre;
		}
		printf("\n%s�� ���������� ������\n", title);
	}
	else printf("\n%s�� ��Ͽ��� ã�� �� ����\n", title);
	
}
int p14() {
	menu();
	int size = 0;
	while (1) {
		int choice;
		printf("\n�������� �Է��Ͻÿ� : ");
		scanf_s("%d", &choice);
		printf("\n");
		if (choice == EXIT) break;
		switch (choice) {
		case ADD:
			arr[size] = add(arr, size);
			printf("���� %s�� ���������� �߰���\n", arr[size].title);
			size++;
			break;
		case PRINT:
			print(arr, size);
			printf("��� ������ ���������� ��µ�\n");
			break;
		case SEARCH:
			search(arr, size);
			break;
		case DELETE:
			delete(arr, size);
			size--;
			break;
		case EXIT:
			break;
		}
	}
}