#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
	//p1(); // programming #1-5
	//p2(); 다시 하기
	//p3();
	//p4();
	//p5();
	//p6(); // p.531 단어개수 세기
	//p7(); // strchr, strstr 함수의 반환값: 주소, strcat_s에서의 인수
	//p8(); // p.542-3 문자열-수치 변환(sprintf_s, scanf_s, atoi, atof)
	//p9(); //문자열의 배열
	//p10(); // p.546-7 한영사전 구현(3차원 문자열배열)
	//p11(); // 암호화,복호화
	//p12(); // p.549-10 행맨 게임
	//p13(); //p.554 exercise strcat_s사용

	//p14(); // programming #6-16
	//p15();
	//p16();
	//p17();
	//p18();
	//p19();
	//p20();
	//p21();
	//p22();
	//p23();
	p24();
	
	
	return 0;
}

int p1() {
	char c;
	printf("문자를 입력하시오: ");
	scanf_s("%c", &c);
	printf("아스키 코드값=%d\n", c);
}
int p2() {
	char str[100]="";
	printf("공백 문자가 있는 문자열을 입력하시오 : ");
	gets(str);
	for (int i = 0;str[i] != NULL;i++) {
		if (str[i] == ' ') continue;
		else printf("%c",str[i]);
	}
}
int str_chr(char* s, int c) {
	int n = 0;
	for (int i = 0;s[i] != NULL;i++)
		if (s[i] == c) n++;
	return n;
}
int p3() {
	char s[50] = "", ch=NULL;
	printf("문자열 입력하시오 : ");
	gets(s);
	printf("개수를 셀 문자를 입력하시오 : ");
	scanf_s("%c", &ch);
	printf("%c의 개수 : %d\n", ch, str_chr(s, ch));
}

int p4() {
	char s[20] = "";
	printf("문자열을 입력하시오 : ");
	gets(s);
	for (char c = 'a';c <= 'z';c++)
		printf("%c : %d\n", c, str_chr(s, c));
}

int p5() {
}

int count_word(char* s);
int p6() {
	char s[50];
	printf("문자열 입력하시오 : ");
	gets(s);
	printf("문자의 개수는 %d\n", count_word(s));
}
int count_word(char* s) {
	int cnt = 0, waiting = 1;
	for (int i = 0;s[i] != NULL;i++) {
		if (isalpha(s[i])) {
			if (waiting) {
				cnt++;
				waiting = 0;
			}
		}
		else
			waiting = 1;
	}
	return cnt;
}

int p7() {
	char str[] = "dog";
	char* p = strchr(str, 'g');
	printf("%u %s %u %s\n", str,str, p,p);
	
	int loc = (int)(p - str);
	printf("%s가 %s의 %d번째에 존재\n", p, str, loc);

	char* ps = strstr(str, "og");
	printf("%u %s %u %s\n", str, str, ps, ps);
	loc = (int)(ps - p);
	printf("%s가 %s의 %d번째에 존재\n", ps, str, loc);

	char dst[100] = "hi ";
	char cpy[5] = "dog";
	strcat_s(dst, 8,cpy);
	printf("%s\n", dst);
}

int p8() {
	char filename[100]="";
	char s[100]="";

	for (int i = 0;i < 6;i++) {
		strcpy_s(filename, 100,"image");
		sprintf_s(s, 100,"%d", i);
		printf("s = %s\n", s);
		strcat_s(filename, 100,s);
		strcat_s(filename, 100,".jpg");
		printf("%s\n", filename);		
	}

	char s1[] = "100";
	char s2[] = "36.5";
	printf("%d %lf\n", atoi(s1), atof(s2));

	int i = atoi(s1);
	double d = atof(s2);
	double result = i + d;
	char buffer[50];
	sprintf_s(buffer, 50, "%f", result);
	printf("결과값 : %s\n", buffer);
	
}

int p9() {
	char* s[3] = { "init", "open","close" };
	for (int i = 0;i < 3;i++) {
		printf("%d : %s -> ",i,s[i]);
		s[i] = "hi";
		printf("%s\n",s[i]);
	}
}

