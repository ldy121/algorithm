#include <stdio.h>

#define MAX 	(500)
#define INIT 	(-1)

int N;
int len[MAX + 1];
int input[MAX + 1];

int traversal(int start)
{
	int ret;
	int i;

	if (len[start] != INIT)	return len[start];
	else len[start] = 0;

	for (i = start + 1; i <= N; ++i) {
		if (input[start] < input[i]) {
			ret = traversal(i);
			if (len[start] < ret) {
				len[start] = ret;
			}
		}
	}

	return ++len[start];
}

int main(void)
{
	int tc, T;
	int i, answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 1; i <= N; ++i) {
			scanf("%d ", &input[i]);
			len[i] = INIT;
		}

		for (answer = 0, i = 1; i <= N; ++i) {
			traversal(i);
			if (answer < len[i]) {
				answer = len[i];
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}
