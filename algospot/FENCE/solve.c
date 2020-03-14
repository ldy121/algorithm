#include <stdio.h>

#define max(A,B) (((A)>(B))?(A):(B))
#define min(A,B) (((A)<(B))?(A):(B))
#define FENCE_MAX (20000)

int fence[FENCE_MAX + 1];
int N;

int get_answer(int left, int right)
{
	int ret, low, high, middle, i, height;

	if (left < right) {
		middle = (left + right) / 2;
		low = middle - 1;
		high = middle + 1;

		ret = get_answer(left, middle);

		if (high <= right) {
			ret = max(ret, get_answer(high, right));
		}

		for (height = fence[middle], i = 2; (left <= low) || (high <= right); ++i) {
			if (left <= low) {
				if ((high <= right) && (fence[low] < fence[high])) {
					height = min(height, fence[high]);
					++high;
				} else {
					height = min(height, fence[low]);
					--low;
				}
			} else {
				height = min(height, fence[high]);
				++high;
			}
			ret = max(ret, height * i);
		}
	} else {
		ret = fence[left];
	}
	return ret;
}

int main(void)
{
	int tc, T;
	int i;

	//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &fence[i]);
		}
		printf("%d\n", get_answer(0, N - 1));
	}
	return 0;
}
