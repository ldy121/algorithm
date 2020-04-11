#include <stdio.h>

#define MAX (100)

struct NODE {
	int count;
	int number;
};

int N;
int triangle[MAX + 1][MAX + 1];
struct NODE answer[MAX + 1][MAX + 1];

int main(void)
{
	int tc, T;
	int i, j;
	int tmp1, tmp2;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);

		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= i; ++j) {
				scanf("%d ", &triangle[i][j]);
				answer[i][j].count = 1;
				answer[i][j].number = triangle[i][j];
			}
		}

		for (i = N - 1; i >= 1; --i) {
			for (j = 1; j <= i; ++j) {
				tmp1 = triangle[i][j] + answer[i + 1][j].number;
				tmp2 = triangle[i][j] + answer[i + 1][j + 1].number;
				if (tmp1 == tmp2) {
					answer[i][j].count = answer[i + 1][j].count + answer[i + 1][j + 1].count;
					answer[i][j].number = tmp1;
				} else if (tmp1 > tmp2) {
					answer[i][j].count = answer[i + 1][j].count;
					answer[i][j].number = tmp1;
				} else {
					answer[i][j].count = answer[i + 1][j + 1].count;
					answer[i][j].number = tmp2;
				}
			}
		}

		printf("%d\n", answer[1][1].count);
	}

	return 0;
}

