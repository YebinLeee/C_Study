#include <stdio.h>
#include <string.h>

int main(void) {
	p1(); // 예제 1,2번
	//p2(); // 예제 3,4번
	//p3(); // 예제 5번
	//p4(); // 예제 6번 
	//p5(); // 예제 7번
	// p6(); // Programming 3번
	//p7(); // Prgoramming 5번
	//p8();

	return 0;
}

int p1() {
	FILE* fp;
	char fname[100];
	int number,count = 0;
	char name[20];
	float score, total = 0.0;

	printf("성적 파일 이름을 입력하시오: ");
	scanf_s("%s", fname, 100);

	
	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "성적 파일 %s를 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (1) {
		printf("학번, 이름, 성적을 입력하시오(음수이면 종료) : ");
		scanf_s("%d", &number);
		if (number < 0)break;
		scanf_s("%s %f", name, 20, &score);
		fprintf(fp, "%d %s %f\n", number, name, score);
	}
	fclose(fp);


	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "성적 파일 %s를 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%d %s %f", &number, name, 20, &score);
		total += score;
		count++;
	}
	printf("평균 = %f\n", total / count);
	fclose(fp);
}

#define SIZE1 5
int p2() {
	int buffer[SIZE1];
	FILE* fp = NULL;
	
	/*
	fopen_s(&fp, "binary.bin", "wb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin 파일을 열 수 없습니다.\n");
		return 1;
	}
	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);
	*/

	fopen_s(&fp, "binary.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin 파일을 열 수 없습니다.\n");
		return 1;
	}
	fread(buffer, sizeof(int),SIZE1, fp);
	for (int i = 0;i < SIZE1;i++)
		printf("%d ", buffer[i]);
	fclose(fp);
	return 0;
}

int p3() {
	FILE* fp;
	fopen_s(&fp, "sample.txt", "wt"); // write, read모드 따로 하고 싶지 않다면 w+하여서 fflush(fp)를 추가
	fputs("ABCDEFGHIJKLMNOPQRSTUVWXYZ", fp);
	fclose(fp);
	fopen_s(&fp, "sample.txt", "rt");
	fseek(fp, 3, SEEK_SET); // 퍼일포언티의 위치를 변경 가능
	printf("fseek(fp, 3, SEEK_SET) = %c \n",fgetc(fp)); // 파일포인터 fp가 현재 놓여있는 우치에서 가리키는 값을 출력
	
	fseek(fp, -1, SEEK_END);
	printf("fseek(fp, -1, SEEK_END) = %c \n", fgetc(fp));

	fclose(fp);
}

int p4() {
	FILE* fp;
	char fname[128], buffer[256], word[256];
	int line_num = 0;

	printf("파일 이름을 입력하시오: ");
	scanf_s("%s", fname, 128);
	printf("탐색할 단어를 입력하시오: ");
	scanf_s("%s", word, 256);

	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "파일 %s를 열 수 없습니다.\n", fname);
		exit(1);
	}
	while (fgets(buffer, 256, fp)) // 더이상 입력되는 내용이 없다면 음수값이 반환되기 때문에 반복문 종료
	{
		line_num++;
		if (strstr(buffer,word)) {
			printf("%s: %d 단어 %s이 발견되었습니다.\n", fname, line_num, word);
		}
	}
	fclose(fp);
}

int p5() {
	FILE* src_file, * dst_file;
	char filename[100];
	char buffer[1024]; 
	int r_count;

	printf("이미지 파일 이름: ");
	scanf_s("%s", filename, 100);
	fopen_s(&src_file, filename, "rb");
	fopen_s(&dst_file, "copy.jpg", "wb");
	
	if (src_file == NULL || dst_file == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		return 1;
	}
	while ((r_count = fread(buffer, 1, sizeof(buffer), src_file))>0) // 읽어드리는 내용이 있는 동안 반복문 실행
	{
		int w_count = fwrite(buffer, 1, r_count, dst_file); // dst_file(copy.jpg)파일에 저장. 한블록 읽을 때마다 복사할 파일에 한 블록씩 복사
		if (w_count < 0) {
			fprintf(stderr, "파일 쓰기 오류\n");
			return 1;
		}
		if (w_count < r_count) {
			fprintf(stderr, "미디어 쓰기 오류\n");
			return 1;
		}
	}
	printf("copy.jpg로 이미지 파일이 복사됨\n");
	fclose(src_file);
	fclose(dst_file);
}

