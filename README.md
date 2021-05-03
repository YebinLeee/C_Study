# C_language
Studying C, a functional programming language, using Visual Studio 2019 for an IDE <br>
📚 C언어 Express

<br><hr>

## <string.h> library functions

#### <string.h> 헤더 파일의 문자열 처리 라이브러리 함수
<br>


 _size_t strlen(const char *str);_

- 기능: 문자열의 길이 반환
- 인수: 문자열 주소
- 반환값: 문자열의 길(마지막 NULL값 제외)
<br>


_char *strchr(const char *str, int c);_

- 기능: 문자열에서 문자를 찾는다.
- 인수: 찾을 대상 문자열, 찾는 문자
- 반환값: 첫 번째 찾은 문자의 위치 주소, 찾지 못한 경우 NULL


_char *strstr(const char *str1, const char *str2);_

- 기능: str1에서 문자열 str1를 찾아 그 포인터를 반환
- 인수: 찾을 대상 문자열, 찾는 문자열
- 반환값: 찾은 첫 번째 문자열 포인터

<br>

_int strcmp(const char *str1, const char *str2);_

- 기능: 두 문자열 비교
- 인수: 비교할 첫 번째 문자열, 비교할 두 번째 문자열
- 반환값: str1 < str2 음수, str1 > str2 양수, 같으면 0 (사전적 순서)


_int strncmp(const char *str1, const char *str2, size_t n);_

- 기능: 두 문자열을 처음부터 n바이트까지 비교
- 인수: 첫번째 문자열, 두번째 문자열, 바이트수
- 반환값: n바이트까지 str1 < str2 음수, str1 > str2 양수, 같으면 0 (사전적 순서)


<br>

_char *strcpy_s(char *dest, rsize_t destsz, const char *src);_

- 기능: 문자열을 복사
- 인수: 복사 받을 배열 주소, 복사받을 문자열의 최대(제한) 길이, 복사할 문자열 주소
- 반환값: 복사 받을 배열 주소

_char *strncpy_s(char *dest, rsize_t destsz, const char *src, size_t n);_

- 기능: 문자열에서 n개의 문자 복사
- 인수: 복사 받을 배열 주소, 복사받을 문자열의 최대(제한) 길이, 복사할 문자열 주소, 바이트 수
- 반환값: 복사 받을 배열 주소


<br>
_char *strtok_s(char *str1, const char *delimeter, char **context);_

- 기능: 구분자 delimeter을 기준으로 str1 문자열을 토큰(token)으로 분리한다.
- 인수: 분리할 대상 문자열, 구분자 문자열, 분리된 문자열 중 두번째 문자열의 시작 주소를 저장할 포인터 변수의 주소
- 반환값: 분리한 토큰의 포인터, 토큰 분리가 끝나면 NULL

<br>


_char *strcat_s(char *dest, rsize_t destsz, const char *src);_

- 기능: 구분자 delimeter을 기준으로 str1 문자열을 토큰(token)으로 분리한다. 
- 인수: 분리할 대상 문자열, 구분자 문자열, 분리된 문자열 중 두번째 문자열의 시작 주소를 저장할 포인터 변수의 주소
- 반환값: 분리한 토큰의 포인터, 토큰 분리가 끝나면 NULL

<br><br><hr>


## FILE I/O
### 파일 포인터와 입출력 관련 라이브러리 함수들



<br>

### 파일 열기와 닫기
<br>

_FILE *fopen_s(&fp, const char *filename, const char *mode);_
- 기능: 스트림 파일을 연다.
- 인수: 파일 포인터의 주소, 파일 이름, 개방 모드
- 반환값: 성공 시 파일 포인터, 실패 시 NULL값

```c
FILE *fp1 = NULL, *fp2 = NULL; // 두 개의 파일 포인터 생성

fopen_s(&fp1, "text1.txt", "rt"); // "rt" 읽기 모드로 "text1.txt" 이름의 파일을 연다.
fopen_s(&fp2, "text2.txt", "wt"); // "wt" 쓰기 모드로 "text2.txt" 이름의 파일을 연다.
```

