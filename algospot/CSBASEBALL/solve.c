#include <stdio.h>

int main(void)
{
	int tc, T;
	int A, B;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &A, &B);
		if (A > B)	printf("0\n");
		else printf("%d\n", (B - A) + 4);
	}

	return 0;
}
