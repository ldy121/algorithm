#include <stdio.h>

#define MAX (50)
#define INIT (-100000000)
#define max(X, Y) (((X)>(Y))?(X):(Y))
#define SEOHA (0)
#define HYUNWOO (1)

int number[MAX + 1];
int answer[MAX + 1][MAX + 1];
int N;

int get_answer(int left, int right) 
{
	int tmp1, tmp2, ret;

	if (right < left) return 0;

	if (answer[left][right] == INIT) {
		tmp1 = number[left] - get_answer(left + 1, right);
		tmp2 = number[right] - get_answer(left, right - 1);

		ret = max(tmp1, tmp2);

		if ((right - left) > 1) {
			tmp1 = -1 * get_answer(left + 2, right);
			tmp2 = -1 * get_answer(left, right - 2);

			ret = max(ret, tmp1);
			ret = max(ret, tmp2);
		}

		answer[left][right] = ret;
	}

	return answer[left][right];
}

int main(void)
{
	int tc, T;
	int i, j, ans;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d", &N);

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				answer[i][j] = INIT;
			}

			scanf("%d", &number[i]);
		}

		ans = get_answer(0, N - 1);

		printf("%d\n", ans);
	}

	return 0;
}
