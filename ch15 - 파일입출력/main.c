#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
	//p1(); // p.671-2 파일, 파일에 문자열 입출력, 문자열 탐색
	//p2(); // p.672-3 파일 입력
	//p3(); //p.679-80 이진 데이터 파일 입출력
	//p4(); // 임의 접근: ftell, fseek, rewind()
	//p5(); // p.686-8 주소록 

	//p6(); // Programming #1-12
	//p7();
	//p8();
	//p9();
	//p10();
	//p11();
	//p12();
	//p13();
	//p14();
	//p15();
	//p16();
	//p17();
	//p18();

	p19(); // getchar(),gets(), fgetc(), fgets(), fscanfs(), fread(), strstr() 의 반환값 알아보기
	return 0;
}
int p1() {
	FILE* fp;
	char fname[20], word[10], buffer[100];
	int line_num = 0;
	char* p = NULL;

	printf("파일 이름 입력 : ");
	scanf_s("%s", fname, 20);
	printf("찾을 단어 입력 : ");
	scanf_s("%s", word, 10);

	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}
	
	while (fgets(buffer, 100, fp)) {
		line_num++;
		if (strstr(buffer, word)) {
			p = strstr(buffer, word);
			printf("%s  %d 단어 %s이 발견되었습니다.:%p\n", fname, line_num, word,p);
		}
	}
	fclose(fp);
}

int p2() {
	FILE* fp;
	char fname[20];
	char name[20];
	int number, count = 0;
	float score, total = 0.0;

	printf("파일 이름 입력 : ");
	scanf_s("%s", fname, 20);

	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}
	
	while (1) {
		printf("학생의 학번, 이름, 성적을 입력하시오(종료는 음수) : ");
		scanf_s("%d", &number);
		if (number < 0) break;
		scanf_s("%s %f", name, 20,&score);
		fprintf(fp, " %d %s %f", number, name, score);
	}
	fclose(fp);

	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%d %s %f\n", &number, name, 20, &score);
		printf("%d %s %f", number, name, score);
		total += score;
		count++;
	}
	printf("학생 수는 %d, 성적의 총합은 %f, 성적의 평균은 %f입니다.\n", count, total, total / count);
	fclose(fp);
}

typedef struct student {
	int number;
	char name[10];
	double grade;
}STU;
int p3() {
	FILE* fp;
	STU list[3] = { {1,"KIM", 3.0}, {2,"Lee",3.5}, {3,"Park",4.0} };
	STU s;
	char name[20];

	printf("이진 파일 이름을 입력하시오: ");
	scanf_s("%s", name, 20);
	fopen_s(&fp, name, "wb");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	for (int i = 0;i < 3;i++) {
		fwrite(list+i, sizeof(STU), 1, fp);
	}
	fclose(fp);

	fopen_s(&fp, name, "rb");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}
	for (int i = 0;i < 3;i++) {
		fread(&s, sizeof(STU), 1, fp);
		printf("%d %s %f\n", s.number, s.name, s.grade);
	}

	fclose(fp);
} 

int p4() {
	FILE* fp;
	char buffer[100];

	fopen_s(&fp, "sample.txt", "wt");
	fputs("ABCDEFGH", fp);
	fclose(fp);

	fopen_s(&fp, "sample.txt", "rt");
	int result = fseek(fp, 0, SEEK_SET);
	printf("fseek(fp, 0, SEEK_SET) = %d %c\n", result, fgetc(fp));
	result = fseek(fp, -5, SEEK_END);
	printf("fseek(fp, -5, SEEK_END) = %d %c\n", result, fgetc(fp));
	result = fseek(fp, 0, SEEK_END);
	printf("fseek(fp, 0, SEEK_END) = %d %c\n", result, fgetc(fp));
	printf("ftell = %ld\n", ftell(fp));
	rewind(fp);
	printf("rewind(fp), %c %ld\n", fgetc(fp),ftell(fp));

	fclose(fp);
}

typedef struct person {
	char name[10];
	char address[30];
	char tel[20];
	char desc[20];
}PERSON;