_int fclose(FILE *fp);_
- 기능: 스트림 파일의 버퍼를 비우고 개방된 파일을 닫는다.
- 인수: 파일 포인터
- 반환값: 성공 시 0, 실패 시 EOF 
<br>

```c
#include <stdio.h>

int main(void)
{
    FILE* fp1 = NULL, * fp2 = NULL; // 두 개의 파일 포인터 생성

    char fname1[100], fname2[100]; // 파일의 이름을 직접 입력받아 파일을 열 수 있도록 문자열 변수를 선언

    printf("첫번째 파일 이름: ");
    gets(fname1);
    fopen_s(&fp1, fname1, "rt");

    printf("두번째 파일 이름: ");
    gets(fname2);
    fopen_s(&fp2, fname2, "wt");

    if (fp1 = NULL || fp2 = NULL) {
        fprintf(stderr, "파일 열기 오류\n");
        exit(1);
    }

    fclose(fp); // 파일 닫기
    
    return 0;
  
}
```

<br><br>

### 파일 입출력 
<br>

  

종류 | 입력 함수 원형 | 출력 함수 원형
-- | -- | --
문자 단위 | int fgetc(FILE *fp); | int fputc(int c, FILE *fp);
문자열 단위 | char *fgets(char *buf, int n, FILE *fp); | int fputs(const char *buf, FILE *fp);
서식화된 입출력 | int fscanf(FILE *fp, const char *format); | fprintf(FILE *fp, const char *format);
이진 데이터 | size_t fread(void *ptr, int size, int count, FILE *fp); | size_t(const void *ptr, it size, int count, FILE *fp);




<br>

#### 문자 단위
<br>


_int fgetc(FILE *fp);_

- 기능: 스트림 파일로부터 하나의 문자를 입력받는다.
- 인수: 파일 포인터
- 반환값: 입력한 문자, 파일의 끝이거나 오류 발생시 EOF 


_int fputc(int c, FILE *fp);_

- 기능: 스트림 파일에 하나의 문자를 쓴다.
- 인수: 출력할 문자, 파일 포인터
- 반환값: 출력한 문자, 오류 발생시 EOF
<br>

```c
#include <stdio.h>

int main(void) {

	FILE* fp = NULL;
	int c; // 파일로부터 읽어드릴 문자를 저장할 변수

	// 쓰기 모드로 파일을 열어 문자 'a'를 해당 파일에 쓴다.
	fopen_s(&fp, "text.txt", "wt");
	fputc('a', fp);
	fclose(fp);

	// 읽기 모드로 파일을 열어 한 개의 문자를 파일로부터 읽는다.
	fopen_s(&fp, "text.txt", "rt");
	c = fgetc(fp);
	printf("%d: %c\n", c, c); // 해당 문자를 모니터에 정수, 문자 형태로 출력한다.
	fclose(fp);

	return 0;
}
```

<br>

#### 문자열 단위
<br>


_char *fgets(char *buf, int n, FILE *fp);_

- 기능: 스트림 파일로부터 개행 문자를 포함한 한 줄의 문자열을 입력받는다.
- 인수: 입력 데이터를 저장할 배열의 포인터, 최대 입력 문자 수, 파일 포인터
- 반환값: buf 반환, 파일 데이터를 모두 읽으면 NULL

_int *fputs(const char *buf, FILE *fp);_

- 기능: 스트림 파일에 한 줄의 문자열을 쓴다.
- 인수: 출력할 문자열, 파일 포인터
- 반환값: 음수가 아닌 값, 오류 발생 시 EOF

<br>

#### 서식화된 형식 단위
<br>

_int fscanf(FILE *fp, const char *format, ...);_

- 기능: 스트림 파일의 데이터를 형식에 따라 변환하여 변수 리스트에 입력한다.
- 인수: 파일 포인터, 형식 문자열, 변수 리스트
- 반환값: 입력에 성공한 데이터 수, 파일의 데이터를 모두 읽으면 EOF


_int fprintf(FILE *fp, const char *format, ...);_

