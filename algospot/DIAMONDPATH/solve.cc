#include <stdio.h>

#define MAX (100)

int N;
int answer[MAX + 1];
int buffer[MAX + 1];
int buf;
int answer_index;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {

		scanf("%d\n", &N);
		answer[0] = 0;
		buffer[0] = 0;
		answer_index = 0;

		for (k = 1; k <= N; ++k) {
			for (i = 0; i < answer_index; ++i)
				buffer[i] = answer[i];

			for (j = 0, i = 0; j < k; ++j, ++i) {
				scanf("%d", &buf);
				if (i == 0) {
					answer[0] = buffer[0] + buf;
				} else if (answer_index == j) {
					answer[answer_index] = buffer[answer_index - 1] + buf;
				} else {
					answer[i] = (((buffer[i - 1] + buf) > (buffer[i] + buf)) ? 
						(buffer[i - 1] + buf) : (buffer[i] + buf));
				}
			}
			answer_index = k;
		}

		--k;
		for (--k; k > 0; --k) {
			for (i = 0; i < answer_index; ++i)
				buffer[i] = answer[i];

			for (j = 0, i = 0; j < k; ++j, ++i) {
				scanf("%d", &buf);
				answer[i] = (((buffer[i] + buf) > (buffer[i + 1] + buf)) ?
					(buffer[i] + buf) : (buffer[i + 1] + buf));
			}

			answer_index = k;
		}

		printf("%d\n", answer[0]);
	}

	return 0;
}
