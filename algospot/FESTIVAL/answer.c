#include <stdio.h>

#define MAX (1000)
#define LIMIT ((double)(MAX * 100))

double answer[MAX + 1];
double Answer;
int accumulate[MAX + 1];
int day[MAX + 1];

int N, L;

int main(void)
{
	int tc, T;
	int i, j;
	double tmp;
	double sum, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d", &N, &L);

		answer[0] = 0.f;
		accumulate[0] = 0;
		Answer = LIMIT;

		for (i = 1; i <= N; ++i) {
			scanf("%d", &day[i]);
			accumulate[i] = accumulate[i - 1] + day[i];
		}

		for (i = 0; i <= (N - L); ++i) {
			answer[i] = LIMIT;
			for (j = i + L, k = (double)L; j <= N; ++j) {
				tmp = (double)(((double)accumulate[j] - (double)accumulate[i]) / k);
				k = k + 1.f;
				if (answer[i] > tmp)
					answer[i] = tmp;
			}
			if (Answer > answer[i])
				Answer = answer[i];
		}

		printf("%.8f\n", Answer);
	}

	return 0;
}
