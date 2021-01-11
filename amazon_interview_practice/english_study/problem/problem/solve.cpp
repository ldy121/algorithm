#include <stdio.h>
#include <queue>
#include <iostream>

#pragma warning(disable : 4996)

#define MAX (200000)

static int day[MAX];

using namespace std;

int solve_cpp(void)
{
	int test_case, T;
	int n, p;
	int answer, available, period;

	queue<int> q;
	
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> p;
		cin >> day[0];

		available = p;
		answer = p + 1;
		q.push(0);

		for (int i = 1; i < n; ++i) {
			cin >> day[i];
			q.push(i);

			for (available -= (day[i] - day[i - 1] - 1); available < 0;) {
				int j = q.front();
				q.pop();
				available += (day[q.front()] - day[j] - 1);
			}
			period = (day[i] - day[q.front()] + 1) + available;
			if (period > answer) {
				answer = period;
			}
		}

		while (!q.empty()) {
			q.pop();
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}