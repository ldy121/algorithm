#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define MAX (1000)

int cnt;
int answer[MAX + 1];
int N, K;

int main(void)
{
	int tc, T;
	int i, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &K);
		for (i = 0; i <= N; ++i) answer[i] = TRUE;

		answer[1] = FALSE;
		for (cnt = 1, i = 1; cnt < (N - 2); ++cnt) {
			for (j = 0; j < K;) {
				if (++i > N)	i = 1;
				if (answer[i] == TRUE) ++j;
			}
			answer[i] = FALSE;
		}

		for (i = 1; i <= N; ++i) {
			if (answer[i] == TRUE)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}
