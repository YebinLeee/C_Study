#include <stdio.h>
int pro1()
{
	double light_speed = 3000.00000;
	double distance = 149600000;

	double time;
	time = distance / light_speed;
	
	printf("���� �ӵ��� %lf\n", light_speed);
	printf("�¾�� �������� �Ÿ��� %lf\n", distance);
	printf("���� �ð��� %lf��\n", time);

	int min, sec;
	min = ((int)time) / 60;
	sec = (int)time % 60;
	printf("%lf�ʴ� %d�� %d���Դϴ�.\n", time, min, sec);
	return 0;
}