#include <stdio.h>

#define MAX (10)
#define min_init (99999999)
#define max_init (0)

int main(void)
{
	int TC, tc;
	int min, max, i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		min = min_init;
		max = max_init;
		for (i = 0; i < MAX; ++i) {
			scanf("%d", &j); 
			for (k = 0; j > 0; j /= 10) {
				k += (j % 10);
			}
			if (min > k) min = k;
			if (max < k) max = k;
		}
		printf("#%d %d %d\n", tc, max, min);
	}

	return 0;
}
