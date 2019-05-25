#include <stdio.h>

#define MAX (100010)

char input[MAX + 1];
char answer[MAX + 1];

int main(void)
{
	int TC, tc;
	int x, y, len, carry, i;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%s %d %d\n", input, &x, &y);
		if (x > y) {
			i = y;
			y = x;
			x = i;
		}

		for (i = 0, carry = 0, len = 0; input[i] != '\0'; ++i) {
			carry = (carry * 10) + (input[i] - '0');
			if (carry >= y) {
				answer[len++] = y + '0';
				carry -= y;
			} else if ((carry >= x) && ((len != 0) || (x != 0))) {
				answer[len++] = x + '0';
				carry -= x;
			}
		}
		answer[len] = '\0';

		if (len == 0) {
			printf("#%d -1\n", tc);
		} else {
			printf("#%d %s\n", tc, answer);
		}
	}

	return 0;
}
