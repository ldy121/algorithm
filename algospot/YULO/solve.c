#include <stdio.h>

#define MAX (40)

int buffer[MAX + 1];
int N, answer;

void qsort(int left, int right) {
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (buffer[i] < buffer[left]) {
				++j;
				k = buffer[i];
				buffer[i] = buffer[j];
				buffer[j] = k;
			}
		}

		k = buffer[left];
		buffer[left] = buffer[j];
		buffer[j] = k;

		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int main(void)
{
	int tc, T;
	int i, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
			scanf("%d", &buffer[i]);

		qsort(0, N - 1);

		answer = 0;
		for (i = 0, j = N - 1; i <= j; ++i, --j) {
			if (answer < (buffer[i] + buffer[j])) {
				answer = buffer[i] + buffer[j];
			}
		}

		printf("%d.%d\n", answer / 2, (((answer % 2) == 1) ? 5 : 0));
	}

	return 0;
}