enum type { ADD = 1, SEARCH, PRINT, EXIT };
void menu() {
	printf("===============\n");
	printf(" 1. 추가\n 2. 검색 \n 3. 출력\n 4. 종료 \n");
	printf("===============\n\n");
}
PERSON get_data() {
	PERSON data;

	printf("이름: "); gets_s(data.name,10);
	printf("주소: "); gets_s(data.address, 30);
	printf("휴대폰: "); gets_s(data.tel,20);
	printf("특징: "); gets_s(data.desc, 20);

	return data;
}
void print_record(FILE* fp) {
	PERSON data;
	char buffer[100];

	fseek(fp, 0, SEEK_SET);
	while (1) {
		fread(&data, sizeof(PERSON), 1, fp);
		if (feof(fp)) break;
		printf("이름: %s\n주소: %s\n휴대폰번호: %s\n특징: %s\n\n", data.name, data.address, data.tel, data.desc);
	}
	printf("\n");
}
void add_record(FILE* fp) {
	PERSON data = get_data();

	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(PERSON), 1, fp);
	printf("\n%s의 정보 추가 성공\n\n", data.name);
}
void search_record(FILE* fp) {
	PERSON data;
	char name[20];
	int check = 0;

	printf("찾고자 하는 사람의 이름: ");
	gets_s(name,20);

	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fread(&data, sizeof(PERSON), 1, fp);
		if (strcmp(name, data.name) == 0) {
			check = 1;
			printf("주소: %s\n번호: %s\n특징: %s\n", data.address, data.tel, data.desc);
			break;
		}
	}
	if (check == 1) printf("%s를 목록에서 검색하여 출력 성공\n\n", name);
	else printf("%s를 목록에서 검색 실패\n\n", name);
}
void update_record(FILE* fp) {
	PERSON data;
	char name[20], tel[20];
	int check = 0;

	printf("수정고자 하는 사람의 이름: ");
	gets_s(name, 20);
	printf("바꿀 번호 입력: ");
	gets_s(tel, 20);

	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fread(&data, sizeof(PERSON), 1, fp);
		if (strcmp(name, data.name) == 0) {
			// strcpy_s
			break;
		}
	}
	if (check == 1) printf("%s의 번호를 %s로 수정 완료\n\n", name, tel);
	else printf("%s를 목록에서 검색 실패\n\n", name);
}
int p5() {
	FILE* fp;
	char fname[20];
	
	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname, 20);
	fopen_s(&fp, fname, "wb+");
	if (fp == NULL) {
		printf("파일을 열 수 없음 \n");
		exit(1);
	}

	menu();
	while (1) {
		int choice;
		printf("정수값을 입력하시오 : ");
		scanf_s("%d", &choice);
		getchar();
		if (choice >= EXIT) break;

		switch (choice) {
		case ADD:add_record(fp);break;
		case SEARCH:search_record(fp);break;
		case PRINT:print_record(fp);break;
		case EXIT:break;
		}
	}
	
	fclose(fp);
}

int p6() {
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];
	char buffer1[100], buffer2[100];
	int line_num = 0, check=0;
	int c1, c2;
	printf("첫번째 파일 이름 : ");
	gets_s(fname1, 20);
	printf("두번째 파일 이름 : ");
	gets_s(fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "rt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 여는데 실패\n");
		exit(1);
	}

	//fgetc() 이용하여 한 문자씩 비교하기
	
	while (!feof(fp1)) {
		if ((c1=fgetc(fp1)) != (c2=fgetc(fp2))) {
			printf("파일은 %c, %c에서 서로 다릅니다.\n", c1, c2);
				check = 1;
				break;
		}
	}
	/* fgets() 이용하여 한 줄씩 비교하기 
	while (!feof(fp1)) {
		line_num++;
		if (strcmp(fgets(buffer1, 100, fp1),fgets(buffer2, 100, fp2))!=0) {
			printf("두 파일은 %d번째 줄에서 %s%s 서로 다릅니다.\n", line_num, buffer1, buffer2);
			check = 1;
			break;
		}
	}
	*/
	if (check == 0) printf("두 파일은 서로 같습니다.\n");
	fclose(fp1);
	fclose(fp2);
}

