#include <iostream>

using namespace std;


void drawLine(char[] screen, int width, int x1, int x2, int y) {
	char * row = screen + ((width / 8) * y);
	int src = x1 / 8;
	int dst = x2 / 8;
	row[src] = (1 << (8 - (x1 % 8))) - 1;
	row[dst] = ((1 << (x2 % 8)) - 1) << (x2 % 8);
	for (int i = src + 1; i < dst; ++i) {
		row[i] = 0xff;
	}
}
