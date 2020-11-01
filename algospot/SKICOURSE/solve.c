#include <stdio.h>

#define MAX_NODE (50000)
#define MAX_PATH (100000)
#define MAX (100)
#define INIT (-100000 * (MAX + 1))
#define INVALID (INIT)

struct PATH {
	int to;
	int weight;
	struct PATH *next;
};

struct NODE {
	struct PATH *first;
	struct PATH *last;
};

struct PATH path[MAX_PATH + 1];
struct NODE node[MAX_NODE + 1];

int N, M, S;
int answer[MAX_NODE + 1][MAX + 1];

int main(void)
{
	int tc, T;
	int i, j, k, ans;
	int a, b, c;
	struct PATH *pt;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %d\n", &N, &M, &S);
		for (i = 0; i<= N; ++i) {
			for (j = 0; j <= S; ++j) {
				answer[i][j] = INIT;
			}
			answer[i][0] = 0;
			node[i].first = NULL;
			node[i].last = NULL;
		}

		for (i = 0; i < M; ++i) {
			scanf("%d %d %d\n", &a, &b, &c);
			
			path[i].next = NULL;
			path[i].to = b;
			path[i].weight = c;

			if (node[a].first == NULL) node[a].first = &path[i];
			else node[a].last->next = &path[i];
			node[a].last = &path[i];
		}

		for (i = N - 1; i > 0; --i) {
			for (pt = node[i].first; pt != NULL; pt = pt->next) {
				j = pt->to;

				for (k = 0; (answer[j][k] != INVALID) && (k < S); ++k) {
					if (answer[i][k + 1] < (pt->weight + answer[j][k])) {
						answer[i][k + 1] = pt->weight + answer[j][k];
					}
				}
			}
		}

		for (ans = INIT, i = 0; i <= N; ++i) {
			for (j = 0; j <= S; ++j) {
				if (ans < answer[i][j])
					ans = answer[i][j];
			}
		}

		if (ans < 0) ans = 0;
		printf("%d\n", ans);
	}

	return 0;
}
