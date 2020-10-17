#include <stdio.h>

#define MAX (30)

double answer[MAX + 1][MAX + 1];
double win, lose;
int P, K;

int main(void)
{
	int tc, T;
	int i, j, k, ans;
	double tmp;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &P, &K);

		K = K * 2 - 1;
		for (i = 0; i <= K; ++i) {
			for (j = 0; j <= K; ++j) {
				answer[i][j] = 0.f;
			}
		}

		win = (double)((double)P / (double)100.f);
		lose = (double)((double)1.f - win);

		answer[0][0] = 1.f;
		answer[1][0] = win;
		answer[0][1] = lose;
		for (i = 1; i < K; ++i) {
			for (j = i, k = 0; (j >= 0) && (k <= i); --j, ++k) {
				answer[j + 1][k] += (answer[j][k] * win);
				answer[j][k + 1] += (answer[j][k] * lose);
			}
		}

		for (tmp = (double)0.f, i = K; i > (K / 2); --i) {
			tmp += answer[i][K - i];
		}

		tmp = (double)(tmp + (double)(0.005));
		ans = (int)(tmp * (double)1000.f);

		printf("%d\n", ans / 10);
	}

	return 0;
}
