#include <stdio.h>
int pro2()
{
	int id, password;
	printf("아이디와 패스워드를 4개의 숫자로 입력하시오: \n");
	printf("id: ____\b\b\b\b");	// \b는 화면의 커서를 뒤로 움직이는 제어문자이다.
	scanf_s("%d", &id);
	printf("pw: ____\b\b\b\b");
	scanf_s("%d", &password);

	printf("\a입력된 아이디는 \"%d\"이고 입력된 패스워든 \"%d\"입니다.\n", id, password);
	// 화면에 ""큰따옴표를 출력하고 싶다면, \""\를 사용하면 된다.

}