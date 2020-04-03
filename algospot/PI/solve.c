#include <stdio.h>

#define MAX (10000)
#define INVALID (-1)
#define TRUE (1)
#define FALSE (0)

char pi[MAX + 2];
int dp[MAX + 1];
int len;

unsigned char same_difference(int src, int dst)
{
	int i;

	for (i = src + 2; i <= dst; ++i) {
		if ((pi[i] - pi[i - 1]) != (pi[i - 1] - pi[i - 2])) {
			return FALSE;
		}
	}

	return TRUE;
}

unsigned char alternate(int src, int dst)
{
	int i;
	char a, b;

	a = pi[src];
	b = pi[src + 1];

	for (i = 2; i <= (dst - src); ++i) {
		if ((i % 2) == 0) {
			if (pi[src + i] != a) {
				return FALSE;
			}
		} else {
			if (pi[src + i] != b) {
				return FALSE;
			}
		}
	}

	return TRUE;
}

unsigned char increase_decrease(int src, int dst)
{
	int i, df;

	if (((pi[src] < pi[src + 1]) && ((pi[src + 1] - pi[src]) == 1)) ||
	    ((pi[src] > pi[src + 1]) && ((pi[src] - pi[src + 1]) == 1))) {
			df = pi[src + 1] - pi[src];
			for (i = 1; i <= (dst - src); ++i) {
				if ((pi[src + i] - pi[src]) != (i * df)) {
					return FALSE;
				}
			}
	} else {
		return FALSE;
	}

	return TRUE;
}

unsigned char same_array(int src, int dst)
{
	int i;

	for (i = src + 1; i <= dst; ++i) {
		if (pi[src] != pi[i])
			return FALSE;
	}

	return TRUE;
}

int get_answer(int index)
{
	int i, j, tmp, ret;

	if (dp[index] == INVALID) {
		ret = INVALID;
		for (i = 2; ((index + i) <= len) && (i <= 4); ++i) {
			tmp = (((index + i) < len) ? (get_answer(index + i + 1)) : (0));
			if (tmp != INVALID) {
				if (same_array(index, index + i)) {
					tmp += 1;
				} else if (increase_decrease(index, index + i))	{
					tmp += 2;
				} else if (alternate(index, index + i)) {
					tmp += 4;
				} else if (same_difference(index, index +i)) {
					tmp += 5;
				} else {
					tmp += 10;
				}
			} else {
				continue;
			}

			if ((ret == INVALID) || (tmp < ret)) {
				ret = tmp;
			}
		}

		if (ret != INVALID) {
			dp[index] = ret;
		}
	} else {
		ret = dp[index];
	}

	return ret;
}

int main(void)
{
	int tc, T;
	int i;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s\n", pi);
		for (i = 0; pi[i] != '\0'; ++i) {
			dp[i] = INVALID;
		}
		dp[i] = INVALID;
		len = i - 1;
		get_answer(0);

		printf("%d\n", dp[0]);
	}

	return 0;
}
