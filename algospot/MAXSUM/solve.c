#include <stdio.h>

#define INIT (-101)

int N;
int sum;
int answer;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 0, answer = INIT, sum = 0; i < N; ++i) {
			scanf("%d\n", &j);
			k = ((j <= (sum + j)) ? (sum + j) : (j));
			
			if (answer < k)	answer = k;
			
			if (0 <= (sum + j))	sum += j;
			else				sum = 0;
		}
		printf("%d\n", answer);
	}

	return 0;
}
