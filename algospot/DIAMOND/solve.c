#include <stdio.h>

#define MAX (50)
#define TRUE (1)
#define FALSE (0)
#define INCREASE (1)
#define DECREASE (0)

char input[MAX + 1][MAX + 1];
int map[MAX + 1][MAX + 1];
int N, M;
int answer;

int get_answer(int row, int col, int size, int inc)
{
	int ret;

	if (map[row][col] < size) {
		return FALSE;
	} else if (inc == INCREASE) {
		if ((row + 1) < M) {
			if (col > 0) ret = get_answer(row + 1, col - 1, size + 2, INCREASE);
			else		 ret = FALSE;

			if ((ret == FALSE) && (size > answer)) {

				if (((col + 1) < N) && (size > 1))
					ret = get_answer(row + 1, col + 1, size - 2, DECREASE);
				if ((ret == TRUE) || (size == 1)) {
					answer = size;
					ret = TRUE;
				}
			}
			return ret;
		} else if (size == 1) {
			if (size > answer) {
				answer = size;
				return TRUE;
			} else {
				return FALSE;
			}
		} else {
			return FALSE;
		}
	} else {
		if (size == 1) {
			return TRUE;
		} else {
			if (((row + 1) < M) && ((col + 1) < N))
				ret = get_answer(row + 1, col + 1, size - 2, DECREASE);
			else
				ret = FALSE;

			return ret;
		}
	}
}

int main(void)
{
	int tc, T;
	int i, j, k, cnt;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &M);
		for (i = 0; i < M; ++i) {
			scanf("%s\n", input[i]);
			for (j = 0; input[i][j] != '\0'; ++j) {
				if (input[i][j] == '#') {
					if (j > 0) {
						if (map[i][j - 1] > 0) {
							map[i][j] = map[i][j - 1] - 1;
						} else {
							for (k = j, cnt = 0; input[i][k] == '#'; ++k) ++cnt;
							map[i][j] = cnt;
						}
					} else {
						for (k = j, cnt = 0; input[i][k] == '#'; ++k) ++cnt;
						map[i][j] = cnt;
					}
				} else {
					map[i][j] = 0;
				}
			}
			N = j;
		}

		answer = 0;
		for (i = 0; i < M; ++i) {
			for (j = 0; input[i][j] != '\0'; ++j) {
				if (input[i][j] == '#') {
					get_answer(i, j, 1, INCREASE);
				}
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}