#define WORDS 5
int p10() {
	int i, index;
	char dic[WORDS][2][30] = {
		{"book","책"},
		{"boy","소년"},
		{"computer","컴퓨터"},
		{"language","언어"},
		{"rain","비"},
	};
	char word[30];

	for (int i = 0;i < WORDS;i++) {
		printf("%s\n", dic[i]);
	}

	printf("단어 입력 : ");
	scanf_s("%s", word, 30);

	index = 0;
	for (i = 0;i < WORDS;i++) {
		if (strcmp(dic[i][0], word) == 0) {
			printf("%s : %s\n", word, dic[i][1]);
			return 0;
		}
	}
	printf("사전에서 발견되지 않았습니다.\n");
}

void encrypt(char* cipher, int shift) {
	for (int i = 0;cipher[i] != NULL;i++) {
		if (cipher[i] >= 'A' && cipher[i] <= 'z') {
			cipher[i] += shift;
			if (cipher[i] > 'z')
				cipher -= 26;
		}
	}
	printf("암호화된 문자열 : %s\n", cipher);
};
void decrypt(char* cipher, int shift) {
	for (int i = 0;cipher[i] != NULL;i++) {
		if (cipher[i] >= 'A' && cipher[i] < 'z') {
			cipher[i] -= shift;
			if (cipher[i] < 'A')
				cipher += 26;
		}
	}
	printf("복호화된 문자열 : %s\n", cipher);
};
void menu() {
	printf("-----------\n");
	printf("1. 암호화\n2.복호화\n");
	printf("-----------\n");
}
int p11() {
	char s[50];
	int shift = 3, choice;

	printf("문자열 입력 : ");
	gets(s);
	
	void menu();
	while (1) {
		printf("메뉴를 선택하시오(종료는 3) : ");
		scanf_s("%d", &choice);
		if (choice == 3) break;
		switch (choice) {
		case 1:encrypt(s, 3);break;
		case 2:decrypt(s, 3);break;
		default:printf("잘못 입력하셨습니다.\n");break;
		}
	}
	
}

#include <time.h>
void draw_line(char sln[], char answer[]) {
	int i;
	for (i = 0;sln[i] != NULL;i++) {
		if (isalpha(sln[i])) answer[i] = '_';
		if (isspace(sln[i])) answer[i] = ' ';
	}
	answer[i] = NULL;
}
int check(char *s, char *answer, char ch) {
	for (int i = 0;s[i] != NULL;i++)
		if (s[i] == ch) {
			answer[i] = ch;
		}
	printf("%s\n", answer);
	if (strcmp(s, answer) == 0)return 1;
	else return 0;
}
int p12() {
	srand((unsigned)time(NULL));
	char *s[7]= {"God is everything is my life",
		"I love you so much",
		"Thanks for everything",
		"How great is our God",
		"God loves you so much",
		"With God, I can do everything",
		"With God, there is nothing I can't do"	};
	char solution[100], answer[100], ch;;
	
	strcpy_s(solution, 100, s[rand()%5]);
	draw_line(solution,answer);
	printf("%s\n", answer);

	while (1) {
		printf("글자를 추측하시오: ");
		ch = getchar();
		if ((check(solution, answer, ch)) == 1) break;
		getchar();
	}
	printf("%s\n", answer);
}

int p13() {
	char s1[] = "Hi! ";
	char s2[] = "Programmers";
	char s3[100] = "";
	strcat_s(s3, 100, s1);
	strcat_s(s3, 100, s2);
	printf(s3);
}

void str_upper(char* s) {
	for (int i = 0;s[i] != NULL;i++)
		s[i] = toupper(s[i]);
}
int p14() {
	char s[20];
	printf("문자열을 입력하시오: ");
	gets(s);
	str_upper(s);
	printf("변환된 문자열: %s\n", s);
}

int get_response(char* prompt) {
	for (int i = 0;prompt[i] != NULL;i++)
		prompt[i] = toupper(prompt[i]);
	if (strcmp(prompt, "yes") == 0 || strcmp(prompt, "ok") == 0)
		return 1;
	else if (strcmp(prompt, "no") == 0)
		return 0;
	else
		return -1;

}
int p15() {
	char ans[10];
	int result;

	printf("게임을 하시겠습니까 ? ");
	gets(ans);
	
	result = get_response(ans);
	if (result == 0) printf("부정적인 답변\n");
	else if (result == 1) printf("긍정적인 답변\n");
	else printf("오류 발생\n");
}

