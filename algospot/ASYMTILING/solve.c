#include <stdio.h>

#define MAX (100)

#define MODULE (1000000007)

int answer[MAX + 1];
int add[MAX + 1];
int sub[MAX + 1];
int N;

int main(void)
{
	int tc, T;
	int i;

	add[0] = add[1] = 1;
	add[2] = 2;
	add[3] = 3;

	sub[0] = sub[1] = 1;
	sub[2] = 2;
	sub[3] = 1;

	answer[0] = answer[1] = answer[2] = 0;
	answer[3] = 2;

	for (i = 4; i <= MAX; ++i) {
		add[i] = (add[i - 1] + add[i - 2]) % MODULE;
		sub[i] = (sub[i - 2] + sub[i - 4]) % MODULE;

		answer[i] = (add[i] + MODULE - sub[i]) % MODULE;
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		printf("%d\n", answer[N]);
	}

	return 0;
}
