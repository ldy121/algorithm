#include <stdio.h>

#define MAX	(2000)
#define invalid	(2000000000)

struct MATERIAL {
	int c_index;
	int r_count;
	int weight;
};

int N, R;
int C[MAX];
struct MATERIAL material[MAX];

int main(void)
{
	int TC, tc;
	int i, j, k, tmp;
	int num_material;
	int answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d %d\n", &N, &R);
		for (i = 0; i < N; ++i) {
			scanf("%d", &C[i]);
			material[i].c_index = i;
			material[i].r_count = 0;
			material[i].weight = C[i];
		}

		for (i = 0; i < N; ++i) {
			for (j = i + 1, k = 1; j != i; j = (j + 1) % N, ++k) {
				if ((C[i] + (k * R) < material[j].weight) ||
				    ((C[i] + (k * R) == material[j].weight) && 
				     (k > material[j].r_count))) {
					material[j].weight  = C[i] + (k * R);
					material[j].c_index = i;
					material[j].r_count = k;
				}
			}
		}

		for (i = 0, answer = 0, j = 0; i < N; ++i) {
			answer += C[material[i].c_index];
			if (j < material[i].r_count)
				j = material[i].r_count;
		}

		answer += (j * R);

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
