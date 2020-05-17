#include <stdio.h>

#define MAX (10000000)

int answer[MAX + 1];

int main(void)
{
	int tc, T;
	int i, j;
	int low, high, n, ans;

	for (i = 0; i <= MAX; ++i)
		answer[i] = 0;

	answer[1] = 1;
	for (i = 2; i <= MAX; ++i) {
		++answer[i];
		for (j = i; j <= MAX; j += i) {
			++answer[j];
		}
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %d\n", &n, &low, &high);
		ans = 0;
		for (i = low; i <= high; ++i) {
			if (answer[i] == n)
				++ans;
		}
		printf("%d\n", ans);
	}

	return 0;
}
