#include <stdio.h>
#include <math.h>

#define MAX (100)
#define INIT (10000000.f)
#define FALSE (0)
#define TRUE (1)

struct NODE {
	double x;
	double y;
};

struct NODE node[MAX + 1];
double map[MAX + 1][MAX + 1];
double distance[MAX + 1];
int visit[MAX + 1];
int N;

int main(void)
{
	int tc, T;
	int i, j, k;
	double answer, tmp;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%lf %lf\n", &node[i].x, &node[i].y);
			visit[i] = FALSE;
		}

		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				tmp = sqrt(((node[i].x - node[j].x) * (node[i].x - node[j].x)) + ((node[i].y - node[j].y) * (node[i].y - node[j].y)));
				map[i][j] = tmp;
				map[j][i] = tmp;
			}
		}

		answer = 0.f;
		visit[0] = TRUE;
		for (i = 0; i < N; ++i) {
			distance[i] = map[0][i];
		}

		for (i = 1; i < N; ++i) {
			tmp = INIT;
			for (j = 0; j < N; ++j) {
				if ((visit[j] == FALSE) && (distance[j] < tmp)) {
					tmp = distance[j];
					k = j;
				}
			}

			if (answer < tmp)
				answer = tmp;

			visit[k] = TRUE;
			for (j = 0; j < N; ++j) {
				if ((visit[j] == FALSE) && (distance[j] > map[k][j])) {
					distance[j] = map[k][j];
				}
			}
		}
	
		printf("%.2f\n", answer);
	}

	return 0;
}
