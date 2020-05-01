#include <stdio.h>

#define MAX (100)
#define INVALID (-1)

int dp[MAX + 1][MAX + 1];
int N, M;
long long n[MAX + 1];
long long m[MAX + 1];

int get_answer(int index_n, int index_m, long long num)
{
	int ret, tmp;
	int i, j;

	if (dp[index_n][index_m] == INVALID) {
		ret = 0;
		for (i = index_n; i < N; ++i) {
			if (n[i] > num) {
				tmp = get_answer(i + 1, index_m, n[i]) + 1;
				if (tmp > ret) ret = tmp;
			}
		}

		for (i = index_m; i < M; ++i) {
			if (m[i] > num) {
				tmp = get_answer(index_n, i + 1, m[i]) + 1;
				if (tmp > ret) ret = tmp;
			}
		}

		dp[index_n][index_m] = ret;
	} else {
		ret = dp[index_n][index_m];
	}

	return ret;
}

int main(void)
{
	int tc, T;
	int i, j, answer, tmp, tmp1, tmp2;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < N; ++i)
			scanf("%lld ", &n[i]);

		for (i = 0; i < M; ++i)
			scanf("%lld ", &m[i]);

		for (i = 0; i <= N; ++i) {
			for (j = 0; j <= M; ++j) {
				dp[i][j] = INVALID;
			}
		}

		answer = 0;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < M; ++j) {
				if (n[i] == m[j]) {
					tmp1 = get_answer(i + 1, j, n[i]) + 1;
					tmp2 = get_answer(i, j + 1, m[j]) + 1;
					tmp = ((tmp1 > tmp2) ? (tmp1) : (tmp2));
				} else if (n[i] < m[j]) {
					tmp = get_answer(i + 1, j, n[i]) + 1;
				} else {
					tmp = get_answer(i, j + 1, m[j]) + 1;
				}

				if (tmp > answer)
					answer = tmp;
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}
