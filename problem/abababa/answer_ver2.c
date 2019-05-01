#include <stdio.h>

int main(void)
{
	int TC, tc;
	int answer, i, T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &T);
		for (answer = 0, i = T; i > 2; i -= 2) {
			answer += (T - i + 1);
		}
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
