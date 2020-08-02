#include <stdio.h>

#define MAX (500)
#define FALSE (0)
#define TRUE (1)

int N, M;
int problem[MAX + 1];

int main(void)
{
	int tc, T;
	int answer;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i <= M; ++i) {
			problem[i] = 0;
		}

		answer = TRUE;
		for (i = 0; i < N; ++i) {
			scanf("%d", &j);
			if ((j == 0) || (j == M)) {
				answer = FALSE;
			} 
			while (j-- > 0) {
				scanf("%d", &k);
				++problem[k];
			}
		}

		for (i = 1; (i <= M) && (answer == TRUE); ++i) {
			if ((problem[i] == 0)) {
				answer = FALSE;
			}
		}

		printf("%s\n", ((answer) ? "YES" : "NO"));
	}

	return 0;
}
