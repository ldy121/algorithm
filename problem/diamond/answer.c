#include <stdio.h>

#define MAX (1000)

int N, K;
int diamond[MAX];

void qsort(int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (diamond[left] > diamond[i]) {
				++j;
				k = diamond[j];
				diamond[j] = diamond[i];
				diamond[i] = k;
			}
		}
		k = diamond[j];
		diamond[j] = diamond[left];
		diamond[left] = k;

		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int main(void)
{
	int TC, tc;
	int i, j, k, answer, cache;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d\n", &N, &K);
		for (i = 0; i < N; ++i) {
			scanf("%d", &diamond[i]);
		}
		qsort(0, N - 1);
		answer = 0;
		cache = 0;
		for (i = 0; i < N; ++i) {
			if (cache != diamond[i]) {
				cache = diamond[i];
				k = 1;
				for (j = i + 1; (j < N) && ((diamond[j] - diamond[i]) <= (K)); ++j) ++k;
				if (answer < k) answer = k;
			}
		}
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}
