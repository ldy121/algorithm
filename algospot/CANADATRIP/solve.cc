#include <stdio.h>

#define MAX (5000)
#define MAX_PATH (8030000)
#define TRUE (1)
#define FALSE (0)
#define INVALID (-1)

struct NODE {
	int M;
	int L;
	int G;
};

int N, K;
int answer;
struct NODE city[MAX + 1];

int get_answer(int D)
{
	int i, ret;

	for (i = 0, ret = 0; i < N; ++i) {
		if (D >= (city[i].L - city[i].M)) {
			if (D >= city[i].L) ret += ((city[i].M / city[i].G) + 1);
			else				ret += ((D - (city[i].L - city[i].M)) / city[i].G + 1);
		}
	}

	return (ret >= K);
}

int main(void)
{
	int tc, T;
	int i, high, low, middle;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		high = 0;
		low = 0;
		scanf("%d %d\n", &N, &K);
		for (i = 0; i < N; ++i) {
			scanf("%d %d %d\n", &city[i].L, &city[i].M, &city[i].G);
			if (city[i].L > high)
				high = city[i].L;
		}

		for (answer = INVALID; answer == INVALID;) {
			middle = (high + low) / 2;
			if (get_answer(middle)) {
				if (get_answer(middle - 1) == FALSE) answer = middle;
				else high = middle;
			} else if (get_answer(middle + 1)) {
				answer = middle + 1;
			} else {
				low = middle;
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}
