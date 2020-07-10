#include <stdio.h>

int main(void)
{
	int tc, T;
	int N, i, answer, input;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (answer = 0, i = 1; i <= N; ++i) {
			scanf("%d", &input);
			if (i == input)
				++answer;
		}
		printf("%d\n", answer);
	}

	return 0;
}