int p7() {
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];
	int c;

	printf("첫번째 파일 이름 : ");
	gets_s(fname1, 20);
	printf("두번째 파일 이름 : ");
	gets_s(fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "wt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 여는데 실패\n");
		exit(1);
	}
	while (!feof(fp1)) {
		c = fgetc(fp1);
		if(isalpha(c))
			c = toupper(c);
		fputc(c,fp2);
	}
	fclose(fp1);
	fclose(fp2);	
}

int p8() {
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];
	char buffer1[1024], buffer2[1024];
	int check = 0, r_count, w_count;

	printf("첫번째 파일 이름 : ");
	gets_s(fname1, 20);
	printf("두번째 파일 이름 : ");
	gets_s(fname2, 20);

	fopen_s(&fp1, fname1, "rb");
	fopen_s(&fp2, fname2, "wb");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 여는데 실패\n");
		exit(1);
	}

	while ((r_count = fread(buffer1, sizeof(char), sizeof(buffer1), fp1)) > 0) {
		w_count = fwrite(buffer1, sizeof(char), r_count, fp2);
		printf("%d %d\n", r_count, w_count);
		if (w_count < 0) {
			fprintf(stderr, "파일 쓰기 오류\n");
			return 1;
		}
		if (w_count < r_count) {
			fprintf(stderr, "파일 복사 오류\n");
			return 1;
		}
		if (r_count > w_count) {
			check = 1;
			printf("파일 복사 실패\n");
			break;
		}
	}
	if (check == 0) printf("파일 복사 성공\n");
	fclose(fp1);
	fclose(fp2);

}

int p9() {
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];
	char buffer1[100], buffer2[100];
	int check = 0, line_num = 0;

	printf("첫번째 파일 이름 : ");
	gets_s(fname1, 20);
	printf("두번째 파일 이름 : ");
	gets_s(fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "rt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 여는데 실패\n");
		exit(1);
	}

	while (!feof(fp1)) {
		line_num++;
		if (strcmp(fgets(buffer1, 100, fp1), fgets(buffer2, 100, fp2)) != 0) {
			printf("Line %d: << %s\n>> %s", line_num,buffer1, buffer2);
			check = 1;
			break;
		}
	}
	if (check == 0)printf("파일은 서로 일치함\n");
	fclose(fp1);
	fclose(fp2);
}

typedef struct scores {
	char name[10];
	int KOR;
	int MATH;
	int ENG;
}SCORES;
int p10() {
	SCORES s;
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];
	int total = 0;
	double avg;

	printf("첫번째 파일 이름 : ");
	gets_s(fname1, 20);
	printf("두번째 파일 이름 : ");
	gets_s(fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "wt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 여는데 실패\n");
		exit(1);
	}

	fseek(fp1, 0, SEEK_SET);
	while(!feof(fp1)){
		fscanf_s(fp1, "%s %d %d %d\n", s.name, 10, &s.KOR, &s.MATH, &s.ENG);
		total = s.KOR + s.MATH + s.ENG;
		avg = total / 3.0;
		fprintf(fp2, "%s %.2f\n", s.name, avg);
	}
	fclose(fp1);
	fclose(fp2);
}

int p11() {
	FILE* fp;
	char fname[20];
	int num = 0, ch;

	printf("파일 이름을 입력하시오 : ");
	scanf_s("%s", fname, 20);
	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음 \n");
		exit(1);
	}

	while ((ch = fgetc(fp)) != EOF) {
		num++;
	}
	printf("문자의 개수는 %d\n", num);
	fclose(fp);
}

