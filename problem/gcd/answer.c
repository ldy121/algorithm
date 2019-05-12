#include <stdio.h>

#define MAX (90)

struct ANSWER {
	int a;
	int b;
};

struct ANSWER answer[MAX + 1];

int main(void)
{
	int TC, tc;
	int i, k;

	answer[0].a = 1;
	answer[0].b = 0;
	answer[1].a = 2;
	answer[1].b = 1;

	for (i = 2; i <= MAX; ++i) {
		answer[i].a = answer[i - 1].a + answer[i - 1].b;
		answer[i].b = answer[i - 1].a;
	}

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &k);
		printf("#%d %d %d\n", tc, answer[k].a, answer[k].b);
	}

	return 0;
}
