#include <stdio.h>

#define win(COMP,WIN) ((long long)(COMP) < (long long)(((M + (WIN)) * (long long)100) / (long long)(N + (WIN))))
#define MAX ((long long)2000000000)

long long N, M;

int main(void)
{
	int tc, T;
	long long low, high, middle;
	long long comp, answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%lld %lld\n", &N, &M);
		if (N != M) {
			comp = (long long)(M * (long long)100) / (long long)N;

			for (low = 1, high = MAX; low < high;) {
				middle = (high + low) / 2;
				if (middle == low) {
					if (win(comp, low)) answer = low;
					else if (win(comp, high)) answer = high;
					else answer = -1;
					break;
				} else if (win(comp, low)) {
					answer = low;
					break;
				} else if (win(comp, middle)) {
					high = middle;
				} else if (win(comp, high)) {
					low = middle;
				} else {
					answer = -1;
					break;
				}
			}
			printf("%lld\n", answer);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}
