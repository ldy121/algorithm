#include <stdio.h>

#define MAX (100)

int triangle[MAX + 1][MAX + 1];
int answer[MAX + 1];
int temp[MAX + 1];
int N;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= i; ++j) {
				scanf("%d ", &triangle[i][j]);
				if (i == N) {
					answer[j] = triangle[i][j];
				}
			}
		}

		for (i = N - 1; i >= 1; --i) {
			for (j = 1; j <= i; ++j)
				temp[j] = 0;

			for (j = 2; j <= i; ++j) {
				if (temp[j - 1] < (answer[j] + triangle[i][j - 1]))
					temp[j - 1] = answer[j] + triangle[i][j - 1];
				if (temp[j]		< (answer[j] + triangle[i][j]))
					temp[j]	= answer[j] + triangle[i][j];
			}

			if (temp[1] < (triangle[i][1] + answer[1]))
				temp[1] = triangle[i][1] + answer[1];
			if (temp[i] < (triangle[i][i] + answer[i + 1]))
				temp[i] = triangle[i][i] + answer[i + 1];


			for (j = 1; j <= i; ++j)
				answer[j] = temp[j];
		}

		printf("%d\n", answer[1]);
	}

	return 0;
}
