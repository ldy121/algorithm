#include <stdio.h>

#define MAX (500)
#define TRUE (1)
#define FALSE (0)

int map[MAX + 1][MAX + 1];
int visit[MAX + 1];
int answer[MAX + 1];
int N, K;

int main(void)
{
	int tc, T;
	int i, j, k;
	int min;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &K);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < K; ++j) {
				scanf("%d", &map[i][j]);
			}
			visit[i] = FALSE;
		}

		for (j = 0, k = 0; (j < K) && (k <= 1); ++j) {
			for (i = 0, k = 0, min = MAX; i < N; ++i) {
				if (visit[i] == FALSE) {
					if ((map[i][j] < min)) {
						min = map[i][j];
						answer[0] = i;
						k = 1;
					} else if (map[i][j] == min) {
						answer[k++] = i;
					}
				}
			}

			if (k == 1) {
				visit[answer[0]] = TRUE;
			} else if (k > 1) {
				break;
			} 
		}

		if (j == K) {
			for (i = 0; i < N; ++i) {
				if (visit[i] == FALSE) {
					printf("%d ", i + 1);
				}
			}
		} else {
			for (i = 0; i < k; ++i) {
				printf("%d ", answer[i] + 1);
			}
		}

		printf("\n");
	}

	return 0;
}
