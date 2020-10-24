#include <stdio.h>

#define FALSE (0)
#define TRUE (1)
#define INVALID (-1)
#define MAX (100)
#define MAX_PATH (1000)
#define IDLE (1)
#define PUSHED (2)
#define MIN_INIT		(MAX_PATH * MAX_PATH * MAX_PATH)
#define MAX_INIT		(-1 * MAX_PATH *MAX_PATH * MAX_PATH)
#define ANDROMEDA	(1)

#define min_push(src,dst,w,t)	do {								\
		if (node[dst].min_weight >= w) {							\
			node[dst].min_weight = w;								\
			min_last_vertex[dst] = src;								\
			if (node[dst].min_turn != t) {							\
				node[dst].min_turn = t;								\
				min_queue[min_push_queue][min_queue_index++] = dst; \
			}														\
		}															\
	} while(0)

#define max_push(src,dst,w,t)	do {								\
		if (node[dst].max_weight <= w) {							\
			node[dst].max_weight = w;								\
			max_last_vertex[dst] = src;								\
			if (node[dst].max_turn != t) {							\
				node[dst].max_turn = t;								\
				max_queue[max_push_queue][max_queue_index++] = dst; \
			}														\
		}															\
	} while(0)

struct PATH {
	int to;
	int weight;
	struct PATH *next;
};

struct NODE {
	int max_turn;
	int min_turn;
	int min_weight;
	int max_weight;
	struct PATH *first;
	struct PATH *last;
};

struct NODE node[MAX + 1];
struct PATH path[MAX_PATH + 1];

int max_queue[2][MAX + 1];
int min_queue[2][MAX + 1];

int max_push_queue, max_queue_index;
int min_push_queue, min_queue_index;
int max_last_vertex[MAX + 1];
int min_last_vertex[MAX + 1];
int max_visit[MAX + 1];
int min_visit[MAX + 1];
int V, W;

int main(void)
{
	int tc, T;
	int a, b, d;
	int i, j, turn;
	int max_pop_queue, max_queue_size;
	int min_pop_queue, min_queue_size;
	int limit, min_infinity, max_infinity;
	struct PATH *pt;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &V, &W);

		for (i = 0; i < V; ++i) {
			node[i].first = NULL;
			node[i].last = NULL;
			node[i].max_weight = MAX_INIT;
			node[i].min_weight = MIN_INIT;
		}

		for (i = 0; i < W; ++i) {
			scanf("%d %d %d\n", &a, &b, &d);
			path[i].to = b;
			path[i].weight = d;
			path[i].next = NULL;

			if (node[a].first == NULL)	node[a].first = &path[i];
			else						node[a].last->next = &path[i];
			node[a].last = &path[i];
		}

		limit = (W + 1) * (W + 1) + 1;
		turn = 0;

		max_push_queue = 0;
		max_queue_index = 0;
		min_push_queue = 0;
		min_queue_index = 0;

		for (i = 0; i < V; ++i) {
			max_last_vertex[i] = INVALID;
			min_last_vertex[i] = INVALID;
			node[i].max_turn = INVALID;
			node[i].min_turn = INVALID;
		}

		for (pt = node[0].first; pt != NULL; pt = pt->next) {
			min_push(0, pt->to, pt->weight, turn);
			max_push(0, pt->to, pt->weight, turn);
		}

		for (max_queue_size = max_queue_index, min_queue_size = min_queue_index; 
			((max_queue_size > 0) || (min_queue_size > 0)) && (turn < limit);
			max_queue_size = max_queue_index, min_queue_size = min_queue_index) {

			max_pop_queue = max_push_queue;
			max_push_queue = !max_push_queue;
			max_queue_index = 0;

			min_pop_queue = min_push_queue;
			min_push_queue = !min_push_queue;
			min_queue_index = 0;
			++turn;

			for (j = 0; j < max_queue_size; ++j) {
				i = max_queue[max_pop_queue][j];
				for (pt = node[i].first; pt != NULL; pt = pt->next) {
					max_push(i, pt->to, node[i].max_weight + pt->weight, turn);
				}
			}

			for (j = 0; j < min_queue_size; ++j) {
				i = min_queue[min_pop_queue][j];
				for (pt = node[i].first; pt != NULL; pt = pt->next) {
					min_push(i, pt->to, node[i].min_weight + pt->weight, turn);
				}
			}
		}

		if ((node[ANDROMEDA].max_weight != MAX_INIT) && (node[ANDROMEDA].min_weight != MIN_INIT)) {
			for (i = 0; i < V; ++i) {
				max_visit[i] = FALSE;
				min_visit[i] = FALSE;
			}

			for (i = ANDROMEDA, max_infinity = FALSE; (i != INVALID) && (max_infinity == FALSE);) {
				if (max_visit[i] == FALSE) {
					max_visit[i] = TRUE;
					i = max_last_vertex[i];
				} else {
					max_infinity = TRUE;
				}
			}

			for (i = ANDROMEDA, min_infinity = FALSE; (i != INVALID) && (min_infinity == FALSE);) {
				if (min_visit[i] == FALSE) {
					min_visit[i] = TRUE;
					i = min_last_vertex[i];
				} else {
					min_infinity = TRUE;
				}
			}

			if (min_infinity == TRUE) printf("INFINITY ");
			else printf("%d ", node[ANDROMEDA].min_weight);

			if (max_infinity == TRUE) printf("INFINITY\n");
			else printf("%d\n", node[ANDROMEDA].max_weight);

		} else {
			printf("UNREACHABLE\n");
		}
	}

	return 0;
}
