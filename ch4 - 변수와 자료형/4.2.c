#include <stdio.h>
int pro5()
{
	int num;
	printf("16진수 정수를 입력하시오: ");
	scanf_s("%x", &num);

	printf("8진수로는 %#o입니다.\n", num); // 8진수 표기법은 %o이다. 0을 붙여 출력하려면 #기호를 이용
	
	printf("10진수로는 %#d입니다.\n", num); // 10진수 정수 표기법은 %d이다.
	
									 // 포인터와 같이 메모리 주소값이 명확히 양수만 있는 경우에는 unsigned int를 의미하는 %u를 사용하기.
	printf("16진수로는 %#x입니다.\n", num); // 16진수 표기법은 %x이다.

	return 0;
}