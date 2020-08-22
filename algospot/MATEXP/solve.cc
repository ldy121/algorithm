#include <stdio.h>

#define MAX (32)
#define MODULE (10007)
#define MAX_MATRIX (100)

int answer_matrix[MAX_MATRIX + 1][MAX_MATRIX + 1];
int matrix[MAX_MATRIX + 1][MAX_MATRIX + 1];
int answer[MAX + 1][MAX_MATRIX + 1][MAX_MATRIX + 1];
int ans;
int N, p;

int main(void)
{
	int tc, T;
	int i, j, k, t;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &p);

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				scanf("%d", &answer[0][i][j]);
				answer_matrix[i][j] = (i == j);
			}
		}

		for (k = 1; k < MAX; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					answer[k][i][j] = 0;
				}
			}

			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					for (t = 0; t < N; ++t) {
						answer[k][i][j] += (((answer[k - 1][i][t] % MODULE) * (answer[k - 1][t][j] % MODULE)) % MODULE);
						answer[k][i][j] %= MODULE;
					}
				}
			}
		}

		for (k = 0; k < MAX; ++k) {
			if (((1 << k) & p) > 0) {
				for (i = 0; i < N; ++i) {
					for (j = 0; j < N; ++j) {
						matrix[i][j] = 0;
					}
				}

				for (i = 0; i < N; ++i) {
					for (j = 0; j < N; ++j) {
						for (t = 0; t < N; ++t) {
							matrix[i][j] += (((answer_matrix[i][t] % MODULE) * (answer[k][t][j] % MODULE)) % MODULE);
							matrix[i][j] %= MODULE;
						}
					}
				}

				for (i = 0; i < N; ++i) {
					for (j = 0; j < N; ++j) {
						answer_matrix[i][j] = matrix[i][j];
					}
				}
			}
		}

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				printf("%d ", answer_matrix[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
