#include <stdio.h>

#define TRUE		(1)
#define FALSE		(0)
#define ON 		(1)
#define OFF		(0)
#define MAX 		(1000)

int n;
int answer[MAX + 1][MAX + 1];

int get_answer(int index) {
	int i;

	for (i = 1; i <= n; ++i) {
		if (i == index)	continue;

		answer[index][i] = !answer[index][i];
		answer[i][index] = !answer[i][index];
		if (answer[index][i] == ON)	++answer[index][0];
		else				--answer[index][0];
		if (answer[i][index] == ON)	++answer[i][0];
		else				--answer[i][0];
	}

	for (i = index + 1; i <= n; ++i) {
		if ((answer[i][0] > 0) && (get_answer(i) == TRUE))
			return TRUE;
	}

	for (i = 1; i <= n; ++i) {
		if (answer[i][0] > 0)
			break;
	}

	if (i > n)
		return TRUE;

	for (i = 1; i <= n; ++i) {
		if (i == index)	continue;

		answer[index][i] = !answer[index][i];
		answer[i][index] = !answer[i][index];
		if (answer[index][i] == ON) 	++answer[index][0];
		else				--answer[index][0];
		if (answer[i][index] == ON)	++answer[i][0];
		else				--answer[i][0];
	}

	return FALSE;
}

int main(void)
{
	int TC, T;
	int i, j, k, m;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n%d\n", &n, &m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j)
				answer[i][j] = ON;
			answer[i][0] = n - 1;
			answer[0][i] = n - 1;
		}
		for (i = 0; i < m; ++i) {
			scanf("%d %d\n", &j, &k);
			answer[j][k] = OFF;
			answer[k][j] = OFF;
			--answer[j][0];
			--answer[k][0];
		}
		for (i = 1, j = FALSE; (i <= n) && (j == FALSE); ++i) {
			if (answer[i][0] > 0)	j = get_answer(i);
		}
		printf("#%d %s\n", T, ((j == TRUE) ? ("DA") : ("NE")));
	}
}
