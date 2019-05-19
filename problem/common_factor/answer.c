#include <stdio.h>

#define MAX (100000)

int answer[MAX + 1];

int main(void)
{
	int TC, tc;
	int i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (i = 1; i <= MAX; ++i) {
		answer[i] = 0;
	}

	for (i = 1; i <= MAX; ++i) {
		for (j = 1; (j * i) <= MAX; ++j) {
			++answer[j * i]; 
		}
	}

	for (i = 1, j = 1, k = 1; i <= MAX; ++i) {
		if ((answer[i] >= k)) {
			j = i;
			k = answer[i];
		}
		answer[i] = j;
	}

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &i);
		printf("#%d %d\n", tc, answer[i]);
	}

	return 0;
}
