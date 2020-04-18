#include <stdio.h>

#define MAX (1000)

double answer[MAX + 1][((MAX + 1) * 2) + 1];

int n, m;

int main(void)
{
	int tc, T;
	int min, max, i, j;
	double Answer;

	for (i = 0; i <= MAX; ++i) {
		for (j = 0; j <= ((MAX + 1) * 2); ++j) {
			answer[i][j] = 0.f;
		}
	}

	min = 1;
	max = 2;
	answer[1][1] = 0.25f;
	answer[1][2] = 0.75f;

	for (i = 2; i <= MAX; ++i) {
		for (j = min; j <= max; ++j) {
			answer[i][j + 1] += answer[i - 1][j] * 0.25f;
			answer[i][j + 2] += answer[i - 1][j] * 0.75f;
		}
		min = min + 1;
		max = max + 2;
	}


//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &n, &m);
		Answer = 0.f;

		for (i = n; i <= ((MAX + 1) * 2); ++i) {
			Answer += answer[m][i];
		}

		printf("%.10f\n", Answer);
	}

	return 0;
}

