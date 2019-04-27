#include <stdio.h>

#define MAX (1000000)

int T[MAX];
int D[MAX];

void qsort(int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (D[left] < D[i]) {
				++j;
				k = T[i];
				T[i] = T[j];
				T[j] = k;
				k = D[i];
				D[i] = D[j];
				D[j] = k;
			}
		}
		k = T[left];
		T[left] = T[j];
		T[j] = k;
		k = D[left];
		D[left] = D[j];
		D[j] = k;
		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int main(void)
{
	int TC, tc;
	int N, i, answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d %d\n", &T[i], &D[i]);
		}
		qsort(0, N - 1);
		answer = D[0] - T[0];
		for (i = 1; i < N; ++i) {
			if (answer > D[i]) {
				answer = D[i] - T[i];
			} else {
				answer -= T[i];
			}
		}
		printf("#%d %d\n", tc, answer);
	}
}
