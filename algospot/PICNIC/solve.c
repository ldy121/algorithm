#include <stdio.h>

#define TRUE (1)
#define FALSE (0)

#define MAX (10)

unsigned char friend_map[MAX + 1][MAX + 1];
unsigned char visit[MAX + 1];

int M, N;
int answer;

void get_answer(int src, int visit_count)
{
	int i, j;

	for (i = src + 1; i <= N; ++i) {
		if ((visit[i] == FALSE) && (friend_map[src][i] == TRUE)) {
			if ((visit_count + 2) == N) {
				++answer;
				return;
			} else {
				visit[src] = TRUE;
				visit[i] = TRUE;
				for (j = src + 1; j <= N; ++j) {
					if (visit[j] == FALSE) {
						get_answer(j, visit_count + 2);
					}
				}
				visit[src] = FALSE;
				visit[i] = FALSE;
			}
		}
	}
}


int main(void)
{
	int tc, T;
	int src, dst;
	int i, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d", &N, &M);
		for (i = 0; i <= N; ++i) {
			for (j = 0; j <= N; ++j)
				friend_map[i][j] = FALSE;
			visit[i] = FALSE;
		}

		for (i = 0; i < M; ++i) {
			scanf("%d %d", &src, &dst);
			if (src < dst)	friend_map[src][dst] = TRUE;
			else friend_map[dst][src] = TRUE;
		}

		answer = 0;
		get_answer(0, 0);
		printf("%d\n", answer);
	}

	return 0;
}
