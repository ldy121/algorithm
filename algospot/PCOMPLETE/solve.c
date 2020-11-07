#include <stdio.h>

#define MAX (1000)

char str[MAX + 1];
int p, q;
int N;

int main(void)
{
	int tc, T;
	int i, j, k;
	int answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		scanf("%s\n", str);
		scanf("%d %d\n", &p, &q);
		k = ((p < q) ? (p) : (q));

		if (N % 2 == 0) {
			i = N / 2 - 1;
			j = N / 2;
			answer = 0;
		} else {
			i = j = N / 2;
			answer = ((str[i] == '?') ? (k) : (0));
			--i; ++j;
		}

		while ((i >= 0) && (j < N)) {
			if (str[i] != str[j]) {
				if (str[i] == '?')	answer += ((str[j] == 'a') ? (p) : (q));
				else				answer += ((str[i] == 'a') ? (p) : (q));
			} else if (str[i] == '?') {
				answer += (k * 2);
			}

			--i;
			++j;
		}

		printf("%d\n", answer);
	}

	return 0;
}
