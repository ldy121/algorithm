#include <stdio.h>

#define MAX (100000)

int main(void)
{
	int T, K, N, TC;
	int i, j, k;
	int numbers[MAX + 1];
	int input[MAX + 1];
	int answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d", &N, &K);
		for (i = 0; i <= K; ++i) {
			numbers[i] = 0;
		}

		for (answer = k = i = j = 0; j < N; ++j) {
			scanf("%d", &input[j]);
			if (numbers[input[j]] == 0) {
				++k;
			}
			++numbers[input[j]];
			while (k == K) {
				answer += (N - j);
				if (numbers[input[i]] == 1) {
					--k;
				}
				--numbers[input[i++]];
			}
		}
		printf("#%d %d\n", T, answer);
	}
}

