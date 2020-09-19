include <stdio.h>
#include <math.h>

#define MAX (500)
#define INVALID (-1)

#define swap(X,Y) do {\
		d = node[(X)].distance;					\
		node[(X)].distance = node[(Y)].distance;\
		node[(Y)].distance = d;					\
												\
		k = node[(X)].from;						\
		node[(X)].from = node[(Y)].from;		\
		node[(Y)].from = k;						\
												\
		k = node[(X)].to;						\
		node[(X)].to = node[(Y)].to;			\
		node[(Y)].to = k;						\
	} while (0)

struct POINT {
	int x;
	int y;
};

struct NODE {
	int from;
	int to;
	double distance;
};

struct POINT point[MAX + 1];
struct NODE node[(MAX + 1) * (MAX + 1) + 1];

int parent[MAX + 1];
int N, M;
int edge_cnt, node_cnt;

void qsort(int left, int right)
{
	int i, j, k;
	double d;

	if (left < right) {
		for (j = left, i = left + 1; i <= right; ++i) {
			if (node[i].distance < node[left].distance) {
				++j;
				swap(i, j);
			}
		}

		swap(left, j);

		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int main(void)
{
	int tc, T;
	int i, j, k;
	int a, b;
	double answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);

		for (i = 0; i < N; ++i) {
			parent[i] = INVALID;

			scanf("%d", &j);
			point[i].x = j;
		}

		for (i = 0; i < N; ++i) {
			scanf("%d", &j);
			point[i].y = j;
		}

		for (i = 0, node_cnt = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				node[node_cnt].from = i;
				node[node_cnt].to = j;
				node[node_cnt++].distance = sqrt((double)(((point[i].x - point[j].x) * (point[i].x - point[j].x)) +
														  ((point[i].y - point[j].y) * (point[i].y - point[j].y))));
			}
		}

		for (k = 0, edge_cnt = 0; k < M; ++k) {
			scanf("%d %d\n", &a, &b);
			for (i = a; parent[i] != INVALID; i = parent[i]);
			for (j = b; parent[j] != INVALID; j = parent[j]);

			if (i != j)	{
				++edge_cnt;

				if (i != b) parent[b] = i;
				if (i != j) parent[j] = i;
			}
		}

		qsort(0, node_cnt - 1);
		for (k = 0, answer = 0.f; (edge_cnt < (N - 1)); ++k) {
			for (i = node[k].from;	parent[i] != INVALID; i = parent[i]);
			for (j = node[k].to;	parent[j] != INVALID; j = parent[j]);

			if (i != j) {
				++edge_cnt;
				answer += node[k].distance;

				if (i != parent[node[k].to])	parent[node[k].to]	 = i;
				if (i != j)						parent[j]			 = i;
			}
		}

		printf("%lf\n", answer);
	}

	return 0;
}
