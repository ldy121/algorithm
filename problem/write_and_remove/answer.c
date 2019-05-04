#include <stdio.h>

#define MAX (10000)

char input[MAX + 1];

int main(void)
{
	int TC, tc;
	int answer;
	int i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%s\n", input);
		answer = 0;
		k = 0;
		for (i = 1; input[i] != '\0'; ++i) {
			j = (0x1 << (input[i] - '0'));
			if ((k & j) > 0) {
				--answer;
				k &= ~j;
			} else {
				++answer;
				k |= j;
			}
		}
		
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
