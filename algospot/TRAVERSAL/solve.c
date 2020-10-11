#include <stdio.h>

#define TRUE (1)
#define FALSE (0)

#define MAX (100)
#define INVALID (-1)

int in_order[MAX + 1];
int pre_order[MAX + 1];
int index;
int N;

void print(int left, int right)
{
	int i, middle, val;

	if (left <= right) {
		val = pre_order[index++];
	} else {
		val = INVALID;
	}

	if (left < right) {
		for (i = left; i <= right; ++i) {
			if (in_order[i] == val) {
				middle = i;
				break;
			}
		}

		print(left, middle - 1);
		print(middle + 1, right);
	}

	if (val != INVALID)
		printf("%d ", val);
}

int main(void)
{
	int tc, T;
	int i;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);

		for (i = 0; i < N; ++i) {
			scanf("%d", &pre_order[i]);
		}

		for (i = 0; i < N; ++i) {
			scanf("%d", &in_order[i]);
		}

		index = 0;
		print(0, N - 1);
		printf("\n");
	}

	return 0;
}

