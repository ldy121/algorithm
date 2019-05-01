#include <stdio.h>

#define MAX (10000)
#define invalid (-1)
#define MODULAR (1000000007)

int answer[MAX + 1];
char s[MAX + 1];

int get_answer(int left, int right)
{
	int mid, i, j;
	if (answer[left] == invalid) {
		answer[left] = 1;
		for (i = right, mid = (left + right) / 2; i > mid; --i) {
			for (j = 0; ((i + j) <= right) && (s[left + j] == s[i + j]); ++j);
			if ((i + j) > right) {
				answer[left] = (answer[left] + get_answer(left + j, i - 1)) % MODULAR;
			}
		}
	}
	return answer[left] % MODULAR;
}

int main(void)
{
	int TC, T;
	int i;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%s", s);
		for (i = 0; s[i] != '\0'; ++i) {
			answer[i] = invalid;
		}
		printf("#%d %d\n", T, get_answer(0, i - 1));
	}
}
