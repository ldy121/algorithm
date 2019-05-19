#include <stdio.h>

#define MAX (10000)

char input[MAX + 1];
int answer[8][MAX + 1];

int main(void)
{
	int TC, tc;
	char * str = "GNUSMAS";
	int len, i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (i = 0; i <= MAX; ++i) {
		answer[0][i] = 1;
	}

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%s\n", input);
		for (i = 0, len = 0; input[len] != '\0'; ++len);
		for (j = 0; str[j] != '\0'; ++j) {
			for (i = len - 1, k = 0; i >= 0; --i) {
				if (input[i] == str[j]) {
					k += answer[j][i + 1];
				}
				answer[j + 1][i] = k;
			}
		}

		printf("#%d %d\n", tc, answer[7][0]);
	}

	return 0;
}
