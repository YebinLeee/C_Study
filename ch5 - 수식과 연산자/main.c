#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//p1();
	//p2();
	//p3();
	//p4();
	//p5();
	//p6();

	/*
	pro1();
	pro2();
	 pro3();
	pro4();
	pro5();
	pro6();
	pro7();
	pro8();
	pro9();
	pro10();
	pro11();
	pro12();
	*/
	
	for (int i = 0;i < 20;i++)
		printf("%lf ",(double)rand()/ RAND_MAX *4.3);
	return 0;
}