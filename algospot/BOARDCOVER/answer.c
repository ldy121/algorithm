#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define WHITE (0)
#define BLACK (1)
#define MAX (20)

#define IS_WHITE(Y,X)		(map[Y][X]	== WHITE)
#define IS_LEFT_WHITE(Y,X)	(map[Y][X-1] == WHITE)
#define IS_RIGHT_WHITE(Y,X)	(map[Y][X+1] == WHITE)
#define IS_UP_WHITE(Y,X)	(map[Y-1][X] == WHITE)
#define IS_DOWN_WHITE(Y,X)	(map[Y+1][X] == WHITE)

#define SET_LEFT_UP_COLOR(Y,X,COLOR)	(map[Y][X]=map[Y][X-1]=map[Y-1][X]=COLOR)
#define SET_RIGHT_UP_COLOR(Y,X,COLOR)	(map[Y][X]=map[Y][X+1]=map[Y-1][X]=COLOR)
#define SET_LEFT_DOWN_COLOR(Y,X,COLOR)	(map[Y][X]=map[Y][X-1]=map[Y+1][X]=COLOR)
#define SET_RIGHT_DOWN_COLOR(Y,X,COLOR)	(map[Y][X]=map[Y][X+1]=map[Y+1][X]=COLOR)

int W, H;
int check_white[MAX + 2];
int map[MAX + 2][MAX + 2];
int answer;
int full_black, black;

void get_answer(int row, int col)
{
	int i;

	for (i = col; i <= W; ++i) {
		if (IS_WHITE(row, i) && IS_LEFT_WHITE(row, i) && IS_UP_WHITE(row, i)) {
			if ((black + 3) == full_black) {
				++answer;
			} else {
				black += 3;
				SET_LEFT_UP_COLOR(row, i, BLACK);

				--check_white[row - 1];
				check_white[row] -=2;
				get_answer(row, i);
				check_white[row] +=2;
				++check_white[row - 1];

				SET_LEFT_UP_COLOR(row, i, WHITE);
				black -= 3;
			}
		}

		if (IS_WHITE(row, i) && IS_RIGHT_WHITE(row, i) && IS_UP_WHITE(row, i)) {
			if ((black + 3) == full_black) {
				++answer;
			} else {
				black += 3;
				SET_RIGHT_UP_COLOR(row, i, BLACK);

				--check_white[row - 1];
				check_white[row] -=2;
				get_answer(row, i);
				check_white[row] +=2;
				++check_white[row - 1];

				SET_RIGHT_UP_COLOR(row, i, WHITE);
				black -= 3;
			}

		}

		if (IS_WHITE(row, i) && IS_LEFT_WHITE(row, i) && IS_DOWN_WHITE(row, i)) {
			if ((black + 3) == full_black) {
				++answer;
			} else {
				black += 3;
				SET_LEFT_DOWN_COLOR(row, i, BLACK);

				--check_white[row + 1];
				check_white[row] -=2;
				get_answer(row, i);
				check_white[row] +=2;
				++check_white[row + 1];

				SET_LEFT_DOWN_COLOR(row, i, WHITE);
				black -= 3;
			}
		}

		if (IS_WHITE(row, i) && IS_RIGHT_WHITE(row, i) && IS_DOWN_WHITE(row, i)) {
			if ((black + 3) == full_black) {
				++answer;
			} else {
				black += 3;
				SET_RIGHT_DOWN_COLOR(row, i, BLACK);

				--check_white[row + 1];
				check_white[row] -=2;
				get_answer(row, i);
				check_white[row] +=2;
				++check_white[row + 1];

				SET_RIGHT_DOWN_COLOR(row, i, WHITE);
				black -= 3;
			}
		}
	}

	if ((row < H) && (check_white[row - 1] <= 0)) {
		get_answer(row + 1, 1);
	}
}

int main(void)
{
	int tc, T;
	int i, j, white;
	char buffer[MAX + 2];

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &H, &W);
		for (i = 0; i <= (H + 1); ++i) {
			check_white[i] = 0;
			map[i][0] = map[i][W + 1] = BLACK;
		}

		for (i = 0; i <= (W + 1); ++i) {
			map[0][i] = map[H + 1][i] = BLACK;
		}

		white = 0;
		answer = 0;
		black = 0;
		full_black = W * H;
		for (i = 1; i <= H; ++i) {
			scanf("%s", buffer);
			for (j = 0; (j < W) && (buffer[j] != '\0'); ++j) {
				if (buffer[j] == '#') {
					++black;
					map[i][j + 1] = BLACK;
				} else {
					++white;
					++check_white[i];
					map[i][j + 1] = WHITE;
				}
			}
		}

		if (black == full_black) {
			printf("1\n");
		} else if (white > 50) {
			printf("0\n");
		} else {
			get_answer(1, 1);
			printf("%d\n", answer);
		}
	}

	return 0;
}