- 기능: 데이터를 형식에 따라 변환하여 스트일 파일에 쓴다.
- 인수: 파일 포인터, 형식 문자열, 출력 데이터
- 반환값: 출력한 문자 수, 실패할 경우 음수

<br>

#### 이진 데이터 단위
<br>


_size_t fread(void *ptr, int size, int count, FILE *fp);_

- 기능: 스트림 파일에서 데이터를 읽어 void 포인터 ptr이 가리키는 배열에 저장한다.
- 인수: 읽은 데이터를 저장할 메모리 주소, 데이터 크기, 개수, 파일 포인터
- 반환값: 읽기에 성공한 데이터 개수


_size_t fwrite(void *ptr, int size, int count, FILE *fp);_

- 기능: void 포인터 ptr이 가리키는 배열의 데이터를 스트림 파일에 쓴다.
- 인수: 출력할 데이터의 메모리 주소, 데이터 크기, 개수, 파일 포인터
- 반환값: 출력에 성공한 데이터의 개수
<br>

```c
// 구조체로 저장되어 있는 학생 세 명의 정보를 이진 파일에 저장하고, 이를 다시 읽어 출력하는 프로그램

#include <stdio.h>

#define SIZE 3
// 문자열, 정수, 실수형 변수의 구조체를 새로운 자료형 STUD로 생성하여 선언
typedef struct{
	char name[20];
	int num;
	double score;
}STUD;


int main(void) {

	FILE* fp = NULL;
	// SIZE 크기의 STUD형 배열 선언
	STUD list[SIZE] = {
		{"KIM", 1, 4.5},
		{"PARK", 2, 4.3},
		{"LEE", 3, 3.7}
	};
	STUD s; // STUD형 변수 s 선언

	// 쓰기 모드로 이진 dat 파일을 열어 STUD형 배열 list에 저장된 데이터들을 파일에 쓴다.

	fopen_s(&fp, "score.dat", "wb");
	fwrite(list, sizeof(STUD), SIZE, fp); // 인수 (배열 list의 시작주소, STUD형의 크기, SIZE 개수, 파일 포인터 fp)
	fclose(fp);


	/* 읽기 모드로 파일을 열어 STUD형 배열 list에 저장된 데이터들을 파일로부터 읽어
	STUD형 변수 s에 저장한 뒤,저장된 배열 요소의 개수만큼 출력한다.*/

	fopen_s(&fp, "score.dat", "rb");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}

	for (int i = 0;i < SIZE;i++)
	{
		fread(&s, sizeof(STUD), 1, fp); // STUD형 변수 s의 주소에 접근하여 하나의 레코드를 읽어드린다.
		printf("이름 = %s, 학번 = %d, 학점 = %f\n", s.name, s.num, s.score);
	}
	fclose(fp);

	return 0;
}
```

<br>



### 기타 유용한 파일 포인터 함수
<br>

_int feof(FILE *fp);_

- 기능: 파일의 데이터를 모두 읽었는지 확인한다.
- 인수: 파일 포인터
- 반환값: 파일의 데이터를 모두 읽은 경우 0, 그렇지 않으면 0이 아닌 값


_int fseek(FILE *fp, long int offset, int origin);_

- 기능: 스트림 파일의 위치 지시자를 설정한다.
- 인수: 파일 포인터, 이동할 바이트 수, 이동할 기준 위치
- 반환값: 성공 시 0, 실패 시 0이 아닌 값



  상수 | 값 | 설명
    -- | -- | --
    SEEK_SET | 0 | 파일의 시작
    SEEK_CUR | 1 | 현재 위치
    SEEK_END | 2 | 파일의 끝

<br>

```c
#include <stdio.h>

int main(void) {
	
	FILE* fp;
	char buffer[] = "hello";

	fopen_s(&fp, "text.txt", "wt");
	fputs(buffer, fp);
	fclose(fp);

	fopen_s(&fp, "text.txt", "rt");
	fseek(fp, 1, SEEK_SET); // 파일의 시작으로부터 1바이트만큼 떨어진 곳으로 파일 위치 표시자를 이동시킴
	printf("%c\n", fgetc(fp));
	fseek(fp, -1, SEEK_END); // 파일의 끝에서부터 -1바이트만큼 떨어진 곳으로 파일 위치 표시자를 이동시킴
	printf("%c\n", fgetc(fp));
	fclose(fp);

	return 0;
}
```

