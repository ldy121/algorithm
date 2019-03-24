#include <stdio.h>

int main(void)
{
	int i;
	int T, t;
	float p, q, s1, s2, succeed, fail;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (t = 1; t <= T; ++t) {
		scanf("%f %f", &p, &q);
		s1 = (1.0f - p) * q;	// 0th - wrong direction, 1st - probability for working
		s2 = p * (1.0f - q) * q;// 1st - right direction, 1st - wrong direction, 2nd - probability for working
		printf ("#%d %s\n", t, ((s1 < s2) ? ("YES") : ("NO")));
	}

	return 0;
}
