#include <stdio.h>
int pro1()
{
	double light_speed = 3000.00000;
	double distance = 149600000;

	double time;
	time = distance / light_speed;
	
	printf("빛의 속도는 %lf\n", light_speed);
	printf("태양과 지구와의 거리는 %lf\n", distance);
	printf("도달 시간은 %lf초\n", time);

	int min, sec;
	min = ((int)time) / 60;
	sec = (int)time % 60;
	printf("%lf초는 %d분 %d초입니다.\n", time, min, sec);
	return 0;
}