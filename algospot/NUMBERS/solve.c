#include <stdio.h>

#define MAX_CITY (50)
#define PATH_COUNT (MAX_CITY)
#define INVALID (-1)

double answer[MAX_CITY + 1];
double tmp_answer[MAX_CITY + 1];
int path[MAX_CITY + 1][MAX_CITY + 1];
int check[MAX_CITY + 1];

int queue[2][MAX_CITY + 1];

int push_queue, queue_index;
int C, D, P;

void push(int city, int day)
{
	if (check[city] < day) {
		check[city] = day;
		queue[push_queue][queue_index++] = city;
	}
}

int main(void)
{
	int tc, T;
	int i, j, k, city;
	int pop_queue, queue_size;
	double tmp1, tmp2;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %d\n", &C, &D, &P);
		for (i = 0; i < C; ++i) {
			path[i][PATH_COUNT] = 0;
			for (j = 0; j < C; ++j) {
				scanf("%d", &k);
				if (k == 1)
					path[i][path[i][PATH_COUNT]++] = j;
			}
			answer[i]	= 0.f;
			check[i]	= INVALID;
		}

		answer[P] = 1.f;
		push_queue = 0;
		queue_index = 0;
		push(P, 0);

		for (k = 1; k <= D; ++k) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_size = queue_index;
			queue_index = 0;

			for (i = 0; i < C; ++i) tmp_answer[i] = 0.f;
			for (i = 0; i < queue_size; ++i) {
				city = queue[pop_queue][i];
				tmp1 = (double)path[city][PATH_COUNT];
				tmp1 = (double)((double)1.f / tmp1);
				tmp2 = answer[city];
				for (j = 0; j < path[city][PATH_COUNT]; ++j) {
					tmp_answer[path[city][j]] = (tmp1 * tmp2) + tmp_answer[path[city][j]];
					push(path[city][j], k);
				}
			}
			for (i = 0; i < C; ++i) answer[i] = tmp_answer[i];
		}

		scanf("%d\n", &j);
		for (i = 0; i < j; ++i) {
			scanf("%d ", &k);
			printf("%.8f ", answer[k]);
		}
		printf("\n");
	}

	return 0;
}
