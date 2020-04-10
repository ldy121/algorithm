#include <stdio.h>

#define MAX (100)
#define MODULE (1000000007)

int fab[MAX + 1];

int main(void)
{
	int tc, T, i;

	fab[1] = 1;
	fab[2] = 2;

	for (i = 3; i <= MAX; ++i) {
		fab[i] = (fab[i - 1] + fab[i - 2]) % MODULE;
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &i);
		printf("%d\n", fab[i]);
	}

	return 0;
}
