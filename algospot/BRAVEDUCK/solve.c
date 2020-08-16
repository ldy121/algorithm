#include <stdio.h>

#define MAX (100)
#define TRUE (1)
#define FALSE (0)

struct NODE {
	int x;
	int y;
};

#define get_distance(x1, y1, x2, y2) (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)))
#define push(X)		do {\
	if (visit[(X)] == FALSE) {\
			visit[(X)] = TRUE;\
			queue[push_queue][queue_index].x = path[(X)].x;\
			queue[push_queue][queue_index].y = path[(X)].y;\
			++queue_index;\
		}\
	} while(0)

int push_queue, queue_index;
int J, N;
int visit[MAX + 1];
struct NODE queue[2][MAX + 1];

struct NODE path[MAX + 1];
struct NODE dst;

int main(void)
{
	int tc, T;
	int i, j, answer;
	int pop_queue, queue_size;
	int x, y;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &J);
		scanf("%d %d\n", &path[0].x, &path[0].y);
		scanf("%d %d\n", &dst.x, &dst.y);
		scanf("%d\n", &N);

		visit[0] = FALSE;
		for (i = 1; i <= N; ++i) {
			visit[i] = FALSE;
			scanf("%d %d\n", &path[i].x, &path[i].y);
		}

		push_queue = 0;
		queue_index = 0;
		push(0);

		for (queue_size = queue_index, answer = FALSE; (answer == FALSE) && (queue_size > 0); queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (j = 0; (j < queue_size) && (answer == FALSE); ++j) {
				x = queue[pop_queue][j].x;
				y = queue[pop_queue][j].y;

				if (get_distance(x, y, dst.x, dst.y) <= (J * J)) {
					answer = TRUE;
				} else {
					for (i = 1; i <= N; ++i) {
						if (get_distance(x, y, path[i].x, path[i].y) <= (J * J)) {
							push(i);
						}
					}
				}
			}
		}

		printf("%s\n", ((answer) ? "YES" : "NO"));
	}

	return 0;
}
