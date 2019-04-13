#include <stdio.h>

#define MAX (100000)
#define NUM(X) ((X) - '0')

int main(void)
{
	int TC, T;
	char N[MAX + 2];
	int len, num;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%s\n", N);
		for (len = 0; N[len] != '\0'; ++len);
		num = NUM(N[0]) * 100 + NUM(N[1]) * 10 + NUM(N[2]);
		num += 5;
		num /= 10;
		if (num >= 100) {
			num /= 10;
			++len;
		}
		printf("#%d %d.%d*10^%d\n", T, num / 10, num % 10, len - 1);
	}
}

