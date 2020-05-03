#include <stdio.h>

#define MAX (100)

int buffer[MAX + 1];
int N;

int main(void)
{
	int tc, T;
	int i, j, k, tmp, answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &k);
			for (j = 0; j < i; ++j) {
				if (k < buffer[j]) {
					tmp = buffer[j];
					buffer[j] = k;
					k = tmp;
				}
			}

			buffer[i] = k;
		}

		if (N > 1) {
			for (answer = 0, i = 1; i < N; ++i) {
				k = buffer[i] + buffer[i - 1];
				answer += k;
				for (j = i; j < N; ++j) {
					if (k < buffer[j]) {
						break;
					} else {
						buffer[j - 1] = buffer[j];
					}
				}
				buffer[j - 1] = k;
			}
		} else {
			answer = buffer[0];
		}

		printf("%d\n", answer);
	}

	return 0;
}
