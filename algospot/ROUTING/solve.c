#include <stdio.h>

#define MAX		(10000)
#define INVALID (-1)
#define PUSHED	(1)
#define IDLE	(0)

struct PATH {
	int to;
	int status;

	double noise;
	struct PATH *next;
};

struct NODE {
	struct PATH *first;
	struct PATH *last;
	double noise;
};

struct PATH path[(MAX + 1) * 4 + 1];
struct NODE node[(MAX + 1)];
struct PATH *queue[2][(MAX + 1) * 4 + 1];

int path_index, node_index;
int N, M;
int push_queue, queue_index;

void push(struct PATH *pt, double noise)
{
	if ((node[pt->to].noise == INVALID) || ((pt->noise * noise) < (node[pt->to].noise))) {
		node[pt->to].noise = pt->noise * noise;
		if (pt->status == IDLE) {
			queue[push_queue][queue_index++] = pt;
			pt->status = PUSHED;
		}
	}
}

int main(void)
{
	int tc, T;
	int i, j, k;
	double noise;
	int pop_queue, queue_size;
	struct PATH * pt;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < N; ++i) {
			node[i].first = NULL;
			node[i].last = NULL;
			node[i].noise = INVALID;
		}

		for (k = 0, path_index = 0; k < M; ++k) {
			scanf("%d %d %lf\n", &i, &j, &noise);

			path[path_index].next = NULL;
			path[path_index].noise = noise;
			path[path_index].status = IDLE;
			path[path_index].to = i;

			if (node[j].first == NULL)	node[j].first		= &path[path_index];
			else						node[j].last->next	= &path[path_index];
			node[j].last = &path[path_index++];

			path[path_index].next = NULL;
			path[path_index].noise = noise;
			path[path_index].status = IDLE;
			path[path_index].to = j;

			if (node[i].first == NULL)	node[i].first		= &path[path_index];
			else						node[i].last->next	= &path[path_index];
			node[i].last = &path[path_index++];
		}

		for (queue_index = 0, push_queue = 0, pt = node[0].first; pt != NULL; pt = pt->next) {
			push(pt, 1.f);
		}

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (k = 0; k < queue_size; ++k) {
				pt = queue[pop_queue][k];
				pt->status = IDLE;
			}

			for (k = 0; k < queue_size; ++k) {
				pt = queue[pop_queue][k];
				i = pt->to;
				for (pt = node[i].first; pt != NULL; pt = pt->next) {
					push(pt, node[i].noise);
				}
			}
		}

		printf("%.10lf\n", node[N - 1].noise);
	}

	return 0;
}
