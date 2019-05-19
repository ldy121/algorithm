#include <stdio.h>

#define MAX (999)

int P[MAX + 1];

int main(void)
{
	int TC, tc;
	int answer, i, j, k, N;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &N);
		for (i = 1; i <= N; ++i) {
			scanf("%d", &P[i]);
		}
		for (answer = 0, i = 1; i <= N; ++i) {
			if ((i % 3) != (P[i] % 3)) {
				for (j = i + 1; j <= N; ++j) {
					if (((j % 3) != (P[j] % 3)) && ((P[j] % 3) == (i % 3))) {
						k = j;
						if ((P[i] % 3) == (j % 3)) {
							break;
						}
					}
				}
				j = P[i];
				P[i] = P[k];
				P[k] = j;
				++answer;
			}
		}
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
