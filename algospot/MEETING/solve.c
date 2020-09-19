#include <stdio.h>

#define MAX (10000)

int male[MAX + 1];
int female[MAX + 1];
int N, answer;

void qsort(int data[], int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (data[i] < data[left]) {
				++j;

				k = data[i];
				data[i] = data[j];
				data[j] = k;
			}
		}

		k = data[j];
		data[j] = data[left];
		data[left] = k;

		qsort(data, left, j - 1);
		qsort(data, j + 1, right);
	}
}

int main(void)
{
	int tc, T;
	int i;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &male[i]);
		}

		for (i = 0; i < N; ++i) {
			scanf("%d", &female[i]);
		}

		qsort(male, 0, N - 1);
		qsort(female, 0, N - 1);

		for (answer = 0, i = 0; i < N; ++i) {
			answer += (((male[i] > female[i]) ? (male[i] - female[i]) : (female[i] - male[i])));
		}

		printf("%d\n", answer);
	}

	return 0;
}
