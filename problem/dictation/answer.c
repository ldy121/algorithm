#include <stdio.h>

#define MAX (100000)

int main(void)
{
	int TC, T;
	char src[MAX + 1];
	char dst[MAX + 1];
	int i, answer, n;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n", &n);
		scanf("%s\n", src);
		scanf("%s\n", dst);
		answer = 0;
		for (i = 0; i < n; ++i) {
			if (src[i] == dst[i])
				++answer;
		}
		printf("#%d %d\n", T, answer);
	}
}
