#include <stdio.h>

int main(void)
{
	int TC, tc;
	int answer, x1, y1, x2, y2, x_diff, y_diff;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
		x_diff = ((x1 < x2) ? (x2 - x1) : (x1 - x2));
		y_diff = ((y1 < y2) ? (y2 - y1) : (y1 - y2));
		if (x_diff < y_diff) answer = ((y_diff - x_diff) > 1) ? (2 * (y_diff - x_diff - 1)) : 0;
		else answer = ((x_diff - y_diff) > 1) ? (2 * (x_diff - y_diff - 1)) : 0;
		answer += (x_diff + y_diff);
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
