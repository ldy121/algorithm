#include <stdio.h>

#define MAX (200)

int p[MAX + 1];
int r[MAX + 1];
int n;

int get_max(int a, int b)
{
	int tmp;

	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while ((b % a) > 0) {
		tmp = b % a;
		b = a;
		a = tmp;
	}

	return a;
}

int main(void)
{
	int tc, T;
	int i, j, max, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &n);
		scanf("%d", &r[0]);
		for (i = 1, k = r[0]; i < n; ++i) {
			scanf("%d", &r[i]);
			k = get_max(k, r[i]);
		}

		max = 1;
		for (i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
			r[i] /= k;
			j = p[i] / r[i];
			if ((p[i] % r[i]) > 0) ++j;
			if (j > max) max = j;
		}

		for (i = 0; i < n; ++i) {
			printf("%d ", r[i] * max - p[i]);
		}
		printf("\n");
	}

	return 0;
}
