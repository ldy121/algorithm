#include <stdio.h>

#define MAX (1000000)

int input[MAX + 1];
int answer[MAX + 1];

int main(void)
{
	int TC, T;
	int i, ans, j, k, N;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &input[i]);
			answer[i] = 0;
		}

		ans = input[0];
		answer[0] = input[0];
		for (i = 1; i < N; ++i) {
			j = ((i - 2) >= 0) ? (answer[i - 2]) : (0);
			k = ((i - 3) >= 0) ? (answer[i - 3]) : (0);
			answer[i] = (j > k) ? (j + input[i]) : (k + input[i]);
			if (ans < answer[i])
				ans = answer[i];
		}

		printf("#%d %d\n", T, ans);
	}
}
