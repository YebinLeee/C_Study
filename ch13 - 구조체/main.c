#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
	//p1(); // p.570 두 점 사이의 거리
	//p2(); // p.572 구조체 안의 구조체
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

	printf("점의 좌표를 입력하시오: ");
	scanf_s("%d %d", &p1.x, &p1.y);
	printf("점의 좌표를 입력하시오: ");
	scanf_s("%d %d", &p2.x, &p2.y);

	xdiff = p1.x - p2.x;
	ydiff = p1.y - p2.y;

	length = sqrt((double)(xdiff * xdiff + ydiff * ydiff));
	printf("거리는 %f입니다.\n", length);
	
}

typedef struct rect{
	POINT a;
	POINT b;
}RECT;
int p2() {
	RECT rec;
	int w, h;

	printf("왼쪽 상단의 좌표를 입력하시오 : ");
	scanf_s("%d %d", &rec.a.x, &rec.a.y);
	printf("오른쪽 하단의 좌표를 입력하시오 :");
	scanf_s("%d %d", &rec.b.x, &rec.b.y);

	w = rec.b.x - rec.a.x;
	if (w < 0)w = -w;
	h = rec.a.y - rec.b.y;
	if (h < 0)h = -h;

	printf("면적은 %d이고 둘레는 %d입니다.\n", w * h, 2*(w + h));
}

struct book {
	int id;
	char title[100];
	char author[20];
};
int p3() {
	struct book b = { 1,"바람과 함께 사라지다", "마가렛 미첼" };
	printf("{ %d, %s, %s }\n", b.id, b.title, b.author);
}

struct account {
	int number;
	char name[20];
	int balance;
};
int p4() {
	struct account ac = { 1, "홍길동", 100000 };
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
	struct email em = { "안부 메일", "chulsoo@hankuk.ac.kr", "hsh@hankuk.ac.kr",
	"안녕하십니까? 별일 없으신지요?", {2020, 12,03},1 };

	printf("제목 : %s\n", em.title);
	printf("수신자: %s\n발신자: %s\n", em.sender, em.receiver);
	printf("내용 : %s\n", em.content);
	printf("날짜 : %d / %d / %d\n", em.dat.year, em.dat.month, em.dat.day);
	printf("우선순위 : %d\n", em.pri);
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
	printf("좌표를 입력하시오(x y) : ");
	scanf_s("%d %d", &p1.x, &p1.y);
	printf("좌표를 입력하시오(x y) : ");
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
	printf("좌표를 입력하시오(x y): ");
	scanf_s("%d %d", &p.x, &p.y);
	
	printf("(%d, %d)의 사분면: %d\n", p.x, p.y, quadrant(p));
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
	printf("원의 중심점 : ");
	scanf_s("%d %d", &c.center.x, &c.center.y);
	printf("원의 반지름 : ");
	scanf_s("%lf", &c.radius);

	printf("원의 면적=%f, 원의 둘레=%f\n", area(c), perimeter(c));
}

