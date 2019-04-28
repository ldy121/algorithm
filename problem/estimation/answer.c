#include <stdio.h>

int main(void)
{
	int TC, tc;
	long long input;
	int answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%lld\n", &input);
		for (answer = 0; input > 0; input >>= 1) {
			if ((input & 1) > 0) ++answer;
		}
		printf("#%d %s\n", tc, (answer > 1) ? ("NO") : ("YES"));
			
	}
	return 0;
}
