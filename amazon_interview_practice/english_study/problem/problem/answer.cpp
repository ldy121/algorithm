#include <stdio.h>

#pragma warning(disable : 4996)

#define MAX (200000)

int day[MAX];
int queue[MAX];
int queue_size;
int queue_index;

void queue_push(int index)
{
	queue[queue_size++] = index;
}

int queue_front(void)
{
	return queue[queue_index];
}

void queue_pop(void)
{
	++queue_index;
}

int main(void)
{
	int test_case, T;
	int n, p;
	int answer, available, period;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d\n", &n, &p);
		scanf("%d", &day[0]);

		queue_index = queue_size = 0;

		available = p;
		answer = p + 1;
		queue_push(0);

		for (int i = 1; i < n; ++i) {
			scanf("%d", &day[i]);
			queue_push(i);

			for (available -= (day[i] - day[i - 1] - 1); available < 0;) {
				int j = queue_front();
				queue_pop();
				available += (day[queue_front()] - day[j] - 1);
			}
			period = (day[i] - day[queue_front()] + 1) + available;
			if (period > answer) {
				answer = period;
			}
		}


		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}