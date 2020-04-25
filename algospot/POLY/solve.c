#include <stdio.h>

#define INVALID (-1)
#define MAX (100)
#define MODULE (10000000)
#define SUM (0)

int answer[MAX + 1][MAX + 1];

int main(void)
{
	int tc, T;
	int i, j, k, t;

	for (i = 0; i <= MAX; ++i) {
		for (j = 0; j <= MAX; ++j) {
			answer[i][j] = 0;
		}
	}

	answer[1][1]	= 1;
	answer[1][SUM]	= 1;

	for (i = 2; i <= MAX; ++i) {
		answer[i][i] = 1;
		for (j = 1; j < i; ++j) {
			answer[i][j] = 0;
			for (k = 1; k <= (i - j); ++k) {
				answer[i][j] = (((answer[i - j][k]) * (j + k - 1)) + answer[i][j]) % MODULE;
			}
		}

		answer[i][SUM] = 0;
		for (j = 1; j <= i; ++j) {
			answer[i][SUM] = (answer[i][j] + answer[i][SUM]) % MODULE;
		}
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &i);
		printf("%d\n", answer[i][SUM]);
	}

	return 0;
}
