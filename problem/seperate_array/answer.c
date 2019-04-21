#include <stdio.h>

enum status {
	none,
	inc,
	dec
};

int main(void)
{
	int TC, T;
	enum status stat;
	int i, j, k, tmp, answer, n;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n", &n);
		answer = 1;
		stat = none;
		scanf("%d", &i);

		for (k = 1; k < n; ++k) {
			scanf("%d", &j);
			switch (stat) {
			case none :
				if (i < j)	stat = inc;
				else if (i > j) stat = dec;
				break;
			case inc :
				if (i > j) {
					++answer;
					stat = none;
				}
				break;
			case dec :
				if (i < j) {
					++answer;
					stat = none;
				}
				break;
			}
			tmp = i;
			i = j;
			j = tmp;
		}
		printf("#%d %d\n", T, answer);
	}
}