<br><br><hr>

## 동적 메모리 - Dynamic Memory Allocation

<br>

### 동적 메모리의 할당과 반납
<br>

_void *malloc(size_t size);_

- 기능: 메모리를 동적으로 할당하고 포인터를 반환
- 인수: 할당할 메모리의 바이트 크기
- 반환값: 할당한 메모리의 포인터, 실패 시 NULL

_void free(void *ptr);_

- 기능: 동적 할당한 메모리를 반환
- 인수: 할당받은 메모리의 포인터
- 반환값: x

<br>

```c
int* p = NULL; // int형 포인터 선언
p = (int*)malloc(sizeof(int) * 100); // int형 4바이트를 100개만큼 할당 (total 400 bytes)하여 int형으로 형변환 한 후, 포인터에 대입
// int *p = (int*)malloc(sizeof(int) * 100); 

if (p == NULL) // 동적 할당에 실패한 경우
{
	printf("동적 메모리 할당 오류\n");
	exit(1);
}
free(p); // 메모리 반납
```
<br>

_void *calloc(size_t nitems, size_t size);_

- 기능: 메모리를 동적으로 할당하고 0으로 치과한 후에 포인터를 반환
- 인수: 할당할 항목 수, 항목 하나의 크기
- 반환값: 할당한 메모리의 포인터, 실패 시 NULL


_void *realloc(void *ptr, size_t size);_

- 기능: 동적 할당한 메모리의 크기를 재조정
- 인수: 이전에 할당받은 영역의 포인터, 재조정한 후의 전체 바이트 크기
- 반환값: 새로 할당한 메모리의 포인터, 실패 시 NULL

<br>

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int* p = NULL; // int형 포인터 선언
	p = (int*)calloc(5, sizeof(int)); // calloc() 함수를 이용하여 5개의 항목을 0으로 초기화하여 int형 정수의 메모리 크기인 4바이트만큼 할당한다. 총 20바이트 할당

	for (int i = 0;i < 5;i++)
		printf("%d ", *(p + i)); // 각 포인터가 가리키는 값을 출력
	printf("\n");

	// 동적 할당한 메모리 블록의 크기를 구하기 위해선 _msize() 함수를 사용한다.
	printf("sizeof(p)/sizeof(int) : %d \n", _msize(p) / sizeof(int));

	p = realloc(p, 7*sizeof(int)); // realloc() 함수를 이용하여 기존의 메모리 영역의 크기를 변경한다.
	if (p == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}

	printf("sizeof(p)/sizeof(int) : %d \n", _msize(p) / sizeof(int));
    
  	free(p); // 동적 메모리 반납

	return 0;
}
```

<br>

### 동적 메모리의 사용

<br>

```c
// 학생의 학점, 이름을 멤버로 갖는 구조체 배열을 동적으로 할당받아 정보를 입력받고 이를 출력하는 프로그램

#include <stdio.h>
#include <stdlib.h>

// 정수, 문자열을 멤버로 갖는 구조체 선언
typedef struct {
	int number;
	char name[10];
}STUD;

int main(void) {

	STUD* s = NULL;
	s = (STUD*)malloc(2 * sizeof(STUD)); // 구조체의 자료형과 구조체 배열 크기에 따라 메모리 할당

	if (s == NULL) {
		printf("동적 할당 오류\n");
		exit(1);
	}

	// 구조체 배열의 요소에 대한 정보를 입력받는다.
	for (int i = 0;i < 2;i++) {
		printf("학번: ");
		scanf_s("%d", &s[i].number);
		printf("이름: ");
		scanf_s("%s", s[i].name, 10);
	}

	// 구조체 배열의 요소에 대한 정보 출력
	for (int i = 0;i < 2;i++)
		printf("%d : %s\n", s[i].number, s[i].name);
	
	free(s);

	return 0;
}
```
