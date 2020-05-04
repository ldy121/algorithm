#include <stdio.h>

#define MAX (200)
#define INVALID (-1.f)
#define INIT (250.f)

double dp[MAX + 1][MAX + 1];
double position[MAX + 1];

int N, M;

double get_answer(int m, int n)
{
	int i;
	double ret, tmp;

	if (dp[m][n] != INVALID) {
		ret = dp[m][n];
	} else if (n == 2) {
		ret = dp[m][2] = position[M - 1] - position[m];
	} else if ((M - m) == n) {
		ret = INIT;
		for (i = m + 1; i < M; ++i) {
			if (ret > (position[i] - position[i - 1]))
				ret = position[i] - position[i - 1];
		}
		dp[m][n] = ret;
	} else {
		ret = INVALID;
		for (i = m + 1; (i < M) && ((n - 1) <= (M - i)); ++i) {
			tmp = get_answer(i, n - 1);
			if ((position[i] - position[m]) < tmp)
				tmp = position[i] - position[m];
			if (ret < tmp)
				ret = tmp;
		}
		dp[m][n] = ret;
	}

	return ret;
}

int main(void)
{
	int tc, T;
	int i, j;
	double answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < M; ++i) {
			scanf("%lf", &position[i]);
			for (j = 0; j <= N; ++j) {
				dp[i][j] = INVALID;
			}
		}
		answer = get_answer(0, N);
		printf("%.2f\n", answer);
	}

	return 0;
}
