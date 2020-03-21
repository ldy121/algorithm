#include <stdio.h>

#define MAX		(100)
#define INVALID		(-1)
#define TRUE		(1)
#define FALSE		(0)
#define VISIT		(TRUE)
#define NO_VISIT	(FALSE)

struct QUEUE {
	int row;
	int col;
};

struct QUEUE queue[2][(MAX + 1) * (MAX + 1)];

int map[MAX + 1][MAX + 1];
int visit[MAX + 1][MAX + 1];
int N;
int push_queue, queue_index;

void push(int row, int col)
{
	if ((row <= N) && (col <= N) && (visit[row][col] == NO_VISIT)) {
		queue[push_queue][queue_index].row = row;
		queue[push_queue][queue_index].col = col;
		++queue_index;

		visit[row][col] = VISIT;
	}
}


int main(void)
{
	int tc, T;
	int i, j, row, col;
	int pop_queue, queue_size;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);

		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j) {
				scanf("%d", &map[i][j]);
				visit[i][j] = FALSE;
			}
		}

		push_queue = 0;
		queue_index = 0;
		push(1, 1);
		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (i = 0; i < queue_size; ++i) {
				row = queue[pop_queue][i].row;
				col = queue[pop_queue][i].col;

				if ((row == N) && (col == N)) {
					break;
				} else {
					push(map[row][col] + row, col);
					push(row, map[row][col] + col);
				}
			}

			if (i < queue_size)
				queue_index = 0;
		}

		printf("%s\n", ((visit[N][N] == VISIT) ? ("YES") : ("NO")));
	}

	return 0;
}
