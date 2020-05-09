#include <stdio.h>

#define MAX (50)
#define BUFFER_SIZE (10)
#define TRUE (1)
#define FALSE (0)
#define INVALID (-1)
#define COUNT (MAX + 1)
#define LENGTH (0)

char buffer[MAX + 1][BUFFER_SIZE + 1];
char buf[BUFFER_SIZE + 1];
int people_table[MAX + 1][MAX + 1];
int food_table[MAX + 1][MAX + 1];
int ANSWER;
int N, M, answer[MAX + 1], answer_count;

int my_strcmp(char *src, char *dst)
{
	int i;

	for (i = 0; src[i] != '\0' && dst[i] != '\0'; ++i) {
		if (src[i] != dst[i])
			return FALSE;
	}

	return src[i] == dst[i];
}

void request(int count)
{
	int i, j, k;
	int food, person;

	if ((ANSWER != INVALID) && (ANSWER <= count))
		return;

	for (person = 0; (person < N) && (answer[person] > 0); ++person);
	if (person == N)
		ANSWER = count;

	for (i = 1; (i <= people_table[person][LENGTH]); ++i) {
		food = people_table[person][i];
		for (j = 1; j <= food_table[food][LENGTH]; ++j) {
			k = food_table[food][j];
			if (answer[k]++ == 0)
				++answer_count;
		}

		request(count + 1);

		for (j = 1; j <= food_table[food][LENGTH]; ++j) {
			k = food_table[food][j];
			if (--answer[k] == 0)
				--answer_count;
		}
	}
}

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);
		for (i = 0; i < N; ++i) {
			scanf("%s", buffer[i]);

			people_table[i][LENGTH] = 0;
			answer[i] = 0;
		}

		for (i = 0; i < M; ++i) {
			food_table[i][LENGTH] = 0;
			scanf("%d", &j);

			while (j-- > 0) {
				scanf("%s", buf);
				for (k = 0; k < N; ++k) {
					if (my_strcmp(buf, buffer[k])) {
						break;
					}
				}
				people_table[k][++people_table[k][LENGTH]] = i;
				food_table[i][++food_table[i][LENGTH]] = k;
			}
		}

		for (i = 0, j = 0; i < N; ++i) {
			if (people_table[i][LENGTH] < people_table[j][LENGTH])
				j = i;
		}

		ANSWER = INVALID;
		answer_count = 0;
		request(0);

		printf("%d\n", ANSWER);
	}

	return 0;
}

