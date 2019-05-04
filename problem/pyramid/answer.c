#include <stdio.h>

#define min(X,Y) (((X)>(Y))?(Y):(X))

int main(void)
{
	int TC, tc;
	int N, X;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d\n", &N, &X);
		printf("#%d %d\n", tc, (min(X - 1, 2 * N - 1 - X) + 1) >= N);
	}

	return 0;
}
