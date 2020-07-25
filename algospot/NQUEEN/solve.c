#include <stdio.h>

int N;
int map[13][13];
int answer;

void mask(int row, int col, int mask)
{
	int i, j;

	map[row][col] += mask;
	for (i = 0; i < N; ++i) {
		if (i != col)
			map[row][i] += mask;
		if (i != row)
			map[i][col] += mask;
	}

	for (i = 1; i < N; ++i) {
		if (((row + i) >= 0) && ((row + i) < N) && 
			((col + i) >= 0) && ((col + i) < N)) {
				map[row + i][col + i] += mask;
		}

		if (((row - i) >= 0) && ((row - i) < N) && 
			((col + i) >= 0) && ((col + i) < N)) {
				map[row - i][col + i] += mask;
		}

		if (((row + i) >= 0) && ((row + i) < N) && 
			((col - i) >= 0) && ((col - i) < N)) {
				map[row + i][col - i] += mask;
		}

		if (((row - i) >= 0) && ((row - i) < N) && 
			((col - i) >= 0) && ((col - i) < N)) {
				map[row - i][col - i] += mask;
		}
	}
}

void get_answer(int line) 
{
	int i;

	if (line < N) {
		for (i = 0; i < N; ++i) {
			if (map[line][i] == 0) {
				mask(line, i, 1);
				get_answer(line + 1);
				mask(line, i, -1);
			}
		}
	} else {
		++answer;
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
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				map[i][j] = 0;
			}
		}

		answer = 0;
		get_answer(0);
		printf("%d\n", answer);
	}

	return 0;
}
