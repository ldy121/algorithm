#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		int N, S, sum, first, second, idx;

		queue<int> q;
		vector<int> vec;
		cin >> N >> S;

		first = second = -1;
		sum = 0;
		for (int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			vec.push_back(input);
			q.push(i);
			sum += input;

			if (first == -1) {
				while (sum > S) {
					int idx = q.front();
					q.pop();
					sum -= vec[idx];
				}
				if (sum == S) {
					first = q.front() + 1;
					second = i + 1;
				}
			}
		}

		if (first != -1) {
			cout << first << " " << second << endl;
		} else {
			cout << "-1" << endl;
		}

	}

	return 0;
}
