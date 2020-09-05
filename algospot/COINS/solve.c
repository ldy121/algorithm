#include <stdio.h>

#define MAX (5000)
#define MODULE (1000000007)

int answer[MAX + 1];
int buffer[MAX + 1];

int M, C;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &M, &C);
		for (i = 0; i <= M; ++i) {
			answer[i] = 0;
			buffer[i] = 0;
		}

		for (k = 0; k < C; ++k) {
			scanf("%d", &j);

			buffer[j] = 1;
			for (i = 0; (i + j) <= M; ++i) {
				if (buffer[i] > 0) buffer[i + j] = (buffer[i + j] + buffer[i]) % MODULE;
				if (answer[i] > 0) buffer[i + j] = (buffer[i + j] + answer[i]) % MODULE;
			}

			for (i = 0; i <= M; ++i) {
				answer[i] = (answer[i] + buffer[i]) % MODULE;
				buffer[i] = 0;
			}
		}

		printf("%d\n", answer[M]);
	}

	return 0;
}
