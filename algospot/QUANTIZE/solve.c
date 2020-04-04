#include <stdio.h>

#define MAX (100)
#define INVALID (-1)

int n[MAX + 1];
int dp[MAX + 1][MAX + 1];
int sub_dp[MAX + 1][MAX + 1];
int S, N;
int answer;

void qsort(int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (n[i] < n[left]) {
				++j;

				k = n[j];
				n[j] = n[i];
				n[i] = k;
			}
		}

		k = n[j];
		n[j] = n[left];
		n[left] = k;

		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int get_min(int src, int dst)
{
	int i, j, k;
	int ret;

	if (sub_dp[src][dst] == INVALID) {
		ret = INVALID;
		for (i = n[src]; i <= n[dst]; ++i) {
			k = 0;
			for (j = src; j <= dst; ++j) {
				k += (n[j] - i) * (n[j] - i);
			}
			if ((ret == INVALID) || (k < ret))
				ret = k;
		}
		sub_dp[src][dst] = ret;
	} else {
		ret = sub_dp[src][dst];
	}

	return ret;
}

int get_answer(int src, int s)
{
	int i, dst;
	int ret, tmp1, tmp2;

	if (dp[s][src] == INVALID) {
		dst = N - s;

		if (s > 0) {
			ret = INVALID;
			for (i = src; i <= dst; ++i) {
				tmp1 = get_min(src, i);
				tmp2 = get_answer(i + 1, s - 1);
				if ((ret == INVALID) || ((tmp1 + tmp2) < ret))
					ret = tmp1 + tmp2;
			}
		} else {
			ret = get_min(src, dst);
		}
		dp[s][src] = ret;
	} else {
		ret = dp[s][src];
	}

	return ret;
}

int main(void)
{
	int tc, T;
	int i, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &S);
		for (i = 1; i <= N; ++i)
			scanf("%d ", &n[i]);

		for (i = 0; i <= N; ++i) {
			for (j = 0; j <= N; ++j) {
				sub_dp[i][j] = INVALID;
				dp[i][j] = INVALID;
			}
		}

		qsort(1, N);

		answer = 0;
		if (N > S) {
			answer = get_answer(1, S - 1);
		} else {
			answer = 0;
		}

		printf("%d\n", answer);
	}

	return 0;
}

