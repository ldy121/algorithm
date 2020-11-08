#include <stdio.h>

#define MAX_N (50)
#define MAX (1000)
#define FALSE (0)
#define TRUE (1)

int answer[MAX_N + 1][MAX + 1];
int N, VS, VM;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %d\n", &N, &VS, &VM);
		for (i = 0; i <= VM; ++i) {
			for (j = 0; j <= N; ++j) {
				answer[j][i] = FALSE;
			}
		}

		answer[0][VS] = TRUE;
		for (i = 1; i <= N; ++i) {
			scanf("%d", &k);
			for (j = 0; j <= VM; ++j) {
				if (answer[i - 1][j] == TRUE) {
					if ((j - k) >= 0) answer[i][j - k] = TRUE;
					if ((j + k) <= VM) answer[i][j + k] = TRUE;
				}
			}
		}

		for (i = VM; i >= 0; --i) {
			if (answer[N][i] == TRUE) {
				break;
			}
		}

		printf("%d\n", i);
	}

	return 0;
}

