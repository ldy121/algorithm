#include <stdio.h>

int main(void)
{
	int tc, T;
	int W, i, j, sum;

//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &W);
		for (sum = 0, i = 0; i < 9; ++i) {
			scanf("%d", &j);
			sum += j;
		}

		if (sum <= W) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
