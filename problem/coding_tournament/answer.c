#include <stdio.h>

#define MAX (1024)

int queue[2][MAX];

int main(void)
{
	int TC, tc, K;
	int answer, i, j, k;
	int push_queue, pop_queue, queue_index, queue_size;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d\n", &K);
		K = (1 << K);
		for (answer = 0, push_queue = 0, queue_index = 0; K > 0; --K) {
			scanf("%d", &queue[push_queue][queue_index++]);
		}
		for (queue_size = queue_index; queue_size > 1; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (k = 0; k < queue_size;) {
				i = queue[pop_queue][k++];
				j = queue[pop_queue][k++];

				if (i < j) {
					answer += (j - i);
					queue[push_queue][queue_index++] = j;
				} else {
					answer += (i - j);
					queue[push_queue][queue_index++] = i;
				}
			}
		}
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
