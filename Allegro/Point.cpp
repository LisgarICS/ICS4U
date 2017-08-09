// sierpinski triangle for 4U using classes and Allegro 5
#include <iostream>
#include <allegro5/allegro.h>
#include "Point.h"


void POINT::midPoint(POINT a, POINT b) {
	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;
}

void POINT::midPoint(POINT a) {
	x = (x + a.x) / 2;
	y = (y + a.y) / 2;
}

void POINT::putPoint() {
	al_draw_pixel(x, y, al_map_rgb(255, 255, 255));		// white
}

