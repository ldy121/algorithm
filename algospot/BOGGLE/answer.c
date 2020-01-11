#include <stdio.h>

#define FALSE (0)
#define TRUE (1)

#define MAX (5)
#define INVALID (-1)
#define BUFFER_SIZE (10)

int N;
char map[MAX + 2][MAX + 2];
char buffer[BUFFER_SIZE + 1];

unsigned char answer[BUFFER_SIZE + 1][MAX + 2][MAX + 2];

unsigned char get_answer(int count)
{
	int i, j, k;

	if (buffer[count] != '\0') {
		k = 0;

		for (i = 0; i <= (MAX + 1); ++i)
			for (j = 0; j <= (MAX + 1); ++j)
				answer[count][i][j] = FALSE;

		for (i = 1; i <= MAX; ++i) {
			for (j = 1; j <= MAX; ++j) {
				if (answer[count - 1][i][j] == TRUE) {
					if (map[i - 1][j]		== buffer[count]) {
						answer[count][i - 1][j]		= TRUE;
						++k;
					}
					if (map[i - 1][j - 1]	== buffer[count]) {
						answer[count][i - 1][j - 1] = TRUE;
						++k;
					}
					if (map[i - 1][j + 1]	== buffer[count]) {
						answer[count][i - 1][j + 1] = TRUE;
						++k;
					}

					if (map[i + 1][j]		== buffer[count]) {
						answer[count][i + 1][j]		= TRUE;
						++k;
					}
					if (map[i + 1][j - 1]	== buffer[count]) {
						answer[count][i + 1][j - 1] = TRUE;
						++k;
					}
					if (map[i + 1][j + 1]	== buffer[count]) {
						answer[count][i + 1][j + 1] = TRUE;
						++k;
					}
/*
					if (map[i][j]			== buffer[count]) {
						answer[count][i][j]			= TRUE;
						++k;
					}
*/
					if (map[i][j - 1]		== buffer[count]) {
						answer[count][i][j - 1]		= TRUE;
						++k;
					}
					if (map[i][j + 1]		== buffer[count]) {
						answer[count][i][j + 1]		= TRUE;
						++k;
					}
				}
			}
		}

		if (k > 0)
			return get_answer(count + 1);

	} else {
		return TRUE;
	}

	return FALSE;
}

int main(void)
{
	int tc, T;
	int i, j, k, t;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (i = 0; i <= (MAX + 1); ++i) {
		for (j = 0; j <= (MAX + 1); ++j) {
			answer[1][i][j] =
			answer[0][i][j] = FALSE;
			map[i][j] = INVALID;
		}
	}

	scanf("%d", &T);

	for (tc = 0; tc < T; ++tc) {
		for (i = 1; i <= MAX; ++i) {
			scanf("%s", &map[i][1]);
			map[i][MAX + 1] = INVALID;
		}

		t = 0;
		scanf("%d", &N);
		for (k = 0; k < N; ++k) {
			scanf("%s", buffer);
			for (i = 1; i <= MAX; ++i) {
				for (j = 1; j <= MAX; ++j) {
					if (map[i][j] == buffer[0]) {
						answer[0][i][j] = TRUE;
						++t;
					} else {
						answer[0][i][j] = FALSE;
					}
				}
			}

			if (t > 0) {
				printf("%s %s\n", buffer, ((get_answer(1)) ? ("YES") : ("NO")));
			} else {
				printf("%s NO\n", buffer);
			}
		}
	}

	return 0;
}
