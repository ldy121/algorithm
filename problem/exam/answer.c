#include <stdio.h>

#define MAX (2000)

int attendee_problem[MAX + 1];
int attendee_score[MAX + 1];
int attendee[MAX + 1][MAX + 1];
int answer[MAX + 1];

int main(void)
{
	int TC, tc;
	int n, t, p;
	int i, j, k, tmp;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d %d\n", &n, &t, &p);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < t; ++j) {
				scanf("%d", &attendee[i][j]);
			}
			attendee_problem[i] = 0;
			attendee_score[i] = 0;
		}

		for (j = 0; j < t; ++j) {
			k = 0;
			for (i = 0; i < n; ++i) {
				if (attendee[i][j] == 0) ++k;
			}
			for (i = 0; i < n; ++i) {
				if (attendee[i][j] == 1) {
					attendee_score[i] += k;
					++attendee_problem[i];
				}
			}
		}

		for (i = 0; i < n; ++i) {
			k = i;
			for (j = 0; j < i; ++j) {
				if ((attendee_score[answer[j]] < attendee_score[k]) ||
				   ((attendee_score[answer[j]] == attendee_score[k]) && 
				     ((attendee_problem[answer[j]] < attendee_problem[k]) ||
				      ((attendee_problem[answer[j]] == attendee_problem[k]) && 
				       (answer[j] > k))))) {
					tmp = answer[j];
					answer[j] = k;
					k = tmp;
				}
			}
			answer[i] = k;
		}

		for (i = 0; i < n; ++i) {
			if (answer[i] == (p - 1)) {
				break;
			}
		}

		printf("#%d %d %d\n", tc, attendee_score[p - 1],i + 1);
	}
}
