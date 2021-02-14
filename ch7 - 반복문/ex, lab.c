#include <stdio.h>
//p. 267 구구단 프로그램
int p1()
{
	int n;
	printf("단을 입력하시오: ");
	scanf_s("%d", &n);
	
	// for문 이용하기
	for (int i = 1;i <= 9;i++)
		printf("%d * %d = %d\n", n, i, n * i);
	//while문 이용하기
	int i = 1;
	while (i <= 9)
	{
		printf("%d * %d = %d\n", n, i, n * i);
		i++;
	}
	return 0;
}
// 1부터 n까지의 의 숫자의 세제곱 출력하는 프로그램
int p2()
{
	int n;
	int i = 1;
	printf("숫자를 입력하시오: ");
	scanf_s("%d", &n);
	printf("----------------------\n");
	
	while ( i <= n) {
		printf("%5d %5d\n", i, i * i * i);
		i++;
	}
	printf("----------------------\n");
	return 0;
}
int p3()
{
	int students,grade, average, sum = 0;
	printf("학생의 수는? : ");
	scanf_s("%d", &students);
	for (int i = 1;i <= students;i++) {
		printf("학생 %d의 성적을 입력하시오: ", i);
		scanf_s("%d", &grade);
		sum += grade;
	}
	average = sum / students;
	printf("학생들의 평균 성적은 %d입니다.\n", average);

	//배열로 나타내기
	/*
	int grades[10]={0};
	for (int i=0;i<10;i++){
		printf("학생 %d의 성적을 입력하시오: );
		scanf_s("%d", &grades[i]);
		sum += grades[i]);
		}
	average = sum / 10;
	printf("학생들의 평균 성적은 %d입니다. \n", average);
	*/
	
	return 0;
}
// p.276 최대 공약수 구하는 프로그램
int p4()
{
	int x, y, r;
	printf("두 수를 입력하시오(큰 수를 먼저): ");
	scanf_s("%d %d", &x, &y);
	
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	printf("%최대 공약수는 %d입니다.\n", x);

	return 0;
}
//p.278 반감기 프로그램
int p5()
{
	int years=0, halflife;
	int initial;
	printf("원소의 원래 양을 입력하시오: ");
	scanf_s("%d", &initial);
	int current = initial;

	printf("원소의 반감기를 입력하시오: ");
	scanf_s("%d", &halflife);

	while (current >= initial * 0.1) {
		years += halflife;
		current =current / 2.0;
		printf("%d년 뒤 남은 원소의 양.= %d \n", years, current);
	}
	printf("양이 1/10이 되기까지 걸린 시간: %d년\n\n", years);
	return 0;
}
// 도전문제 (1)
int p6()
{
	int initial = 10;
	double current = initial;
	int quarter_num = 4;
	int hours=1;
	while (hours <= 7) {
		current *= 4;
		printf("%d시간 뒤의 세균의 수 = %lf\n", hours, current);
		hours++;
	}
	return 0;
}
// 도전문제 (2)
int p7()
{
	unsigned int current = 1;
	for (int i = 0;i < 30;i++)
		current = current * 2;
	
	printf("종이를 50번 접은 후 두께는 %u입니다.\n\n", current);
	return 0;
}
//p.281 do...while문 이용하여 메뉴판 선택
int p8()
{
	int ans;
	printf("1--새로만들기\n");
	printf("2--파일열기\n");
	printf("3--파일닫기\n");
	do {
		printf("메뉴 중 하나를 선택하시오: ");
		scanf_s("%d", &ans);
	} while (ans < 1 || ans>3);
	printf("선택된 메뉴 = %d\n\n", ans);

	return 0;
}

