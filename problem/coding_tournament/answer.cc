#include <stdio.h>
#include <queue>
#include <iostream>

#define MAX (1024)

using namespace std;

int main(void)
{
	int TC, tc, K;
	int answer, i, j, k;
	int push_queue, pop_queue;
	queue<int> q[2];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		cin >> K;
		K = (1 << K);
		for (answer = 0, push_queue = 0; K > 0; --K) {
			cin >> k;
			q[push_queue].push(k);
		}

		while (q[push_queue].size() > 1) {
			pop_queue = push_queue;
			push_queue = !push_queue;

			while (!q[pop_queue].empty()) {
				i = q[pop_queue].front();
				q[pop_queue].pop();
				j = q[pop_queue].front();
				q[pop_queue].pop();

				if (i < j) {
					answer += (j - i);
					q[push_queue].push(j);
				} else {
					answer += (i - j);
					q[push_queue].push(i);
				}
			}
		}

		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
