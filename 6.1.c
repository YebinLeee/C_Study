#include <stdio.h>

int main(void)
{
	char ch;
	printf("���ڸ� �Է��Ͻÿ�: ");
	ch = getchar();
	
	switch(ch){
		case 'a':
			printf("�����Դϴ�.\n");
			break;
		case 'e':
			printf("�����Դϴ�.\n");
			break;
		case 'i':
			printf("�����Դϴ�.\n");
			break;
		case 'o':
			printf("�����Դϴ�.\n");
			break;
		case 'u':
			printf("�����Դϴ�.\n");
			break;
		default: printf("�����Դϴ�.\n");
			break;
	}
	return 0;
}