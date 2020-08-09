#include <stdio.h>

#define MAX (100)

#define EMPTY (0)
#define WALL (1)
#define INVALID (-1)

struct NODE {
	int row;
	int col;
	int count;
};

struct NODE queue[2][(MAX + 1) * (MAX + 1)];

int push_queue, queue_index;
int map[MAX + 2][MAX + 2];
int visit[MAX + 2][MAX + 2];
int N, M;

#define INIT ((MAX + 1) * (MAX + 1) + 1)
#define push(Y,X,Z) do {\
		if (visit[(Y)][(X)] > (Z)) { \
			visit[(Y)][(X)] = (Z); \
			queue[push_queue][queue_index].row = (Y); \
			queue[push_queue][queue_index].col = (X); \
			queue[push_queue][queue_index].count = (Z); \
			++queue_index; \
		} \
	} while(0);

int main(void)
{
	int tc, T;
	int i, j, k, cnt;
	int pop_queue, queue_size;
	char buffer[MAX + 1];

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

//	scanf("%d", &T);
	T = 1;
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < M; ++i) {
			scanf("%s\n", buffer);

			for (j = 0; j < N; ++j) {
				if (buffer[j] == '0') map[i + 1][j + 1] = EMPTY;
				else				  map[i + 1][j + 1] = WALL;

				map[0][j + 1] = INVALID;
				map[M + 1][j + 1] = INVALID;

				visit[i + 1][j + 1] = INIT;
			}

			map[i + 1][0] = INVALID;
			map[i + 1][N + 1] = INVALID;
		}

		push_queue = 0;
		queue_index = 0;
		push(1, 1, map[1][1]);

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue= push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (k = 0; k < queue_size; ++k) {
				i = queue[pop_queue][k].row;
				j = queue[pop_queue][k].col;
				cnt = queue[pop_queue][k].count;

				if (map[i][j - 1] != INVALID) push(i, j - 1, map[i][j - 1] + cnt);
				if (map[i][j + 1] != INVALID) push(i, j + 1, map[i][j + 1] + cnt);
				if (map[i - 1][j] != INVALID) push(i - 1, j, map[i - 1][j] + cnt);
				if (map[i + 1][j] != INVALID) push(i + 1, j, map[i + 1][j] + cnt);
			}
		}

		printf("%d\n", visit[M][N]);
	}

	return 0;
}
