#include <stdio.h>

#define MAX (6)
#define TRUE (1)
#define FALSE (0)

int visit[MAX + 2][MAX + 2];
int map[MAX + 2][MAX + 2];
int M, N;
int answer;

void get_answer(int row, int col, int count)
{
	if ((row == N) && (col == M) && (count == (N * M - 1))) {
		++answer;
	} else if ((map[row][col] == count) || (map[row][col] == -1)) {
		visit[row][col] = TRUE;
		if (visit[row - 1][col] == FALSE) get_answer(row - 1, col, count + 1);
		if (visit[row + 1][col] == FALSE) get_answer(row + 1, col, count + 1);
		if (visit[row][col - 1] == FALSE) get_answer(row, col - 1, count + 1);
		if (visit[row][col + 1] == FALSE) get_answer(row, col + 1, count + 1);
		visit[row][col] = FALSE;
	}
}


int main(void)
{
	int tc, T;
	int i, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= M; ++j) {
				scanf("%d", &map[i][j]);

				visit[i][j] = FALSE;
				
				visit[0][j] = TRUE;
				visit[N + 1][j] = TRUE;
			}
			visit[i][0] = TRUE;
			visit[i][M + 1] = TRUE;
		}

		answer = 0;
		get_answer(1, 1, 0);
		printf("%d\n", answer);
	}

	return 0;
}
