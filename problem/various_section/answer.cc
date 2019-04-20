#include <iostream>
#include <queue>
#include <stdio.h>

#define MAX (100000)

using namespace std;

int main(void)
{
	int T, K, N, TC;
	int i, j, k, num;
	int answer;
	int map[MAX + 1];
	queue<int> q;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d", &N, &K);
		for (i = 0; i <= K; ++i) {
			map[i] = 0;
		}

		q.empty();
		for (answer = k = i = j = 0; j < N; ++j) {
			cin >> num;
			q.push(num);

			if (map[num] == 0) {
				++k;
			}
			++map[num];
			while (k == K) {
				answer += (N - j);
				if (map[q.front()] == 1) {
					--k;
				}
				--map[q.front()];
				q.pop();
			}
		}
		cout << "#" << T << " " << answer << endl;
	}
}

