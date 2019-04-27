#include <stdio.h>

#define MAX (50)
#define invalid (((MAX + 1) * (MAX + 1) * 1000) * 2)

int answer[MAX + 1][MAX + 1][MAX + 1][MAX + 1];
int sum[MAX + 1][MAX + 1][MAX + 1][MAX + 1];
int input[MAX + 1][MAX + 1];

int get_answer(int src_n, int src_m, int dst_n, int dst_m)
{
	int i, j, k;
	if (answer[src_n][src_m][dst_n][dst_m] == invalid) {
		j = invalid;
		for (i = src_n + 1; i <= dst_n; ++i) {
			k = get_answer(src_n, src_m, i - 1, dst_m) + get_answer(i, src_m, dst_n, dst_m);
			if (j > k) j = k;
		}
		for (i = src_m + 1; i <= dst_m; ++i) {
			k = get_answer(src_n, src_m, dst_n, i - 1) + get_answer(src_n, i, dst_n, dst_m);
			if (j > k) j = k;
		}
		if (sum[src_n][src_m][dst_n][dst_m] >= invalid) {
			printf("%d %d %d %d\n", src_n, src_m, dst_n, dst_m);
		}
		answer[src_n][src_m][dst_n][dst_m] = sum[src_n][src_m][dst_n][dst_m] + j;
	}

	return answer[src_n][src_m][dst_n][dst_m];
}

int main(void)
{
	int TC, T;
	int i, j, k, l;
	int m, n;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n%d\n", &n, &m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%d", &input[i][j]);
			}
			for (j = 1; j <= m; ++j) {
				sum[i][j][i][j] = input[i][j];
				for (k = j + 1; k <= m; ++k) {
					sum[i][j][i][k] = sum[i][j][i][k - 1] + input[i][k];
					answer[i][j][i][k] = invalid;
				}
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				for (k = i + 1; k <= n; ++k) {
					for (l = j; l <= m; ++l) {
						sum[i][j][k][l] = sum[i][j][k - 1][l] + sum[k][j][k][l];
						answer[i][j][k][l] = invalid;
					}
				}
				answer[i][j][i][j] = 0;
			}
		}
		printf("#%d %d\n", T, get_answer(1, 1, n, m));
	}
}
