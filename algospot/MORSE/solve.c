#include <stdio.h>

#define MAX (100)

long long dp[MAX + 1][MAX + 1];
char answer[(MAX + 1) * 2];
long long N, M, K;

void get_answer(long long m, long long k, int start, int end)
{
	int i, j;
	long long sum, tmp;

	if (m == 0) {
		for (i = start; i < end; ++i) answer[i] = '-';
	} else if (k > 1) {
		for (i = 0, sum = 0, j = end - (int)m + 1; i <= end; ++i, --j) {
			tmp = dp[i][m - 1];
			if ((sum + tmp) >= k) {
				get_answer(m - 1, k - sum, j, end);
				break;
			} else {
				sum += tmp;
			}
		}
		for (i = start; i < (j - 1); ++i) answer[i] = '-';
		answer[j - 1] = 'o';
	} else {
		for (i = start; i < (end - (int)m); ++i) answer[i] = '-';
		while (i < end)	answer[i++] = 'o';
	}
}

int main(void)
{
	int tc, T;
	int i, j, k;
	long long sum;

	for (i = 0; i <= MAX; ++i) {
		dp[0][i] = 1;
		dp[i][0] = 1;
	}

	for (i = 1; i <= MAX; ++i) {
		for (j = 1; j <= MAX; ++j) {
			sum = 1;
			if (j <= i) {
				for (k = 1; k <= i; ++k)
					sum += dp[k][j - 1];
			} else {
				for (k = 1; k <= j; ++k)
					sum += dp[i - 1][k];
			}
			dp[i][j] = sum;
		}
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%lld %lld %lld\n", &N, &M, &K);
		get_answer(M, K, 0, N + M);

		answer[N + M] = '\0';
		printf("%s\n", answer);
	}

	return 0;
}
