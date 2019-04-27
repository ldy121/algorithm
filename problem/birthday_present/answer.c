#include <stdio.h>

#define MAX (300000)

int hole[MAX + 1];

int main(void)
{
	int TC, T;
	int mid, high;
	int n, q, i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d\n", &n, &q);
		k = 1000000001;
		for (i = 0; i < n; ++i) {
			scanf("%d", &j);
			if (j < k) k = j;
			hole[i] = k;
		}
		for (i = 0, high = n; i < q; ++i) {
			scanf("%d", &j);
			if (high > 0) {
				mid = high / 2;
				if (hole[mid] >= j) {
					for (k = mid; k < high; ++k) {
						if (hole[k] < j) {
							break;
						}
					}
					if (high == k) --high;
					else high = k;
				} else {
					for (k = 0; hole[k] >= j; ++k);
					high = k;
				}
			}
		}
		printf("#%d %d\n", T, high);
	}
}
