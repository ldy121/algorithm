#include <stdio.h>

#define MAX 	(51)
#define invalid (-1)
#define MODULE	((long long)(998244353))

long long answer[MAX];
int T[MAX];
int A[MAX];
int B[MAX];


int M, N;

long long get_answer(int index, int t, int a, int b, long long x)
{
	if (answer[index] == invalid) {
		if (t == 1) 	 answer[index] = get_answer(a, T[a], A[a], B[a], x) + get_answer(b, T[b], A[b], B[b], x);
		else if (t == 2) answer[index] = (long long)a * get_answer(b, T[b], A[b], B[b], x);
		else if (t == 3) answer[index] = get_answer(a, T[a], A[a], B[a], x) * get_answer(b, T[b], A[b], B[b], x);
		answer[index] = answer[index] % MODULE;
	}
	return answer[index];
}

int main(void)
{
	int TC, tc;
	int i, j;
	long long x;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d", &N);
		for (i = 2; i <= N; ++i) {
			scanf("%d %d %d\n", &T[i], &A[i], &B[i]);
		}
		printf("#%d", tc);
		scanf("%d\n", &M);
		for (i = 0; i < M; ++i) {
			scanf("%lld\n", &x);
			answer[0] = 1;
			answer[1] = x;
			for (j = 2; j <= N; ++j) {
				answer[j] = invalid;
			}
			printf(" %lld", get_answer(N, T[N], A[N], B[N], x));
		}
		printf("\n");
	}
}

