#include <stdio.h>

#define MAX (11)
#define init (4)
#define base (21)
#define max_card (52)

int main(void)
{
	int N, TC, T;
	int card[MAX + 1];
	int i, j, k;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		for (i = 1; i <= 9; ++i) {
			card[i] = 4;
		}
		card[10] = 16;
		card[11] = 4;
		scanf("%d", &N);
		for (i = 0, k = 0 ;i < N; ++i) {
			scanf("%d", &j);
			--card[j];
			k += j;
		}

		for (i = 1, j = 0; i < (base - k); ++i) {
			j += card[i];
		}

		printf("#%d %s\n", T, (j > (max_card - N - j)) ? ("GAZUA") : ("STOP"));
	}
}

