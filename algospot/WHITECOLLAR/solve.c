#include <stdio.h>

#define MAX (1000)
#define TRUE (1)
#define FALSE (0)

int answer[MAX + 1];
int visit[MAX + 1][MAX + 1];
int map[MAX + 1][MAX + 1];
int queue[2][MAX + 1];
int available_buffer[MAX + 1];
int available[MAX + 1];
int push_queue, queue_index;
int N, M;

#define push(X,Y) do {\
	if (available[(X)] == FALSE) {\
			if (visit[(X)][0] == 0) queue[push_queue][queue_index++] = (X);\
			visit[(X)][++visit[(X)][0]] = (Y); \
		} \
	} while(0)

int main(void)
{
	int tc, T;
	int i, j, k, buffer_index;
	int pop_queue, queue_size;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i <= N; ++i) {
			for (j = 0; j <= N; ++j) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
			available[i] = FALSE;
			answer[i] = FALSE;
		}

		for (k = 0; k < M; ++k) {
			scanf("%d %d\n", &i, &j);
			map[i][j] = TRUE;
		}

		push_queue = 0;
		queue_index = 0;
		push(1, 1);
		available[1] = TRUE;
		buffer_index = 0;

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;
			for (j = 1; j <= N; ++j)
				available_buffer[j] = FALSE;

			for (i = 0; i < queue_size; ++i) {
				k = queue[pop_queue][i];
				if (k == N) {
					queue_index = 0;
					break;
				} else {
					for (j = 1; j <= N; ++j) {
						if (map[k][j] == TRUE) {
							map[k][j] = FALSE;
							push(j, k);
							available_buffer[j] = TRUE;
						}
					}
				}
			}

			for (j = 1; j <= N; ++j) {
				if (available_buffer[j] == TRUE)
					available[j] = TRUE;
			}
		}

		answer[1] = TRUE;
		answer[N] = TRUE;
		push_queue = 0;
		queue_index = 0;
		for (i = 1; i <= visit[N][0]; ++i) {
			queue[push_queue][queue_index++] = visit[N][i];
			answer[visit[N][i]] = TRUE;
		}

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (i = 0; i < queue_size; ++i) {
				k = queue[pop_queue][i];
				for (j = 1; j <= visit[k][0]; ++j) {
					if (answer[visit[k][j]] == FALSE) {
						queue[push_queue][queue_index++] = visit[k][j];
						answer[visit[k][j]] = TRUE;
					}
				}
			}
		}

		for (i = 1; i <= N; ++i) {
			if (answer[i] == TRUE)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}
