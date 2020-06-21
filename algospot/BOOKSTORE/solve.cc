#include <stdio.h>

#define MAX_BOOKSTORE	(100)
#define MAX_BOOK		(200)
#define MAX				(10000)

struct NODE {
	int price;
	int point;
};

void qsort(struct NODE nd[], int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (nd[i].point > nd[left].point) {
				++j;

				k = nd[i].price;
				nd[i].price = nd[j].price;
				nd[j].price = k;

				k = nd[i].point;
				nd[i].point = nd[j].point;
				nd[j].point = k;
			}
		}

		k = nd[left].price;
		nd[left].price = nd[j].price;
		nd[j].price = k;

		k = nd[left].point;
		nd[left].point = nd[j].point;
		nd[j].point = k;


		qsort(nd, left, j - 1);
		qsort(nd, j + 1, right);
	}
}


struct NODE node[MAX_BOOKSTORE + 1][MAX_BOOK + 1];
int N, M;

int main(void)
{
	int tc, T;
	int i, j;
	int price, point;
	int answer;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &M);

		for (i = 0; i < N; ++i) {
			for (j = 0; j < M; ++j) {
				scanf("%d %d", &node[j][i].price, &node[j][i].point);

			}
		}

		answer = MAX * MAX_BOOK;
		for (i = 0; i < M; ++i) {
			qsort(node[i], 0, N - 1);

			point = 0;
			price = 0;
			for (j = 0; j < N; ++j) {
				if (point > 0) {
					if (node[i][j].price > point) {
						price += (node[i][j].price - point);
						point = 0;
					} else {
						point -= node[i][j].price;
					}
				} else {
					price += node[i][j].price;
				}

				point += node[i][j].point;
			}

			if (price < answer)
				answer = price;
		}

		printf("%d\n", answer);
	}

	return 0;
}
