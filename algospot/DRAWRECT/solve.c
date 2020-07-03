#include <stdio.h>

int main(void)
{
	int tc, T;
	int x1, x2, y1, y2;
	int x, y;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &x1, &y1);
		scanf("%d %d\n", &x2, &y2);
		scanf("%d %d\n", &x, &y);

		if (x1 != x2) x = x1 + x2 - x;
		if (y1 != y2) y = y1 + y2 - y;

		printf("%d %d\n", x, y);
	}

	return 0;
}
