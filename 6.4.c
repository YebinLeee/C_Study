#include <stdio.h>

int main(void)
{
	int num, random;

	printf("선택하시오(1가위 2:바위 3:보)");
	scanf("%d", &num);

	random = (rand() % 3 + 1);

	if (num == 1) {
		if (random == 3)
			printf("사용자가 이겼음 \n컴퓨터의 선택: %d\n", random);
		else if (random==1)
			printf("사용자와 비겼음 \n컴퓨터의 선택: %d\n", random);
		else
			printf("사용자가 졌음 \n컴퓨터의 선택: %d\n", random);
	}
	else if (num == 2) {
		if (random == 1)
			printf("사용자가 이겼음 \n컴퓨터의 선택: %d\n", random);
		if (random == 2)
			printf("사용자와 비겼음 \n컴퓨터의 선택: %d\n", random);
		else
			printf("사용자가 졌음 \n컴퓨터의 선택: %d\n", random);
	}
	else {
		if (random == 2)
			printf("사용자가 이겼음 \n컴퓨터의 선택: %d\n", random);
		if (random == 3)
			printf("사용자와 비겼음 \n컴퓨터의 선택: %d\n", random);
		else
			printf("사용자가 졌음 \n컴퓨터의 선택: %d\n", random);
	}

	return 0;
}