#include <stdio.h>

#define MAX 		(100)
#define MAX_WEIGHT	(1000)
#define TRUE 		(1)
#define FALSE 		(0)

struct NODE {
	char name[21];
	int area;
	int want;
};

struct ANSWER {
	int sum;
	int buffer[MAX + 1];
	int buffer_size;
};

struct ANSWER answer[MAX_WEIGHT + 1];
struct ANSWER backup[MAX_WEIGHT + 1];
struct NODE item[MAX + 1];
unsigned char check[MAX_WEIGHT + 1];

int N, W;

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &W);
		for (i = 0; i <= W; ++i) {
			answer[i].buffer_size = 0;
			answer[i].sum = 0;
		}

		for (k = 0; k < N; ++k) {
			scanf("%s %d %d\n", item[k].name, &item[k].area, &item[k].want);

			for (i = 0; i <= W; ++i) {
				check[i] = FALSE;

				for (j = 0; j < answer[i].buffer_size; ++j) {
					backup[i].buffer[j] = answer[i].buffer[j];
				}
				backup[i].buffer_size = answer[i].buffer_size;
				backup[i].sum = answer[i].sum;
			}

			for (i = 0; (i + item[k].area) <= W; ++i) {
				if (backup[i + item[k].area].sum < (backup[i].sum + item[k].want)) {

					answer[i + item[k].area].sum = backup[i].sum + item[k].want;
					for (j = 0; j < backup[i].buffer_size; ++j)
						answer[i + item[k].area].buffer[j] = backup[i].buffer[j];

					answer[i + item[k].area].buffer[j] = k;
					answer[i + item[k].area].buffer_size = backup[i].buffer_size + 1;
				}
			}
		}

		j = k = 0;
		for (i = 0; i <= W; ++i) {
			if (k < answer[i].sum) {
				k = answer[i].sum;
				j = i;
			}
		}

		printf("%d %d\n", answer[j].sum, answer[j].buffer_size);
		for (i = 0; i < answer[j].buffer_size; ++i) {
			printf("%s\n", item[answer[j].buffer[i]].name);
		}
	}

	return 0;
}
