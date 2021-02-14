#include <stdio.h>
#define USA
#define PI 3.141592
int main(void) {
	//p1();
	//p2(); // programming #2-10
	//p3();
	//p4();
	//p5();
	p6();
	//p7();

	return 0;
}

#define SQUARE(n) ((n)*(n))
int p1() {
	double r;
#ifdef KOR
	printf("원의 반지름을 입력하시오: ");
	scanf_s("%lf", &r);
	printf("area(%f)가 호출되었음\n원의 면적은 %lf입니다.\n", r, SQUARE(r));
#endif
#ifdef USA
	printf("Please enter radius of a circle(inch): ");
	scanf_s("%lf", &r);
	printf("area(%f)is called\narea of the circle is %lf\n", r, SQUARE(r));
#endif
}

#define GET_MIN(x,y,z) ((x)<(y)?((x)<(z)?(x):(z)):((y)<(z)?(y):(z)))
int p2() {
	int x, y, z;
	printf("3개의 정수를 입력하시오: ");
	scanf_s("%d %d %d", &x, &y, &z);
	printf("최소값은 %d입니다.\n", GET_MIN(x, y, z));
}

#define ARRAY_INIT(array,size,value) for(int i=0;i<size;i++){array[i]=value;};
int p3() {
	int n, arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("원소를 모두 어떤 수로 바꾸시겠습니까? ");
	scanf_s("%d", &n);
	ARRAY_INIT(arr, 10, n);
	printf("{ ");
	for (int i = 0;i < 10;i++)
		printf("%d ", arr[i]);
	printf("}\n");
}

#define VOLUME(n,h) (PI*SQUARE(n)*(h))
int p4() {
	int r, h;
	printf("원기둥의 반지름을 입력하시오: ");
	scanf_s("%d", &r);
	printf("원기둥의 높이를 입력하시오: ");
	scanf_s("%d", &h);

	printf("원기둥의 부피 = %f\n", VOLUME(r, h));
}

#define IS_SPACE(c)((c==' '||c=='\t'||c=='\n')?1:0)
int p5() {
	char s[20];
	int cnt = 0;
	printf("문자열을 입력하시오: ");
	gets(s);

	for(int i=0;s[i]!=NULL;i++)
		if((IS_SPACE(s[i]))==1) cnt++;
	printf("공백 문자의 개수  : %d\n", cnt);
}

#define display_bit(c) c^=32
int p6() {
	char s[20];
	printf("문자열 입력 : ");
	gets(s);
	for (int i = 0;s[i] != NULL;i++)
		putchar(display_bit(s[i]));

}