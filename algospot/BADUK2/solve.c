#include <stdio.h>

#define MAX (19)
#define EMPTY (0)
#define VISIT (1)
#define BLACK (2)
#define WHITE (4)
#define WALL (8)
#define NOBODY (BLACK | WHITE)

int map[MAX + 2][MAX + 2];
int N, B, W;
int white_count;
int black_count;
int assign, count;

void get_answer(int row, int col)
{
	switch (map[row][col]) {
	case EMPTY :
		++count;
		map[row][col] = VISIT;

		get_answer(row - 1, col);
		get_answer(row + 1, col);
		get_answer(row, col - 1);
		get_answer(row, col + 1);
		break;
	case BLACK :
	case WHITE :
		assign |= map[row][col];
		break;
	}
}

int main(void)
{
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (scanf("%d", &N); N > 0; scanf("%d", &N)) {
		scanf("%d %d\n", &B, &W);
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j) {
				map[i][j] = EMPTY;
				map[0][j] = map[N + 1][j] = WALL;
			}
			map[i][0] = map[i][N + 1] = WALL;
		}

		for (k = 0; k < B; ++k) {
			scanf("%d %d", &i, &j);
			map[i][j] = BLACK;
		}

		for (k = 0; k < W; ++k) {
			scanf("%d %d", &i, &j);
			map[i][j] = WHITE;
		}

		black_count = white_count = 0;
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j) {
				if (map[i][j] == EMPTY) {
					assign = EMPTY;
					count = 0;
					get_answer(i, j);

					if (assign == BLACK)	black_count += count;
					if (assign == WHITE)	white_count += count;
				}
			}
		}

		if (white_count > black_count)			printf("White wins by %d\n", white_count - black_count);
		else if (white_count < black_count)		printf("Black wins by %d\n", black_count - white_count);
		else									printf("Draw\n");
	}

	return 0;
}
