#include <stdio.h>
#include <stdio.h>

#pragma warning(disable : 4996)

#define MAX (10000)

int input[MAX];

int main(void)
{
	int N, T, test_case;
	int average, i, answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d\n", &N);
		for (average = 0, i = 0; i < N; ++i) {
			scanf("%d", &input[i]);
			average += input[i];
		}
		average /= N;

		for (answer = 0, i = 0; i < N; ++i) {
			if (input[i] <= average)
				++answer;
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}