int p12() {
	FILE* fp;
	char fname[20];
	char buffer[200];
	char ch;
	int n;

	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname, 20);
	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	printf("내용 입력하시오 \n");
	//문자열을 파일에 쓰는 경우: 줄바꿈\n은 파일에 출력되지 않음.
	while ((n= gets_s(buffer,100)) != EOF) {
		fputs(buffer, fp);
		printf("%d : buffer: %s\n", n, buffer);
		if (n == 0) break;
	}
	
	/* 문자 하나씩 파일에 쓰는 경우 
	while ((ch = getchar()) != EOF) {
		fputc(ch, fp);
	}
	*/
	fclose(fp);
}

int p13() {
	srand((unsigned)time(NULL));
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];

	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname1, 20);
	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname2, 20);

	fopen_s(&fp1, fname1, "wt");
	fopen_s(&fp2, fname2, "wb");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	for (int i = 0;i < 100;i++) {
		int n = rand;
		fprintf(fp1, "%d", n);
		fwrite(&n, sizeof(char), 1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}

int p14() {
	FILE* fp1, * fp2, * fp3;
	char fname1[20], fname2[20];
	char fname3[20];
	char buffer[100];

	printf("파일1 이름을 입력하시오: ");
	scanf_s("%s", fname1, 20);
	printf("파일2 이름을 입력하시오: ");
	scanf_s("%s", fname2, 20);
	printf("하나로 합칠 파일 이름을 입력하시오: ");
	scanf_s("%s", fname3, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "rt");
	fopen_s(&fp3, fname3, "wt");
	if (fp1 == NULL || fp2 == NULL || fp3==NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	while (!feof(fp1)) {
		fgets(buffer, 100, fp1);
		fputs(buffer, fp3);
	}
	fseek(fp3, 0, SEEK_END);
	fputc('\n', fp3);
	while (!feof(fp2)) {
		fgets(buffer, 100, fp2);
		fputs(buffer, fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

int p15() {
	FILE* fp;
	char fname[20], buffer[100];

	printf("파일 이름 입력: ");
	scanf_s("%s", fname, 20);
	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음 \n");
		exit(1);
	}

	int n = 1;
	while (!feof(fp)) {
		fgets(buffer, 100, fp);
		printf("%6d: %s", n++, buffer);
	}
	printf("\n");
	fclose(fp);
}

typedef struct book {
	char title[10];
	char writer[10];
	char publisher[10];
}BOOK;
BOOK get_book() {
	BOOK b;

	printf("도서의 이름: "); gets_s(b.title, 10);
	printf("저자: "); gets_s(b.writer, 10);
	printf("출판사: "); gets_s(b.publisher, 10);

	return b;
		
}
void add_book(FILE *fp){
	BOOK b = get_book();
	
	fseek(fp, 0, SEEK_END);
	fwrite(&b, sizeof(b), 1, fp);
	printf("도서 %s를 성공적으로 파일에 입력하였음\n\n", b.title);
}
void print_book(FILE *fp) {
	BOOK b;
	int i = 0;

	fseek(fp, 0, SEEK_SET);
	while (1) {
		printf("fread 전 : feof : %d\n", feof(fp));
		fread(&b, sizeof(b), 1, fp);
		printf("fread 후 : foef : %d\n", feof(fp));
		if (feof(fp))break;
		printf("< 도서 %d의 정보 > \n", i++);
		printf("도서의 이름 : %s\n", b.title);
		printf("저자 : %s\n", b.writer);
		printf("출판사: %s\n\n", b.publisher);
	}
}
void search_book(FILE *fp) {
	BOOK b;
	char name[10];
	int i=0, check = 0;

	printf("찾고자 하는 도서의 제목 입력: ");
	scanf_s("%s", name, 10);

	fseek(fp, 0, SEEK_SET);
	while(!feof(fp)){
		fread(&b, sizeof(b), 1, fp);
		if (strcmp(name, b.title) == 0) {
			printf("< 도서 %d의 정보 > \n", i);
			printf("도서의 이름 : %s\n", b.title);
			printf("저자 : %s\n", b.writer);
			printf("출판사: %s\n\n", b.publisher);
			check = 1;
			break;
		}
		i++;
	}
	if (check == 0)
		printf("도서를 목록에서 찾지 못하였음\n");
}
int p16() {
	FILE* fp;
	char fname[20];
	int choice, size = 0;
	enum type type;

	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname, 20);

	fopen_s(&fp, fname, "w+b");
	if (fp == NULL) {
		fprintf(stderr, "파일 열 수 없음\n");
		exit(1);
	}

	menu();
	while (1) {
		printf("메뉴를 입력하시오: ");
		scanf_s("%d", &choice);
		type = choice;
		getchar();

		switch (choice) {
		case ADD:add_book(fp);break;
		case PRINT:print_book(fp);break;
		case SEARCH:search_book(fp);break;
		case EXIT:return 0;
		}
	}
	fclose(fp);
}

int p17() {
	FILE* fp;
	char name[20], word[10], buffer[100];
	int line_num = 0;

	printf("파일 이름 : ");
	scanf_s("%s", name, 20);
	printf("탐색할 단어 : ");
	scanf_s("%s", word, 10);

	fopen_s(&fp, name, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}

	while (fgets(buffer, 100, fp)) {
		line_num++;
		if(strstr(buffer,word))
			printf("%s:%d %s", name, line_num, buffer);
	}
	printf("\n");
	fclose(fp);
}

int p18() {
	FILE* fp1, * fp2;
	char fname1[20], fname2[20], buffer[200], word1[20], word2[20];
	char seps[] = " ";
	char* token, * next = NULL;

	printf("읽을 파일 이름 입력 : ");
	scanf_s("%s", fname1, 20);
	printf("쓸 파일 이름 입력 : ");
	scanf_s("%s", fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "wt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}
	while (fgets(buffer, 100, fp1))
		printf(buffer);
	printf("\n");

	printf("바꿔야 하는 단어 입럭 : ");
	scanf_s("%s", word1, 20);
	printf("무엇으로 바꾸시겠습니까: ");
	scanf_s("%s", word2, 20);

	int n = 0;
	fseek(fp1, 0, SEEK_SET);
	/* 모든 단어를 하나씩 쪼개서 이어붙이는 방법
	while (fgets(buffer, 200, fp1)) {
		char buffer2[200] = "";
		printf("%d번째 줄 : %s", n++, buffer);
		int i = 0;
		
		token = strtok_s(buffer, seps, &next);
		while (token != NULL) {
			printf("%d 번째 token : %s\n",i++,token);
			if (strcmp(token, word1) == 0)
				strcat_s(buffer2, _countof(buffer2), word2);
			else
				strcat_s(buffer2, _countof(buffer2), token);
			strcat_s(buffer2, _countof(buffer2), " ");
			token = strtok_s(NULL, seps, &next);
		}
		printf("buffer2 = %s\n", buffer2);
		fputs(buffer2,fp2);
	}
	*/

	// 찾고자 하는 단어를 발견한 문장만 strtok_s로 쪼개는 방법

	while (fgets(buffer, 200, fp1)) {
		char buffer2[200] = "";
		printf("%d번째 줄 buffer = %s", n, buffer);
		
		if (strstr(buffer, word1)) {
			printf("%d번째 줄에서 찾고자 하는 단어 %s발견\n", n, word1);

			token = strtok_s(buffer, seps, &next);
			while (token != NULL) {
				if (strcmp(token, word1) == 0)
					strcat_s(buffer2, _countof(buffer2), word2);
				else
					strcat_s(buffer2, _countof(buffer2), token);
				strcat_s(buffer2, _countof(buffer2), " ");
				token = strtok_s(NULL, seps, &next);
			}
			fputs(buffer2, fp2);
		}
		else fputs(buffer, fp2);
		n++;
	}

	fclose(fp1);
	fclose(fp2);
}

int p19() {
	FILE* fp;
	char ch;
	char buffer[100];
	
	fopen_s(&fp, "proverbs.txt", "rt");
	while (1) {
		int n= fgets(buffer, 100, fp);
		printf("fgets : %d\nfeof : %d\nbuffer : %s", n, feof(fp),buffer);
		if (feof(fp))break;
	}
	
}