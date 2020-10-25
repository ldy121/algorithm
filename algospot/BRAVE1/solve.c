#include <stdio.h>

#define MAX (100000)
#define INVALID (-1)
#define INIT (1)

int parent[MAX + 1];
int set_number[MAX + 1];
int N, M;

int main(void)
{
	int tc, T;
	int i, j, k, a, b;
	int answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i <= N; ++i) {
			parent[i] = INVALID;
			set_number[i] = INIT;
		}

		for (k = 0; k < M; ++k) {
			scanf("%d %d\n", &a, &b);
			for (i = a; parent[i] != INVALID; i = parent[i]);
			for (j = b; parent[j] != INVALID; j = parent[j]);

			if (i != j) {
				set_number[i] += set_number[j];
				parent[j] = i;
				parent[b] = i;
			}
		}

		for (i = 0, answer = 0; i <= N; ++i) {
			if ((parent[i] == INVALID) && (set_number[i] > answer))
				answer = set_number[i];
		}

		printf("%d\n", answer);
	}

	return 0;
}
