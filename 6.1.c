#include <stdio.h>

int main(void)
{
	char ch;
	printf("문자를 입력하시오: ");
	ch = getchar();
	
	switch(ch){
		case 'a':
			printf("모음입니다.\n");
			break;
		case 'e':
			printf("모음입니다.\n");
			break;
		case 'i':
			printf("모음입니다.\n");
			break;
		case 'o':
			printf("모음입니다.\n");
			break;
		case 'u':
			printf("모음입니다.\n");
			break;
		default: printf("자음입니다.\n");
			break;
	}
	return 0;
}