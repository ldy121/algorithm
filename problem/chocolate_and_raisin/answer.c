#include <stdio.h>

#define MAX (50)
#define invalid ((MAX + 1) * (MAX + 1) * 1000)

int answer[MAX + 1][MAX + 1][MAX + 1][MAX + 1];
int input[MAX + 1][MAX + 1];

int get_answer(int src_n, int src_m, int dst_n, int dst_m)
{
	int i, j, k, sum;
	if (answer[src_n][src_m][dst_n][dst_m] == invalid) {
		sum = 0;
		for (i = src_n; i <= dst_n; ++i) {
			for (j = src_m; j <= dst_m; ++j) {
				sum += input[i][j];
			}
		}
		j = invalid;
		for (i = src_n + 1; i <= dst_n; ++i) {
			k = get_answer(src_n, src_m, i - 1, dst_m) + get_answer(i, src_m, dst_n, dst_m);
			if (j > k) j = k;
		}
		for (i = src_m + 1; i <= dst_m; ++i) {
			k = get_answer(src_n, src_m, dst_n, i - 1) + get_answer(src_n, i, dst_n, dst_m);
			if (j > k) j = k;
		}
		answer[src_n][src_m][dst_n][dst_m] = sum + j;
	}

	return answer[src_n][src_m][dst_n][dst_m];
}

int main(void)
{
	int TC, T;
	int i, j, k, l, s;
	int m, n;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n%d\n", &n, &m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%d", &input[i][j]);
				for (k = 1; k <= n; ++k) {
					for (l = 1; l <= m; ++l) {
						answer[i][j][k][l] = invalid;
					}
				}
				answer[i][j][i][j] = 0;
			}
		}

		printf("#%d %d\n", T, get_answer(1, 1, n, m));
	}
}