int p16() {
	char s[20];
	char* token = NULL, * next_token = NULL;
	char seps[] = " ";
	int cnt = 0;

	printf("문자열을 입력하시오: ");
	gets(s);

	token = strtok_s(s, seps, &next_token);
	while (token != NULL) {
		cnt++;
		token = strtok_s(NULL, seps, &next_token);
	}

	printf("단어의 수는 %d입니다.\n", cnt);
}

int p17() {
	char s[20] = "";
	int i = 0;

	printf("텍스트를 입력하시오 : ");
	gets(s);

	if(islower(s[i])) s[i]=toupper(s[i]);
	if (s[strlen(s)-1] != '.') s[strlen(s)] = '.';
	s[strlen(s) + 1] = NULL;

	printf("수정된 텍스트: %s\n", s);
}

int p18() {
	char s[20];
	int check = 0;

	printf("문자열을 입력하시오 : ");
	gets(s);

	for (int i = 0;s[i] != NULL;i++)
		s[i] = tolower(s[i]);
	for (int i = 0;i < strlen(s) / 2;i++) {
		if (s[i] != s[strlen(s)-1-i]){
			check = 1;
			break;
		}
	}
	if (check==1) printf("회문 문자가 아닙니다.\n");
	else printf("회문 문자입니다.\n");
}

int p19() {
	char s[20];
	char *token=NULL, * tok[10] = { 0 }, * next_token = NULL;
	char seps[] = " ";
	int n = 0;

	printf("문자열을 입력하시오: ");
	gets(s);

	token = strtok_s(s, seps, &next_token);
	while (token != NULL) {
		tok[n] = token;
		printf("%p: tok[%d] = %s\n", token, n, tok[n]);
		n++;
		token = strtok_s(NULL, seps, &next_token);
	}
	n--;

	for (int i = n;i >= 0;i--)
		printf("%s ", tok[i]);
	printf("\n");
}

int p20() {
	char name[20];
	char* surname, * mainname;
	char* token = NULL, * next = NULL, seps[] = " ";

	printf("성과 이름을 대문자로 입력하시오: ");
	gets(name);
	
	for (int i = 0;name[i] != NULL;i++)
		name[i] = tolower(name[i]);

	token = strtok_s(name, seps, &next);
	surname = token;
	token = strtok_s(NULL, seps, &next);
	mainname = token;

	printf("%s, %s\n", mainname, surname);
}

int p21() {
	char s[20];
	int cnt = 0;

	printf("문자열을 입력하시오 : ");
	gets(s);

	for (int i = 0;s[i] != NULL;i++)
		if (s[i] == '.' || s[i] == ',')
			cnt++;
	printf("구두점의 개수는 %d입니다.\n", cnt);
}

int p22() {
	char s[80], target[10], change[10], new[80]="";
	char* token = NULL, * next = NULL;
	char seps[] = " ";

	printf("문자열을 입력하시오 : ");
	gets(s);
	printf("찾을 문자열: ");
	gets(target);
	printf("바꿀 문자열: ");
	gets(change);

	token = strtok_s(s, seps, &next);
	while (token != NULL) {
		if (strcmp(token, target) == 0) strcat_s(new, 80, change);
		else strcat_s(new, 80, token);
		strcat_s(new, 80, " ");
		token = strtok_s(NULL, seps, &next);
	}
	printf("수정된 문자열: %s\n", new);
}

int p23() {
	char s[5];
	int x, y, result = 0;

	printf("연산을 입력하시오 : ");
	scanf_s("%s %d %d", s, 5, &x, &y);
	if (strcmp(s,"add") == 0) result = x + y;
	else if (strcmp(s, "sub") == 0)result = x - y;
	else if (strcmp(s, "mul") == 0)result = x * y;
	else if (strcmp(s, "div") == 0)result = x / y;
	else printf("잘못 입력하셨습니다.\n");

	printf("연산의 결과 : %d\n", result);
}

int p24() {
	char s[30];
	char* p = NULL, *p2=NULL;
	
	printf("광고하고 싶은 텍스트를 입력하시오: ");
	gets(s);
	p = s, p2=s;

	printf("=======================\n");
	for (p = s;p != NULL;p++) {
		int loc = p - p2;
		for(int i=0;i<loc;i++)
			printf("%c", p2[i]);
		printf("%s\n", p);
	}
}