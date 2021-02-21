#pragma once
typedef struct rect {
	int x, y, w, h;
}RECT;

void draw_rect(const RECT*);
double calc_area(const RECT*);
void move_rect(RECT*, int, int); // 원점을 이동하게 되므로 const키워드를 붙여서는 안 된다
