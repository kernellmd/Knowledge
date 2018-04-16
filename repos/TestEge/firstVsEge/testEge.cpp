#include "graphics.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	initgraph(640, 480);

	outtextxy(100, 300, "Aloha World!");
	line(10, 10, 400, 400);

	ege::getch();
	closegraph();
	return 0;
}