#include <stdlib.h>
#include <time.h>
//p.282 숫자 찾기 게임
int p9(){

	srand((unsigned)time(NULL));
	int guess;
	int ans = rand() % 100;
	int tries = 0;
	do {
		tries++;
		printf("수를 입력하시오: ");
		scanf_s("%d", &guess);
		if (guess > ans)
			printf("입력하신 수는 답보다 큽니다.\n");
		else
			printf("입력하신 수는 답보다 작습니다.\n");
	} while (guess != ans);

	printf("축하합니다! 시도 횟수는 총 %d번입니다.\n", tries);
	return 0;
}

// p.289 n! factorial 값 구하는 프로그램
int p10() {
	int n;
	int factorial = 1;
	printf("n을 입력하시오: ");
	scanf_s("%d", &n);
	for (int i = 1;i <= n;i++)
		factorial *= i;
	printf("%d!의 값은 %d입니다.\n\n", n, factorial);
	return 0;
}
// 피타고라스의 법칙을 만족하는 직각삼각형의 세 변 구하기
int p18()
{
	int a, b, c;
	for (a = 1;a <= 100;a++)
		for (b = 1;b <= 100;b++)
			for (c = 1;c <= 100;c++)
				if ((a* a + b * b == c * c) && (a<b) && (b<c))
					printf("%d %d %d\n", a, b, c);

	return 0;
}
// 세 주사위를 던져 합이 10이 되는 프로그램
int p19()
{
	int a, b, c;
	
	for (a = 1;a <= 6;a++)
		for (b = 1;b <= 6;b++)
			for (c = 1;c <= 6;c++)
				if ((a + b + c == 10) && (a < b))
					printf("%d %d %d\n", a, b, c);
	return 0;
}

#define SEED_MONEY 1000000
// p.298 재태크 계산 프로그램 break문 사용
int p20()
{
	int year = 0;
	int money = SEED_MONEY;

	while (1)
	{
		money += SEED_MONEY * 0.30;
		year++;
		if (money >= SEED_MONEY * 10)
			break;
	}
	printf("%년\n\n", year);
	return 0;
}

// p.300 continue문 사용하기
int p21() {
	int n;
	
	for (int i = 0;i <= 10;i++)
	{
		if (i % 3 == 0)
			continue;
		printf("%d ", i);
	}
	return 0;
}
// p. 310 소문자를 대문자로 바꾸기
int p22()
{
	char letter;
	while (1)
	{
		printf("소문자를 입력하시오: ");
		scanf_s(" %c", &letter);
		if (letter == 'Q')
			break;
		if (letter < 'a' || letter>'z')
			continue;
		letter -= 32;
		printf("해당 소문자는 대문자로 %c 입니다.\n\n", letter);
	}
	return 0;
}

//p.304 수학 사친연산 프로그램
int p23()
{
	srand((unsigned)time(NULL));

	int x, y, guess, ans;
	char opc=0;
	int op;
	for (int i = 0;i < 10;i++) {
		
		op = rand() % 4 + 1;
		x = rand() % 10;
		y = rand() % 10;

		switch (op) {
		case 1: opc = '+'; ans = x + y; break;
		case 2:opc = '-';ans = x - y;break;
		case 3: opc = '*';ans = x * y;break;
		case 4:opc = '/';ans = x / y;break;
		}

		printf("%d %c %d = ", x, opc, y);
		scanf_s("%d", &guess);
		while (guess != ans)
		{
			printf("틀렸습니다. 다시 시도하세요.\n\n");
			printf("%d %c %d = ", x, opc, y);
			scanf_s("%d", &guess);
		}
		printf("맞았습니다.\n");
	
	}
	return 0;
}
#include <time.h>
#include <stdlib.h>

// p.305 while문, break문 사용 예제 게임
#define INITIAL 50
int p24(){

	srand((unsigned)time(NULL));
	int money = INITIAL;
	int result;

	int n = 1;
	while (n <= 50) {
		result = rand() % 2;
		n++;
		if (result == 1)
			money++;
		else
			money--;
		if (money >= 250)
			break;
	}
	printf("100번중 %d번 만에 250달러를 달성했습니다.\n\n", n);
	return 0;
}