#include <stdio.h>

#define MAX (64)
double R[MAX + 1];

int main(void)
{
	int TC, tc;
	long long N, n, i;
	double p, answer, r;


	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%lf %lld\n", &p, &N);
		for (R[0] = 1.f - 2.f * p, i = 2; i <= MAX; ++i)
			R[i] = R[i - 1] * R[i - 1];
		for (n = N - 1, r = 1.f, i = 0; n > 0; ++i, n >>= 1) {
			if (n & (long long)(0x1)) {
				r *= R[i];
			}
		}
		answer = r * p + (p * (1.f - r)) / ( 1.f - R[0]);
		printf("#%d %lf\n", tc, answer);
	}

	return 0;
}
