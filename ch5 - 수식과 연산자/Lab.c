#include <stdio.h>
//p.180 거스름돈 계산 :Lab
int p3()
{
	int price, money, change;
	int change5000, change1000, change500, change100;

	printf("물건 값을 입력하시오: ");
	scanf_s("%d", &price);
	printf("사용자가 낸 돈: ");
	scanf_s("%d", &money);
	
	change = price - money;	// 물건 값에서 사용자가 낸 돈 (나머지 값)을 계산한다.
	change5000 = change / 5000;	//5000원 거스름돈은 change를 5000원으로 나눈 몫이다.
	change = change % change5000;	// change에서 5000원으로 나눈 나머지값을 다시 대입한다.

	change1000 = change / 1000;	// change를 1000으로 나눈 몫이 1000원 거스름돈 개수이다.
	change = change % change1000;	// change를 1000으로 나눈 후의 나머지값을 대입한다.

	change500 = change / 500;
	change = change % change500;

	change100 = change / 100;

	printf("오천원권: %d\n", change5000);
	printf("천원권: %d\n", change1000);
	printf("오백원권: %d\n", change500);
	printf("백원권: %d\n\n", change100);

	return 0;
}

// p. 192 윤년 판단
int p4()
{
	int year;
	printf("연도를 입력하시오: ");
	scanf_s("%d", &year);
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		printf("%d년도는 윤년입니다.\n", year);
	else
		printf("%d년도는 윤년이 아닙니다.\n", year);
		
	return 0;
}

// p.201  lab 10진수를 2진수로 바꾸기
int p5()
{
	unsigned int num;	// 부호 없는 unsingd int형 정수 변수 num 선언.
	printf("10진수 정수를 입력하시오: "); // 128(2진수 : 10000000)보다 작은 수 입력받기
	scanf_s("%d", &num);
	printf("10진수: %d\n", num);
	printf("2진수: ");

	unsigned int mask = 1 << 7;	// '1'을 7비트 앞당겨, 하나씩 num과 mask의 비트를 비교할 것이다. &연산자를 이용하여
	// num의 비트 중 1이 있다면, mask와 num이 만나 1이 계산 될 것이다. 이를 8번 반복하면 된다.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;

	printf("\n\n");

	return 0;
}

//p. 202 XOR을 이용한 암호화
int p6()
{
	char data, key = 0xff;
	printf("원래 데이터를 입력하시오: ");
	scanf_s(" %c", &data);

	char encrpted_data = data ^ key;
	printf("암호화된 문자= %c  \n", encrpted_data);

	char orig_data = encrpted_data ^ key;
	printf("원래의 데이터 = %c \n\n", data);

	return 0;
}