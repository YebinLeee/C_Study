#include <stdio.h>
#include <string.h>

int main(void) {
	p1(); // ���� 1,2��
	//p2(); // ���� 3,4��
	//p3(); // ���� 5��
	//p4(); // ���� 6�� 
	//p5(); // ���� 7��
	// p6(); // Programming 3��
	//p7(); // Prgoramming 5��
	//p8();

	return 0;
}

int p1() {
	FILE* fp;
	char fname[100];
	int number,count = 0;
	char name[20];
	float score, total = 0.0;

	printf("���� ���� �̸��� �Է��Ͻÿ�: ");
	scanf_s("%s", fname, 100);

	
	fopen_s(&fp, fname, "wt");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (1) {
		printf("�й�, �̸�, ������ �Է��Ͻÿ�(�����̸� ����) : ");
		scanf_s("%d", &number);
		if (number < 0)break;
		scanf_s("%s %f", name, 20, &score);
		fprintf(fp, "%d %s %f\n", number, name, score);
	}
	fclose(fp);


	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%d %s %f", &number, name, 20, &score);
		total += score;
		count++;
	}
	printf("��� = %f\n", total / count);
	fclose(fp);
}

#define SIZE1 5
int p2() {
	int buffer[SIZE1];
	FILE* fp = NULL;
	
	/*
	fopen_s(&fp, "binary.bin", "wb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin ������ �� �� �����ϴ�.\n");
		return 1;
	}
	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);
	*/

	fopen_s(&fp, "binary.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "binary.bin ������ �� �� �����ϴ�.\n");
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
	fopen_s(&fp, "sample.txt", "wt"); // write, read��� ���� �ϰ� ���� �ʴٸ� w+�Ͽ��� fflush(fp)�� �߰�
	fputs("ABCDEFGHIJKLMNOPQRSTUVWXYZ", fp);
	fclose(fp);
	fopen_s(&fp, "sample.txt", "rt");
	fseek(fp, 3, SEEK_SET); // ��������Ƽ�� ��ġ�� ���� ����
	printf("fseek(fp, 3, SEEK_SET) = %c \n",fgetc(fp)); // ���������� fp�� ���� �����ִ� ��ġ���� ����Ű�� ���� ���
	
	fseek(fp, -1, SEEK_END);
	printf("fseek(fp, -1, SEEK_END) = %c \n", fgetc(fp));

	fclose(fp);
}

int p4() {
	FILE* fp;
	char fname[128], buffer[256], word[256];
	int line_num = 0;

	printf("���� �̸��� �Է��Ͻÿ�: ");
	scanf_s("%s", fname, 128);
	printf("Ž���� �ܾ �Է��Ͻÿ�: ");
	scanf_s("%s", word, 256);

	fopen_s(&fp, fname, "rt");
	if (fp == NULL) {
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}
	while (fgets(buffer, 256, fp)) // ���̻� �ԷµǴ� ������ ���ٸ� �������� ��ȯ�Ǳ� ������ �ݺ��� ����
	{
		line_num++;
		if (strstr(buffer,word)) {
			printf("%s: %d �ܾ� %s�� �߰ߵǾ����ϴ�.\n", fname, line_num, word);
		}
	}
	fclose(fp);
}

int p5() {
	FILE* src_file, * dst_file;
	char filename[100];
	char buffer[1024]; 
	int r_count;

	printf("�̹��� ���� �̸�: ");
	scanf_s("%s", filename, 100);
	fopen_s(&src_file, filename, "rb");
	fopen_s(&dst_file, "copy.jpg", "wb");
	
	if (src_file == NULL || dst_file == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		return 1;
	}
	while ((r_count = fread(buffer, 1, sizeof(buffer), src_file))>0) // �о�帮�� ������ �ִ� ���� �ݺ��� ����
	{
		int w_count = fwrite(buffer, 1, r_count, dst_file); // dst_file(copy.jpg)���Ͽ� ����. �Ѻ�� ���� ������ ������ ���Ͽ� �� ��Ͼ� ����
		if (w_count < 0) {
			fprintf(stderr, "���� ���� ����\n");
			return 1;
		}
		if (w_count < r_count) {
			fprintf(stderr, "�̵�� ���� ����\n");
			return 1;
		}
	}
	printf("copy.jpg�� �̹��� ������ �����\n");
	fclose(src_file);
	fclose(dst_file);
}

int p6() {
	FILE* fp1, * fp2;
	char orig[100], copy[100];
	char buffer[1024];
	int r_count;

	printf("���� ���� �̸�: ");
	scanf_s("%s", orig, 100);
	printf("���� ���� �̸�: ");
	scanf_s("%s", copy, 100);

	fopen_s(&fp1, orig, "rt");
	fopen_s(&fp2, copy, "wt");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "������ �� �� ����\n");
		exit(1);
	}
	while ((r_count = fread(buffer, 1, sizeof(buffer), fp1)) > 0) {
		int w_count = fwrite(buffer, 1, r_count, fp2); 
		if (w_count < 0) {
			fprintf(stderr, "���� ���� ����\n");
			return 1;
		}
		if (w_count < r_count) {
			fprintf(stderr, "���� ���� ����\n");
			return 1;
		}
	}
	printf("%s�� �̹��� ������ �����\n", copy);
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

	printf("�л� ���� ���� �̸�: ");
	scanf_s("%s", fname1, 20);
	printf("���� ��� ���� �̸�: ");
	scanf_s("%s", fname2, 20);

	fopen_s(&fp1, fname1, "rt");
	fopen_s(&fp2, fname2, "wt");
	if (fp1 == NULL || fp2 == NULL){
		fprintf(stderr, "������ �� �� ���� \n");
		exit(1);
	}

	fprintf(fp2, "�̸�\t���\n");

	while (!feof(fp1)) {
		fscanf_s(fp1, "%s %d %d %d", s.name, 10, &s.kor, &s.math, &s.eng);
		float avg = (s.kor + s.math + s.eng) / 3;
		fprintf(fp2, "%s\t%.2f\n", s.name, avg);
	}
	printf("���� ��� ���� %s�� ������\n", fname2);
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

	printf("���� �̸��� �Է��Ͻÿ�: ");
	gets_s(fname, SIZE);
	fopen_s(&fp, fname, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "������ ���µ� �����Ͽ����ϴ�.\n");
		exit(1);
	}
	int number;
	while (1) {
		menu();
		printf("�������� �Է��Ͻÿ�: ");
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
	printf("1.�߰�\n2.���\n3.�˻�\n4.����\n");
	printf("====================\n");
}
BOOK get_record() {
	BOOK data;
	getchar();

	printf("������ �̸�: ");
	gets_s(data.title, SIZE);
	printf("����: ");
	gets_s(data.author, SIZE);
	printf("���ǻ�: ");
	gets_s(data.publisher, SIZE);
	return data;
}
void add_record(FILE* fp) {
	BOOK data;
	data = get_record();
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
	printf("å %s�� ���������� �߰��Ͽ����ϴ�.\n\n", data.title);
}
void print_record(FILE* fp) {
	BOOK data;
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		printf("���� ����: %s\n", data.title);
		printf("����: %s\n", data.author);
		printf("���ǻ�: %s\n\n", data.publisher);
	}
	printf("��� ���� ������ ����Ͽ����ϴ�.\n\n");
}
void search_record(FILE* fp) {
	BOOK data;
	char title[SIZE];
	int check = 0;

	getchar();
	printf("ã���� �ϴ� å ������ �Է��Ͻÿ�: ");
	gets_s(title, SIZE);
	fseek(fp, 0, SEEK_SET);
	while (!feof) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(title, data.title) == 0) {
			printf("���� ����: %s\n", data.title);
			printf("����: %s\n", data.author);
			printf("���ǻ�: %s\n", data.publisher);
			printf("å %s �� ���������� ã�ҽ��ϴ�.\n\n", title);
			check = 1;
			break;
		}
	}
	if (check == 0)
		printf("ã���� �ϴ� å %s�� ã�� ���Ͽ����ϴ�.\n\n", title);
}