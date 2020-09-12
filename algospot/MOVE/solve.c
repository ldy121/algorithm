#include <stdio.h>

#define MAX_NODE	(10000)
#define MAX_PATH	(20000)
#define INIT		(MAX_NODE * MAX_PATH * 10)
#define IDLE		(2)
#define PUSHED		(3)

#define push(X,Y)	do {\
		if (node[(X)].weight > (Y)) { \
			node[(X)].weight = (Y); \
			if (node[(X)].status == IDLE) { \
				node[(X)].status = PUSHED; \
				queue[push_queue][queue_index++] = (X); \
			} \
		} \
	} while(0)

struct PATH {
	int to;
	int weight;
	struct PATH *next;
};

struct NODE {
	struct PATH *first;
	struct PATH *last;
	int status;
	int weight;
};

struct PATH path[(MAX_PATH + 1) * 2 + 1];
struct NODE node[MAX_NODE + 1];
int queue[2][(MAX_PATH + 1) * 4 + 1];
int push_queue, queue_index;
int N, M;

int main(void)
{
	int tc, T;
	int a, b, c;
	int i, j;
	int path_index, pop_queue, queue_size;
	struct PATH *pt;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < N; ++i) {
			node[i].first = NULL;
			node[i].last = NULL;
			node[i].weight = INIT;
			node[i].status = IDLE;
		}

		node[0].weight = 0;

		for (path_index = 0, i = 0; i < M; ++i) {
			scanf("%d %d %d\n", &a, &b, &c);

			path[path_index].to = b;
			path[path_index].weight = c;
			path[path_index].next = NULL;

			if (node[a].first == NULL) node[a].first = &path[path_index];
			else node[a].last->next = &path[path_index];
			node[a].last = &path[path_index++];

			path[path_index].to = a;
			path[path_index].weight = c;
			path[path_index].next = NULL;

			if (node[b].first == NULL) node[b].first = &path[path_index];
			else node[b].last->next = &path[path_index];
			node[b].last = &path[path_index++];
		}

		for (push_queue = 0, queue_index = 0, pt = node[0].first; pt != NULL; pt = pt->next) {
			push(pt->to, pt->weight);
		}

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (i = 0; i < N; ++i)
				node[i].status = IDLE;

			for (j = 0; j < queue_size; ++j) {
				i = queue[pop_queue][j];
				for (pt = node[i].first; pt != NULL; pt = pt->next) {
					push(pt->to, node[i].weight + pt->weight);
				}
			}
		}

		printf("%d\n", node[N - 1].weight);
	}

	return 0;
}