typedef struct {
	char name[100];
	int calories;
}FOOD;
int p10() {
	FOOD food_array[3];
	int sum = 0;

	for (int i = 0;i < 3;i++) {
		printf("음식의 이름: ");
		scanf_s("%s", food_array[i].name,100);
		printf("칼로리: ");
		scanf_s("%d", &food_array[i].calories);
		printf("\n");
		sum += food_array[i].calories;
	}
	printf("총 칼로리=%d\n", sum);
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
	{1,"홍길동1", "010-0000-0000", rand() % 100 },
	{2, "홍길동2", "010-0000-0001", rand() % 100 },
	{3, "홍길동3", "010-0000-0002", rand() % 100 },
	{4, "홍길동4", "010-0000-0003", rand() % 100 },
	{5, "홍길동5", "010-0000-0004", rand() % 100 },
	{6, "홍길동6", "010-0000-0005", rand() % 100 },
	{7, "홍길동7", "010-0000-0006", rand() % 100 },
	{8, "홍길동8", "010-0000-0007", rand() % 100 },
	{9, "홍길동9", "010-0000-0008", rand() % 100 },
	{10, "홍길동10", "010-0000-0009", rand() % 100 }	};

	for (int i = 0;i < 10;i++)
		if (arr[i].age >= 20 && arr[i].age <= 30)
			printf("이름=%s 나이=%d\n", arr[i].name, arr[i].age);
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
		printf("이름을 입력하시오: ");
		scanf_s("%s", list[i].name, 10);
		printf("집전화번호를 입력하시오: ");
		scanf_s("%s", list[i].homtel, 20);
		printf("휴대폰번호를 입력하시오: ");
		scanf_s("%s", list[i].ptel, 20);
	}

	printf("검색할 이름을 입력하시오 : ");
	scanf_s("%s", answer, 20);
	for (int i = 0;i < 3;i++)
		if (strcmp(answer, list[i].name) == 0)
			printf("집전화번호 : %s\n휴대폰번호 : %s\n", list[i].homtel, list[i].ptel);
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

	printf("도형의 타입을 입력하시오(0, 1, 2) : ");
	scanf_s("%d", &type);

	switch (type) {
	case TRI:
		printf("밑변과 높이의 길이를 입력하시오: ");
		scanf_s("%d %d", &s.data.tri.base, &s.data.tri.height);
		printf("면적은 %f\n", 0.5 * s.data.tri.base * s.data.tri.height);
		break;
	case REC:
		printf("가로와 세로의 길이를 입력하시오: ");
		scanf_s("%d %d\n", &s.data.rect.w, &s.data.rect.h);
		printf("면적은 %d\n", s.data.rect.w * s.data.rect.h);
		break;
	case CIRC:
		printf("반지름을 입력하시오: ");
		scanf_s("%lf", &s.data.circle.radius);
		printf("면적은 %f\n", PI * s.data.circle.radius * s.data.circle.radius);
		break;
	default:
		printf("잘못 입력\n");
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
	printf(" 1. 추가\n 2. 출력\n 3. 검색\n 4. 삭제\n 5. 종료\n");
	printf("===============\n");
}
MUSIC add(MUSIC list[], int size) {
	MUSIC m;
	
	printf("제목을 입력하시오: ");
	scanf_s("%s", m.title, 20);
	printf("가수를 입력하시오: ");
	scanf_s("%s", m.artist, 20);
	printf("위치를 입력하시오: ");
	scanf_s("%s", m.location, 20);
	printf("장르를 입력하시오(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악): ");
	scanf_s("%d", &m.genre);
	
	return m;
}
void print(MUSIC list[], int size) {
	for (int i = 0;i < size;i++) {
		char genre[20];
		enum genre type = list[i].genre;
		switch (type) {
		case KPOP: strcpy_s(genre, 20, "가요");break;
		case POP: strcpy_s(genre, 20, "팝");break;
		case CLASSIC: strcpy_s(genre, 20, "클래식");break;
		case OST: strcpy_s(genre, 20, "영화음악");break;
		default:break;
		}
		printf("제목: %s\n가수: %s\n위치: %s\n장르: %s\n\n", list[i].title, list[i].artist, list[i].location, genre);
	}
}
void search(MUSIC list[], int size) {
	char title[20];
	int check = 0;
	
	printf("찾고 싶은 음악 제목을 입력하시오: ");
	scanf_s("%s", title, 20);
	
	for (int i = 0;i < size;i++) {
		if (strcmp(title, list[i].title) == 0) {
			char genre[20];
			enum genre type = list[i].genre;
			check = 1;
			
			switch (type) {
			case KPOP: strcpy_s(genre, 20, "가요");break;
			case POP: strcpy_s(genre, 20, "팝");break;
			case CLASSIC: strcpy_s(genre, 20, "클래식");break;
			case OST: strcpy_s(genre, 20, "영화음악");break;
			default:break;
			}

			printf("%d번에서 %s 검색 \n", i, title);
			printf("\n제목: %s\n가수: %s\n위치: %s\n장르: %s\n\n", list[i].title, list[i].artist, list[i].location, genre);
		}
	}
	if (check == 0) printf("%s 검색 실패\n", title);
}
void delete(MUSIC list[], int size) {
	char title[20];
	printf("삭제하고 싶은 음악 제목을 입력하시오: ");
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
		printf("\n%s가 성공적으로 삭제됨\n", title);
	}
	else printf("\n%s를 목록에서 찾을 수 없음\n", title);
	
}
int p14() {
	menu();
	int size = 0;
	while (1) {
		int choice;
		printf("\n정수값을 입력하시오 : ");
		scanf_s("%d", &choice);
		printf("\n");
		if (choice == EXIT) break;
		switch (choice) {
		case ADD:
			arr[size] = add(arr, size);
			printf("음악 %s가 성공적으로 추가됨\n", arr[size].title);
			size++;
			break;
		case PRINT:
			print(arr, size);
			printf("모든 음악이 성공적으로 출력됨\n");
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