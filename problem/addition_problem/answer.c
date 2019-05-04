#include <stdio.h>

int main(void)
{
	int TC, tc;
	int N, A, B, answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d %d\n", &N, &A, &B);
		answer = (B * (N - 1) + A) - (B + (N - 1) * A) + 1;
		if (answer < 0) answer = 0;
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