int p6() {
	FILE* fp1, * fp2;
	char orig[100], copy[100];
	char buffer[1024];
	int r_count;

	printf("원본 파일 이름: ");
	scanf_s("%s", orig, 100);
	printf("복사 파일 이름: ");
	scanf_s("%s", copy, 100);

	fopen_s(&fp1, orig, "rt");
	fopen_s(&fp2, copy, "wt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 열 수 없음\n");
		exit(1);
	}
	while ((r_count = fread(buffer, 1, sizeof(buffer), fp1)) > 0) {
		int w_count = fwrite(buffer, 1, r_count, fp2); 
		if (w_count < 0) {
			fprintf(stderr, "파일 쓰기 오류\n");
			return 1;
		}
		if (w_count < r_count) {
			fprintf(stderr, "파일 복사 오류\n");
			return 1;
		}
	}
	printf("%s로 이미지 파일이 복사됨\n", copy);
	fclose(fp1);
	fclose(fp2);
}

#define SIZE 3
typedef struct student {
	char name[10];
	int kor;
	int math;
	int eng;
}STU;
int p7() {
	STU s;
	FILE* fp1, * fp2;
	char fname1[20], fname2[20];

	printf("학생 성적 파일 이름: ");
	scanf_s("%s", fname1, 20);
	printf("성적 평균 파일 이름: ");
	scanf_s("%s", fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "wt");
	if (fp1 == NULL || fp2 == NULL){
		fprintf(stderr, "파일을 열 수 없음 \n");
		exit(1);
	}

	fprintf(fp2, "이름\t평균\n");

	while (!feof(fp1)) {
		fscanf_s(fp1, "%s %d %d %d", s.name, 10, &s.kor, &s.math, &s.eng);
		float avg = (s.kor + s.math + s.eng) / 3;
		fprintf(fp2, "%s\t%.2f\n", s.name, avg);
	}
	printf("성적 평균 파일 %s가 생성됨\n", fname2);
	fclose(fp1);
	fclose(fp2);
}


#define SIZE 50
typedef struct book {
	char title[SIZE];
	char author[SIZE];
	char publisher[SIZE];
}BOOK;

void menu();
BOOK get_record();
void add_record(FILE* fp);
void print_record(FILE* fp);
void search_record(FILE* fp);

int p8() {
	FILE* fp;
	char fname[SIZE];

	printf("파일 이름을 입력하시오: ");
	gets_s(fname, SIZE);
	fopen_s(&fp, fname, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "파일을 여는데 실패하였습니다.\n");
		exit(1);
	}
	int number;
	while (1) {
		menu();
		printf("정수값을 입력하시오: ");
		scanf_s("%d", &number);
		printf("\n");
		switch (number) {
		case 1:add_record(fp);break;
		case 2:print_record(fp);break;
		case 3:search_record(fp);break;
		case 4:return 0;
		}
	}

	return 0;
}
void menu() {
	printf("====================\n");
	printf("1.추가\n2.출력\n3.검색\n4.종료\n");
	printf("====================\n");
}
BOOK get_record() {
	BOOK data;
	getchar();

	printf("도서의 이름: ");
	gets_s(data.title, SIZE);
	printf("저자: ");
	gets_s(data.author, SIZE);
	printf("출판사: ");
	gets_s(data.publisher, SIZE);
	return data;
}
void add_record(FILE* fp) {
	BOOK data;
	data = get_record();
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
	printf("책 %s를 성공적으로 추가하였습니다.\n\n", data.title);
}
void print_record(FILE* fp) {
	BOOK data;
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		printf("도서 제목: %s\n", data.title);
		printf("저자: %s\n", data.author);
		printf("출판사: %s\n\n", data.publisher);
	}
	printf("모든 도서 정보를 출력하였습니다.\n\n");
}
void search_record(FILE* fp) {
	BOOK data;
	char title[SIZE];
	int check = 0;

	getchar();
	printf("찾고자 하는 책 제목을 입력하시오: ");
	gets_s(title, SIZE);
	fseek(fp, 0, SEEK_SET);
	while (!feof) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(title, data.title) == 0) {
			printf("도서 제목: %s\n", data.title);
			printf("저자: %s\n", data.author);
			printf("출판사: %s\n", data.publisher);
			printf("책 %s 를 성공적으로 찾았습니다.\n\n", title);
			check = 1;
			break;
		}
	}
	if (check == 0)
		printf("찾고자 하는 책 %s를 찾지 못하였습니다.\n\n", title);
}