#include <stdio.h>

int main(void)
{
	int TC, tc;
	int answer, i, j, T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &T);
		for (answer = 0, i = 3, j = 0; j >= 0; i += 2) {
			j = T - i + 1;
			if (j > 0) {
				answer += j;
			}
		}
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
