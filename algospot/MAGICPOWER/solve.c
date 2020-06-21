#include <stdio.h>

#define MAX (10000)

int map[MAX + 1];

int main(void)
{
	int tc, T;
	int i, j, answer, max;
	int N, M;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i <= MAX; ++i) {
			map[i] = 0;
		}

		max = 0;
		for (i = 0; i < N; ++i) {
			scanf("%d", &j);
			++map[j];
			if (max < j) max = j;
		}

		answer = 0;
		for (i = 0; i < M; ++i) {
			while ((map[max] == 0) && (max > 0)) --max;
			answer += max;

			++map[max - 1];
			--map[max];
		}

		printf("%d\n", answer);
	}

	return 0;
}
