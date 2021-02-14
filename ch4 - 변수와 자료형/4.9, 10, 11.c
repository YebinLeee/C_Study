#include <stdio.h>
int pro12()
{
	char code = 'a';
	printf("%c %c %c\n", code + 1, code + 2, code + 3);


	printf("\a화재가 발생하였습니다.");

	printf("\"ASCII CODE\", \'A\', \'B\', \'C\'\n");
	printf("\\t \\a \\n \n");
	return 0;
}