#include <stdio.h>

#define MAX (7)

char* day[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};


int month[] = {
	31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

int answer[MAX];

int main(void)
{
	int tc, T;
	int m, d, i, j, th;
	char s[1024];

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d %s\n", &m, &d, s);
		for (i = 0; i < (sizeof(day) / sizeof(char *)); ++i) {
			for (j = 0; (s[j] != '\0') && (day[i][j] != '\0'); ++j) {
				if (s[j] != day[i][j])
					break;
			}
			if ((s[j] == '\0') && (day[i][j] == '\0')) {
				th = i;
				break;
			}
		}

		answer[th] = d;
		for (i = th - 1, j = d - 1; i >= 0; --i) {
			if (j == 0)		j = month[m - 1];
			answer[i] = j--;
		}

		for (i = th + 1, j = d + 1; i < MAX; ++i) {
			if (month[m] < j)	j = 1;
			answer[i] = j++;
		}

		for (i = 0; i < MAX; ++i)
			printf("%d ", answer[i]);
		printf("\n");
	}

	return 0;
}
