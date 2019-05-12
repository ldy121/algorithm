#include <stdio.h>

#define calc(X) ((((X) + 1) * (X)) >> 1)

int main(void)
{
	int TC, tc;
	long long answer, N, k, K, tmp;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%lld\n", &N);
		for (k = ((long long)1 << (long long)31), K = 0,answer = -1;
			(answer == -1) && (k > 0); k >>= 1) {
			tmp = calc(K | k);
			if (tmp < N) {
				K |= k;	
			} else if (tmp == N) {
				answer = (K | k);
			}
		}
		printf("#%d %lld\n", tc, answer);
	}

	return 0;
}
