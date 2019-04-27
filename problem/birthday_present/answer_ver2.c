#include <stdio.h>

#define MAX (300000)

int hole[MAX + 1];

int get_low(int input, int len)
{
	int i, j;
	for (j = i = 1; (i <= len) && (input <= hole[i]); i <<= 1) j = i;

	return j;
}

int get_high(int input, int len)
{
	int i, j;

	for (j = i = len; (i > 0) && (input > hole[i]); i >>= 1) j = i;

	return j;
}

int main(void)
{
	int TC, T;
	int low, high, len, answer;
	int n, q, i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d\n", &n, &q);
		k = 1000000001;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &j);
			if (j < k) k = j;
			hole[i] = k;
		}
		for (i = 0, len = answer = n; i < q; ++i) {
			scanf("%d", &j);
			if (len > 0) {
				low = get_low(j, len);
				high = get_high(j, len);
				for (k = low; k <= high; ++k) {
					if (j > hole[k]) {
						break;
					}
				}
				answer = k - 1;
				len = answer - 1;
			} else {
				answer = 0;
			}
		}
		printf("#%d %d\n", T, answer);
	}
}
