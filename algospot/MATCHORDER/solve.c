#include <stdio.h>

#define MAX (100)

int russia[MAX + 1];
int korea[MAX + 1];
int N;

void qsort(int data[], int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (j = left, i = left + 1; i <= right; ++i) {
			if (data[i] < data[left]) {
				++j;

				k = data[i];
				data[i] = data[j];
				data[j] = k;
			}
		}

		k = data[left];
		data[left] = data[j];
		data[j] = k;

		qsort(data, left, j - 1);
		qsort(data, j + 1, right);
	}
}

int main(void)
{
	int tc, T, i, j, answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i)
			scanf("%d", &russia[i]);
		for (i = 0; i < N; ++i)
			scanf("%d", &korea[i]);

		qsort(russia, 0, N - 1);
		qsort(korea, 0, N - 1);

		for (answer = j = i = 0; (i < N) && (j < N); ++i) {
			if (russia[j] <= korea[i]) {
				++j;
				++answer;
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}
