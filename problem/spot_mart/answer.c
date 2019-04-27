#include <stdio.h>

#define MAX (1000)

int main(void)
{
	int TC, tc;
	int N, M, weight[MAX + 1];
	int i, j, k, answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d\n", &N, &M);
		answer = -1;
		for (i = 0; i < N; ++i) {
			scanf("%d\n", &weight[i]);
			for (j = 0; (answer <  M) && (j < i); ++j) {
				k = weight[i] + weight[j];
				if ((k <= M) && (answer < k)) {
					answer = k;
				}
			}
		}
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
