#include <stdio.h>

#define MAX (500)
#define invalid (-1000 * 1000)
#define set_invalid(X) ((X).x = invalid)
#define is_invalid(X) ((X).x == invalid)

struct checkpoint {
	int x;
	int y;
};

int get_distance(struct checkpoint *src, struct checkpoint *dst)
{
	int ret = 0;

	ret += ((src->x > dst->x) ? (src->x - dst->x) : (dst->x - src->x));
	ret += ((src->y > dst->y) ? (src->y - dst->y) : (dst->y - src->y));

	return ret;
}

int main(void)
{
	int TC, T;
	int N, K, i, j, k;
	int max, max_point, point;
	int tmp1, tmp2, cmp;
	struct checkpoint input[MAX + 1];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d\n", &N, &K);
		for (i = 0; i < N; ++i) {
			scanf("%d %d\n", &input[i].x, &input[i].y);
		}

		for (k = 0; k < K; ++k) {
			i = 0;
			max = invalid;
			for (point = 1; is_invalid(input[point]); ++point);
			while (point < (N - 1)) {
				for (j = point + 1; is_invalid(input[j]); ++j);
				tmp1 = get_distance(&input[i], &input[point]) +
					get_distance(&input[point], &input[j]);
				tmp2 = get_distance(&input[i], &input[j]);
				if ((tmp1 - tmp2) > max) {
					max = tmp1 - tmp2;
					max_point = point;
				}
				i = point;
				point = j;
			}
			set_invalid(input[max_point]);	
		}

		k = 0;
		for (i = 0; i < (N - 1); i = j) {
			for (j = i + 1; is_invalid(input[j]); ++j);
			k += get_distance(&input[i], &input[j]);
		}

		printf("#%d %d\n", T, k);
	}
}

