#include <stdio.h>

#define INIT (-1)
#define MAX (1000)
#define INVALID (MAX * MAX * MAX)
#define push(X,Y,Z) do {\
		if (answer[(X)] > (Y)) {\
			answer[(X)] = (Y); \
			if (turn[(X)] < (Z)) { \
				queue[push_queue][queue_index++] = (X);\
				turn[(X)] = (Z); \
			}\
		}\
	} while (0)

int turn[MAX + 1];
int answer[MAX + 1];
int fire_station[MAX + 1];
int fire_point[MAX + 1];

int map[MAX + 1][MAX + 1];
int push_queue, queue_index;
int queue[2][MAX + 1];
int V, E, M, N;

int main(void)
{
	int tc, T;
	int i, j, k, a, b, c, ans;
	int pop_queue, queue_size;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %d %d\n", &V, &E, &N, &M);

		for (i = 0; i <= V; ++i) {
			for (j = 0; j <= V; ++j) {
				map[i][j] = INVALID;
			}
			answer[i] = INVALID;
			turn[i] = INIT;
		}

		for (i = 0; i < E; ++i) {
			scanf("%d %d %d\n", &a, &b, &c);
			map[a][b] = c;
			map[b][a] = c;
		}

		for (i = 0; i < N; ++i) {
			scanf("%d", &j);
			fire_point[i] = j;
		}

		k = 0;
		push_queue = 0;
		queue_index = 0;
		for (i = 0; i < M; ++i) {
			scanf("%d", &j);
			fire_station[i] = j;
			push(j, 0, k);
		}

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;
			++k;
			
			for (j = 0; j < queue_size; ++j) {
				a = queue[pop_queue][j];
				for (b = 0; b <= V; ++b) {
					if (map[a][b] != INVALID) {
						push(b, answer[a] + map[a][b], k);
					}
				}
			}
		}

		for (ans = 0, i = 0; i < N; ++i) {
			ans += answer[fire_point[i]];
		}

		printf("%d\n", ans);
	}

	return 0;
}
