#include <stdio.h>

#define MAX (1000)

int data[MAX];

int main(void)
{
	int TC, tc;
	int N, i, j, k, max;
	int tmp1, tmp2;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &N);

		for (i = 0, max = -1; i < N; ++i) {
			scanf("%d", &data[i]);
			for (j = 0; j < i; ++j) {
				tmp1 = tmp2 = data[j] * data[i];
				k = tmp1 % 10;
				for (tmp1 /= 10; tmp1 > 0; tmp1 /= 10) {
					if ((tmp1 % 10) != (k - 1)) {
						break;
					} else {
						--k;
					}
				}
				if ((tmp1 == 0) && (tmp2 > max)) {
					max = tmp2;
				}
			}
		}

		printf("#%d %d\n", tc, max);
	}

	return 0;
}
