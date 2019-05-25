#include <stdio.h>

#define MAX (9)

int answer, N;
int a[MAX];

void get_answer(int acc, int index)
{
	int tmp;

	if (index == N) {
		if (acc > answer) {
			answer = acc;
		}
	} else {
		tmp = acc * a[index];
		get_answer(tmp, index + 1);
		tmp = acc + a[index];
		get_answer(tmp, index + 1);
	}
}

int main(void)
{
	int TC, tc, i;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
		}

		answer = a[0];
		get_answer(a[0], 1);

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
