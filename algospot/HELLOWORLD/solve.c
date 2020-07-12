#include <stdio.h>

#define MAX (50)

char buffer[MAX + 1];

int main(void)
{
	int tc, T;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s\n", buffer);
		printf("Hello, %s!\n", buffer);
	}

	return 0;
}

